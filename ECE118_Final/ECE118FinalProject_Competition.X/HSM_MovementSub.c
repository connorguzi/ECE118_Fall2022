/*
 * File: HSM_MovementSub.c
 */


/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/
#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM_Robot.h"
#include "HSM_MovementSub.h"
#include "StepperDriver.h"
#include "ping.h"
/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/

typedef enum {
    InitPSubState,
    FindBeacon,
    StopRead,
    DrivingForward,
    DrivingBackward,
    GoForward,
} MovementSubHSMState_t;

static const char *StateNames[] = {
	"InitPSubState",
	"FindBeacon",
	"StopRead",
	"DrivingForward",
	"DrivingBackward",
	"GoForward",
};

/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/
/* You will need MyPriority and the state variable; you may need others as well.
 * The type of state variable should match that of enum in header file. */

static MovementSubHSMState_t CurrentState = InitPSubState; // <- change name to match ENUM
static uint8_t MyPriority;
//extern uint8_t Bumped;
extern uint8_t Bumped;
static uint8_t FoundBeacon = FALSE;
extern uint8_t Adjust;
static uint16_t RearCount;
static uint16_t RearAvg;
static uint16_t RearVal[VALUES_ARRAY_SIZE];
extern uint16_t ForDistTraveled; // keep track of distance traveled
extern TurnDirection TurnDir;
/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

uint8_t InitMovementSubHSM(void){
    ES_Event returnEvent;
//    printf("InitMovementSubHSM\r\n");

    CurrentState = InitPSubState;
    returnEvent = RunMovementSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

ES_Event RunMovementSubHSM(ES_Event ThisEvent){
    uint8_t makeTransition = FALSE; // use to flag transition
    MovementSubHSMState_t nextState; // <- change type to correct enum
    int i;
//    printf("RunMovementSubHSM\r\n");
//    printf("CurrentState=%d\r\n", CurrentState);


    ES_Tattle(); // trace call stack

    switch (CurrentState) {
    case InitPSubState: // If current state is initial Psedudo State
        if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
        {
            // this is where you would put any actions associated with the
            // transition from the initial pseudo-state into the actual
            // initial state

            // now put the machine into the actual initial state
            nextState = FindBeacon;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
//            ThisEvent.EventType = INTO_MOVEMENT;
        }
        break;

    case FindBeacon: // in the first state, replace this with correct names
//        printf("FindBeacon (Movement)\r\n");       
        switch (ThisEvent.EventType) {
            case ES_ENTRY:
                ES_Timer_InitTimer(BEACON_TIMER, BEACON_TIME);
//                printf("FindBeacon ES_Entry\r\n");
                StepperSpin();                
                break;
//            case INTO_MOVEMENT:
//                StepperSpin();
//                break;
            case BEACON_DETECTED:
//                printf("CASE BEACON_DETECTED\n\r");
                if(!FoundBeacon){
                    setEnableHigh();
                    StepperStop();
    //                nextState = StopRead;
    //                makeTransition = TRUE;
    //                ThisEvent.EventType = ES_NO_EVENT;
                    if(Adjust){
                        TurnRight(6);
                        Adjust = FALSE;
                    }
                    ES_Timer_StopTimer(BEACON_TIMER);
                    ES_Timer_InitTimer(MOVEMENT_TIMER, PING_DELAY);
                    FoundBeacon = TRUE;
                }
                break;
            case ES_TIMEOUT:
                if(ThisEvent.EventParam == MOVEMENT_TIMER){
                    printf("CASE ES_TIMEOUT\n\r");    
    //                if(ForDistTraveled != 0){
    //                    nextState = DrivingForward;
    //                    makeTransition = TRUE;
    //                    ThisEvent.EventType = ES_NO_EVENT;
    //                }
    //                else{
                    FoundBeacon = FALSE;
                    nextState = StopRead;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                       }
                else if(ThisEvent.EventParam == BEACON_TIMER){
                    nextState = GoForward;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }  
                break;
            case ES_NO_EVENT:
            default: // all unhandled events pass the event back up to the next level
                break;
        }
        break;
        
    case GoForward:
        switch (ThisEvent.EventType) {
            case ES_ENTRY:
                driveInches(90);
                break;
                
            case FRONT_BUMPER_TRIPPED:
                driveInchesBackward(2);
                break;
            case STOPPED_STEPPING:
                StepperStop();
                setEnableHigh();            
                Adjust = TRUE;
                nextState = FindBeacon;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                Bumped = TRUE;
                break;
        }
        break;
            
    case StopRead:
//        printf("StopRead (Movement)\r\n");        
        switch(ThisEvent.EventType){
        case ES_ENTRY:
            setEnableHigh();
            RearCount = 0;
            break;
        case REAR_SENSOR_UPDATED:
//            printf("Sensor Updated\r\n");
            if(ThisEvent.EventParam != 100){
//                printf("got here\r\n");
//                if(abs(RearVal[RearCount] - ThisEvent.EventParam) < MAX_DEVIATION){
                    RearVal[RearCount] = ThisEvent.EventParam;
                    RearCount++;
//                }
            }            
            if(RearCount >= ARR_MAX_SIZE){
                RearAvg = getAverage(RearVal, RearCount);
//                printValues (RearVal, RearCount);
//                    printf("Average = %d\r\n", RearAvg);
                RearCount = 0;
                nextState = DrivingForward;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;
            case ES_NO_EVENT:
            default: // all unhandled events pass the event back up to the next level
                break;                
        }
        break;
        
    case DrivingForward:
//        printf("DrivingForward (Movement)\r\n");        
        switch(ThisEvent.EventType){
        case ES_ENTRY:
            if(!Bumped){
                if(RearAvg <= MAX_AVG_DISTANCE){
                    driveInches(MAX_AVG_DISTANCE - RearAvg);
                    ForDistTraveled = MAX_AVG_DISTANCE - RearAvg - BACKUP_DISTANCE;
                    printf("Measured Forward: %d\r\n", ForDistTraveled);
                }
                else {
                    driveInches(MAX_AVG_DISTANCE);
                    ForDistTraveled = MAX_AVG_DISTANCE - BACKUP_DISTANCE;
                    printf("Not Measured Forward: %d\r\n", ForDistTraveled);
                }
            }
            else{
                driveInches(MAX_AVG_DISTANCE - RearAvg);
//                ForDistTraveled = MAX_AVG_DISTANCE - RearAvg + RELOAD_ZONE_WIDTH;
//                Bumped = FALSE;
            }
            break;
        case FRONT_BUMPER_TRIPPED:        
            ForDistTraveled -= (Stepper_GetRemainingSteps()/(STEPS_PER_10/10));
            StepperStop();
            setEnableHigh();            
            Adjust = TRUE;
            nextState = FindBeacon;
            makeTransition = TRUE;
            ThisEvent.EventType = OBSTACLE_DETECTED;
            Bumped = TRUE;
            break;                
        case STOPPED_STEPPING:
            ES_Timer_InitTimer(MOVEMENT_TIMER, STEPPER_DELAY);
            break;
        case ES_TIMEOUT:                
            nextState = DrivingBackward;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
            break;    
        case ES_NO_EVENT:
        default: // all unhandled events pass the event back up to the next level
            break;
        }
        break;
                
    case DrivingBackward:
//        printf("DrivingBackward (Movement)\r\n");                
        switch(ThisEvent.EventType){
        case ES_ENTRY:
            driveInchesBackward(BACKUP_DISTANCE);
            break;
        case STOPPED_STEPPING:
            ES_Timer_InitTimer(MOVEMENT_TIMER, STEPPER_DELAY);
            break;
        case ES_TIMEOUT:                
            nextState = FindBeacon;
            makeTransition = TRUE;
            ThisEvent.EventType = DISTANCE_MOVED;
            break;        
        case ES_NO_EVENT:
        default: // all unhandled events pass the event back up to the next level
            break;
        }
    default: // all unhandled states fall into here
        break;
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunMovementSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunMovementSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/

