/*
 * File: TemplateSubHSM.c
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 *
 * Template file to set up a Heirarchical State Machine to work with the Events and
 * Services Framework (ES_Framework) on the Uno32 for the CMPE-118/L class. Note that
 * this file will need to be modified to fit your exact needs, and most of the names
 * will have to be changed to match your code.
 *
 * There is for a substate machine. Make sure it has a unique name
 *
 * This is provided as an example and a good place to start.
 *
 * History
 * When           Who     What/Why
 * -------------- ---     --------
 * 09/13/13 15:17 ghe      added tattletail functionality and recursive calls
 * 01/15/12 11:12 jec      revisions for Gen2 framework
 * 11/07/11 11:26 jec      made the queue static
 * 10/30/11 17:59 jec      fixed references to CurrentEvent in RunTemplateSM()
 * 10/23/11 18:20 jec      began conversion from SMTemplate.c (02/20/07 rev)
 */


/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM_Robot.h"
#include "HSM_AvoidObstacleSub.h"
#include "StepperDriver.h"
#include "ping.h"
#include <stdio.h>
#include <math.h>

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/

typedef enum {
    InitPSubState,
    StopRead,
    Backup,
    TurnRightOrLeft,
    DrivingFoward,
    BackupAgain,
} AvoidObstacleSubHSMState_t;

static const char *StateNames[] = {
	"InitPSubState",
	"StopRead",
	"Backup",
	"TurnRightOrLeft",
	"DrivingFoward",
	"BackupAgain",
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

static AvoidObstacleSubHSMState_t CurrentState = InitPSubState; // <- change name to match ENUM
static uint8_t MyPriority;

static uint16_t LeftCount;
static uint16_t LeftAvg;
static uint16_t LeftVal[VALUES_ARRAY_SIZE];
static uint16_t RightCount;
static uint16_t RightAvg;
static uint16_t RightVal[VALUES_ARRAY_SIZE];
extern uint16_t ForDistTraveled;
extern TurnDirection TurnDir;

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitAvoidObstacleSubHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTemplateFSM function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitAvoidObstacleSubHSM(void)
{
    ES_Event returnEvent;

    CurrentState = InitPSubState;
    returnEvent = RunAvoidObstacleSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @Function RunAvoidObstacleSubHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the heirarchical state
 *        machine, as this is called any time a new event is passed to the event
 *        queue. This function will be called recursively to implement the correct
 *        order for a state transition to be: exit current state -> enter next state
 *        using the ES_EXIT and ES_ENTRY events.
 * @note Remember to rename to something appropriate.
 *       The lower level state machines are run first, to see if the event is dealt
 *       with there rather than at the current level. ES_EXIT and ES_ENTRY events are
 *       not consumed as these need to pass pack to the higher level state machine.
 * @author J. Edward Carryer, 2011.10.23 19:25
 * @author Gabriel H Elkaim, 2011.10.23 19:25 */
ES_Event RunAvoidObstacleSubHSM(ES_Event ThisEvent)
{
    uint8_t makeTransition = FALSE; // use to flag transition
    AvoidObstacleSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
    case InitPSubState: // If current state is initial Psedudo State
        if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
        {
            // this is where you would put any actions associated with the
            // transition from the initial pseudo-state into the actual
            // initial state

            // now put the machine into the actual initial state
            nextState = Backup;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
        }
        break;

    case StopRead: // in the first state, replace this with correct names
//        printf("AvoidObstacle StopRead\r\n");
        switch (ThisEvent.EventType) {
        case ES_ENTRY:
//            setEnableHigh();
            LeftCount = 0;
            RightCount = 0;
            break;
        case LEFT_SENSOR_UPDATED:
            if(ThisEvent.EventParam != 100){
//                if(abs(LeftVal[LeftCount] - ThisEvent.EventParam) < MAX_DEVIATION){
                    LeftVal[LeftCount] = ThisEvent.EventParam;
                    LeftCount++;
//                }
            }
            if((LeftCount >= ARR_MAX_SIZE) && (RightCount >= ARR_MAX_SIZE)){
                LeftAvg = getAverage(LeftVal, LeftCount);
                RightAvg = getAverage(RightVal, RightCount);                
//                printValues (LeftVal, LeftCount);
//                printValues (RightVal, RightCount);
//                printf("Left Average = %d\r\n", LeftAvg);
//                printf("Right Average = %d\r\n", RightAvg);
                LeftCount = 0;
                RightCount = 0;
                nextState = TurnRightOrLeft;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;
        case RIGHT_SENSOR_UPDATED:
            if(ThisEvent.EventParam != 100){
//                if(abs(RightVal[RightCount] - ThisEvent.EventParam) < MAX_DEVIATION){
                    RightVal[RightCount] = ThisEvent.EventParam;
                    RightCount++;
//                }
            }
            break;
        case ES_NO_EVENT:
        default: // all unhandled events pass the event back up to the next level
            break;                
        }
        break;
        
    case Backup:
//        printf("Backup (Avoid Obstacle)\r\n");                
        switch(ThisEvent.EventType){
        case ES_ENTRY:
            driveInchesBackward(4);
            break;
        case STOPPED_STEPPING:
            ES_Timer_InitTimer(ROBOT_TIMER, STEPPER_DELAY);
            break;
        case ES_TIMEOUT:                
            nextState = StopRead;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
            break;        
        case ES_NO_EVENT:
        default: // all unhandled events pass the event back up to the next level
            break;
        }
        break;
        
    case TurnRightOrLeft: 
//        printf("TurnRightOrLeft (Avoid Obstacle)\n\r");
        switch (ThisEvent.EventType) {
        case ES_ENTRY:
            if(LeftAvg > RightAvg){
                TurnLeft(80); //90 degree turn
                TurnDir = Left;
            }
            else{
                TurnRight(80);
                TurnDir = Right;
            }
            break;
        case STOPPED_STEPPING:
            ES_Timer_InitTimer(ROBOT_TIMER, STEPPER_DELAY);
            break;
        case ES_TIMEOUT:                
            nextState = DrivingFoward;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
            break;        
        case ES_NO_EVENT:
        default: // all unhandled events pass the event back up to the next level
            break;
        }
        break;                

    case DrivingFoward:                
//        printf("DrivingForward (Avoid Obstacle)\n\r");
        switch (ThisEvent.EventType) {
        case ES_ENTRY:
            driveInches(100); //continue driving 100 inches until bumper hit
            break;
        case FRONT_BUMPER_TRIPPED:
            StepperStop();
            nextState = BackupAgain;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;            
            break;
        case ES_NO_EVENT:
        default: // all unhandled events pass the event back up to the next level
            break;
        }
        break;                

    case BackupAgain:             
//        printf("BackupAgain (Avoid Obstacle)\n\r");
        switch (ThisEvent.EventType) {
        case ES_ENTRY:
            driveInchesBackward(2);
            break;               
        case STOPPED_STEPPING:
            ES_Timer_InitTimer(ROBOT_TIMER, STEPPER_DELAY);
            break;
        case ES_TIMEOUT:                
            nextState = Backup;
            makeTransition = TRUE;
            ThisEvent.EventType = OBSTACLE_AVOIDED;
            break;                    
        case ES_NO_EVENT:
        default: // all unhandled events pass the event back up to the next level
            break;
        }
        break;                
        
    default: // all unhandled states fall into here
        break;
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunAvoidObstacleSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunAvoidObstacleSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/

