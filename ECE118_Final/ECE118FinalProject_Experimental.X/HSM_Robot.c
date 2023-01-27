/*
 * File: HSM_Robot.c
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/
#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM_Robot.h"
 //#include all sub state machines called
#include "HSM_MovementSub.h"
#include "HSM_LaunchingSub.h"
#include "HSM_AvoidObstacleSub.h"
#include "HSM_ReloadingSub.h"

/*******************************************************************************
 * PRIVATE #DEFINES                                                            *
 ******************************************************************************/
//Include any defines you need to do

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/



typedef enum {
    InitPState,
    Movement,
    AvoidObstacle,
    Launching,
    Reloading,
} RobotHSMState_t;

static const char *StateNames[] = {
	"InitPState",
	"Movement",
	"AvoidObstacle",
	"Launching",
	"Reloading",
};

/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine
   Example: char RunAway(uint_8 seconds);*/
/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/
/* You will need MyPriority and the state variable; you may need others as well.
 * The type of state variable should match that of enum in header file. */

static RobotHSMState_t CurrentState = InitPState; // <- change enum name to match ENUM
static uint8_t MyPriority;
uint8_t Bumped = FALSE;
uint8_t Adjust = TRUE;
uint16_t ForDistTraveled = 0; // keep track of distance traveled
TurnDirection TurnDir = None;
/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitRobotHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTemplateFSM function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitRobotHSM(uint8_t Priority)
{
    MyPriority = Priority;
    // put us into the Initial PseudoState
    CurrentState = InitPState;
    // post the initial transition event
    if (ES_PostToService(MyPriority, INIT_EVENT) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * @Function PostRobotHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Remember to rename to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t PostRobotHSM(ES_Event ThisEvent)
{
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function RunRobotHSM(ES_Event ThisEvent)
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
ES_Event RunRobotHSM(ES_Event ThisEvent)
{
    uint8_t makeTransition = FALSE; // use to flag transition
    RobotHSMState_t nextState; // <- change type to correct enum
    ES_Tattle(); // trace call stack
    
    switch (CurrentState) {
    case InitPState: // If current state is initial Pseudo State
        
        if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
        {
            // this is where you would put any actions associated with the
            // transition from the initial pseudo-state into the actual
            // initial state
            // Initialize all sub-state machines
            InitMovementSubHSM();
            InitLaunchingSubHSM();
            InitAvoidObstacleSubHSM();            
            InitReloadingSubHSM();
            // now put the machine into the actual initial state
            nextState = Movement;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
            ;
        }
        break;

    case Movement: // in the first state, replace this with correct names
        // run sub-state machine for this state
        //NOTE: the SubState Machine runs and responds to events before anything in the this
        //state machine does
//        printf("In Movement\r\n");
        ThisEvent = RunMovementSubHSM(ThisEvent);
        switch (ThisEvent.EventType) {
        case ES_EXIT:
            InitMovementSubHSM();
            StepperStop();
            setEnableHigh();
            break;
        case BEACON_FOUND:
        case DISTANCE_MOVED: // complete Movement
            nextState = Launching;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
            break;
        case OBSTACLE_DETECTED:
            nextState = AvoidObstacle;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
            break;
        case ES_NO_EVENT:

        default:
            break;
        }
        break;

    case AvoidObstacle:
//        printf("In AvoidObstacle\r\n");
        ThisEvent = RunAvoidObstacleSubHSM(ThisEvent);
        switch (ThisEvent.EventType) {
        case ES_EXIT:
            InitAvoidObstacleSubHSM();
            break;
        case OBSTACLE_AVOIDED: // obstacle avoided, moving onto launch
            nextState = Movement;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
            break;
        case ES_NO_EVENT:
            
        default:
            break;
        }
        break;        
        
    case Launching:
//        printf("In Launching\r\n");
        ThisEvent = RunLaunchingSubHSM(ThisEvent);
        switch (ThisEvent.EventType) {
        case ES_EXIT:
            InitLaunchingSubHSM();
            break;
        case BALLS_LAUNCHED: // finished shooting
            nextState = Reloading;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
            break;
        case ES_NO_EVENT:
            
        default:
            break;
        }
        break;
                
    case Reloading:
//        printf("In Reloading\r\n");

//        if(ThisEvent.EventType == ES_ENTRY){
//            InitReloadingSubHSM();
//        }
        ThisEvent = RunReloadingSubHSM(ThisEvent);
        switch (ThisEvent.EventType) {
        case ES_EXIT:
            InitReloadingSubHSM();
            break;
        case RELOADING_COMPLETE: // timer ended, reloading complete
            nextState = Movement;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
            break;
        case ES_NO_EVENT:
            
        default:
            break;
        }
        break;
        
    default: // all unhandled states fall into here
        break;
    } // end switch on Current State
    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunRobotHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunRobotHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/
