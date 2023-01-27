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
#include "HSM_ReloadingSub.h"
#include "HSM_AvoidObstacleSub.h"
#include "HSM_MovementSub.h"
#include "StepperDriver.h"
#include "ES_Configure_Beacon.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
typedef enum {
    InitPSubState,
    Turning,
    Backup,
    Wait,
    Reloading,
} ReloadingSubHSMState_t;

static const char *StateNames[] = {
	"InitPSubState",
	"Turning",
	"Backup",
	"Wait",
	"Reloading",
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

static ReloadingSubHSMState_t CurrentState = InitPSubState; // <- change name to match ENUM
static uint8_t MyPriority;
extern uint16_t ForDistTraveled; // keep track of distance traveled
extern TurnDirection TurnDir;
extern uint8_t Bumped;
static BumperDirection Bumper = NoBumper;
/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitReloadingSubHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTemplateFSM function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitReloadingSubHSM(void)
{
    ES_Event returnEvent;

    CurrentState = InitPSubState;
    returnEvent = RunReloadingSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @Function RunReloadingSubHSM(ES_Event ThisEvent)
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
ES_Event RunReloadingSubHSM(ES_Event ThisEvent)
{
    uint8_t makeTransition = FALSE; // use to flag transition
    ReloadingSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
    case InitPSubState: // If current state is initial Psedudo State
        if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
        {
            // this is where you would put any actions associated with the
            // transition from the initial pseudo-state into the actual
            // initial state

            // now put the machine into the actual initial state
//            nextState= Turning;
//            makeTransition = TRUE;
            CurrentState= Turning;
            makeTransition = FALSE;
            ThisEvent.EventType = ES_NO_EVENT;
        }
        break;

        // Turn to correct before backing up. After handling obstacle avoidance, the robot will be facing the beacon at 
            // an angle that will make the robot back up into the wall. This attempts to correct for that
    case Turning:
        switch (ThisEvent.EventType){
            case ES_ENTRY:
                printf("Entering the Turn State\r\n");
                switch(TurnDir){
                    case Left:
                        TurnLeft(10);
                        printf("Turning Left\r\n");
                        TurnDir = None;
                        break;
                    case Right:
                        TurnRight(10);
                        printf("Turning Right\r\n");
                        TurnDir = None;
                        break;
                    case None:
                        nextState = Backup;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        TurnDir = None;

                        break;
                }
                break;
            case STOPPED_STEPPING:
                nextState = Backup;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
        }
        break;
        
        // Backup the amount of distance that the robot moved forward
            // CHANGING TO BACKUP UNTIL BOTH BUMPERS ARE HIT
    case Backup: 
//        printf("Backup (Reloading)\n\r");
        switch (ThisEvent.EventType) {
        case ES_ENTRY:
//            printf("ForDistTravled = %d \r\n",ForDistTraveled);
            if(!Bumped){
                driveInchesBackward(ForDistTraveled); // make global variable to record total inches driven forward (depending on bumper hit/not hit)
            }
            else{
                driveInchesBackward(60);
            }
            break;
        case STOPPED_STEPPING:           
            nextState = Reloading;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
            break;
            
        case REAR_LEFT_BUMPER_TRIPPED:
//            Bumper = Left;
//            nextState = Wait;
//            makeTransition = TRUE;
//            ThisEvent.EventType = ES_NO_EVENT;
//            break;
        case REAR_RIGHT_BUMPER_TRIPPED:
            driveInches(2);
//            Bumper = Right;
//            nextState = Wait;
//            makeTransition = TRUE;
//            ThisEvent.EventType = ES_NO_EVENT;
            break;
            
        case ES_EXIT:
            StepperStop();
            break;
        case ES_NO_EVENT:
        default: // all unhandled events pass the event back up to the next level
            break;
        }
        break;
       
    case Wait:
        switch(ThisEvent.EventType){
            case ES_ENTRY:
                ES_Timer_InitTimer(BUMPER_TIMER, BUMPER_DELAY);

                break;
            case REAR_BUMPERS_TRIPPED:
                printf("Stopping Backing up");
                driveInches(1);
                Bumper = Both_bumpers;
                ES_Timer_StopTimer(BUMPER_TIMER);
                
                break;
//            case REAR_LEFT_BUMPER_TRIPPED:
//                if(Bumper == Right){
//                    driveInches(1);
//                    Bumper = Both_bumpers;
//                    ES_Timer_StopTimer(BUMPER_TIMER);
//
//                }
//                break;
//            case REAR_RIGHT_BUMPER_TRIPPED:
//                if(Bumper == Left){
//                    driveInches(1);
//                    Bumper = Both_bumpers;
//                    ES_Timer_StopTimer(BUMPER_TIMER);
//
//                }
//                break;
            case ES_TIMEOUT:
                if(ThisEvent.EventParam == BUMPER_TIMER){
                    driveInches(1);
                    if(Bumper == Left){
                        TurnDir = Left;
                    }
                    else if (Bumper == Right){
                        TurnDir = Right;
                    }
                }
                break;
            case STOPPED_STEPPING:
                if(Bumper == Both_bumpers){
                    nextState = Wait;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
                else{
                    nextState = Turning;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
                break;
            default:
                break;
        }  
        break;
        
        // Wait for the balls to be reloaded
    case Reloading:
//        printf("Wait (Reloading)\n\r");        
        switch (ThisEvent.EventType) {
        case ES_ENTRY:
            StepperStop();
            Bumped = FALSE;
            ES_Timer_InitTimer(RELOAD_TIMER, RELOAD_DELAY);
            break;
        case ES_TIMEOUT:
            if(ThisEvent.EventParam == RELOAD_TIMER){
                nextState = Turning;
                makeTransition = TRUE;
                ThisEvent.EventType = RELOADING_COMPLETE;    
            }
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
        RunReloadingSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunReloadingSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/

