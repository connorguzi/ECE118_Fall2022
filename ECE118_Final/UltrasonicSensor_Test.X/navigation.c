/*
 * File: TemplateService.h
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 *
 * Template file to set up a simple service to work with the Events and Services
 * Framework (ES_Framework) on the Uno32 for the CMPE-118/L class. Note that this file
 * will need to be modified to fit your exact needs, and most of the names will have
 * to be changed to match your code.
 *
 * This is provided as an example and a good place to start.
 *
 * Created on 23/Oct/2011
 * Updated on 13/Nov/2013
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "BOARD.h"
#include "AD.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "EventChecker.h"
#include <stdio.h>
#include "IO_Ports.h"
#include "xc.h"
#include "navigation.h"
#include "StepperDriver.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define US_TIMER_TICKS 1 // 1ms for the trigger to be high
#define INIT_DELAY 500
#define CYCLE_DELAY 60
#define STEPRATE 3000
#define ARRAY_SIZE 1024
#define MAX_DISTANCE 110
/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */


/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                    *
 ******************************************************************************/
/* You will need MyPriority and maybe a state variable; you may need others
 * as well. */
typedef enum {
    DRIVE_FORWARD,
    TURN_RIGHT,
    OBSTACLE_RECENTER,
    TURN_LEFT,
    BIG_TURN_RIGHT,
    RECENTER,
} FSMState;

static const char *StateNames[] = {
    "DRIVE FORWARD",
	"TURN RIGHT",
    "OBSTACLE RECENTER",
    "TURN LEFT",
    "BIG TURN RIGHT",
    "RECENTER",
};
static FSMState CurrentState = DRIVE_FORWARD;
static uint8_t MyPriority;
static float rightValues[ARRAY_SIZE];
static int rightCount;
static float leftValues[ARRAY_SIZE];
static int leftCount;
/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitTemplateService(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTemplateService function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitNAVFSM(uint8_t Priority) {
    ES_Event ThisEvent;
    MyPriority = Priority;
    // Set trigger and echo pins appropriately
    // Set trigger pin high
    Stepper_SetRightRate(STEPRATE);
    Stepper_SetRate(STEPRATE);
    
    // post the initial transition event
    ThisEvent.EventType = ES_INIT;
    if (ES_PostToService(MyPriority, ThisEvent) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * @Function PostTemplateService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Remember to rename to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */

uint8_t PostNAVFSM(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function RunTemplateService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the service,
 *        as this is called any time a new event is passed to the event queue. 
 * @note Remember to rename to something appropriate.
 *       Returns ES_NO_EVENT if the event have been "consumed." 
 * @author J. Edward Carryer, 2011.10.23 19:25 */
ES_Event RunNAVFSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    FSMState nextState; 
    ES_Tattle();
    switch (CurrentState) {
    case DRIVE_FORWARD:
        // If there is an obstacle in front, start looking for gap
        switch(ThisEvent.EventType){
            case ES_ENTRY:
                DriveForward();
                break;
            case FRONT_SENSOR_UPDATED:
                if(ThisEvent.EventParam < 4){
                    nextState = TURN_RIGHT;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
                break;
        }
        break;
    case TURN_RIGHT: 
        switch(ThisEvent.EventType){
            // On entry, begin the turn and reset the arrays
            case ES_ENTRY:
                TurnRight(45);
                rightCount = 0;
                leftCount = 0;
                break;
            // Update the array of right values every time the ping sensor is updated
            case FRONT_SENSOR_UPDATED:
                // Sometimes the sensor will read an abnormaly large value, this throws it out.
                if (ThisEvent.EventParam < MAX_DISTANCE){
                    rightValues[rightCount] = ThisEvent.EventParam;
                }
                break;
            // Move to the re-center obstacle state
            case STOPPED_STEPPING:
                break;
            default:
                break;
        }
        break;
    case OBSTACLE_RECENTER:
        break;
    case TURN_LEFT:
        break;
   
    case RECENTER:
        break;
    default: // all unhandled states fall into here
        break;
    } // end switch on Current State
    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunNAVFSM(EXIT_EVENT);
        CurrentState = nextState;
        RunNAVFSM(ENTRY_EVENT);
    }
    ES_Tail();
    return ThisEvent;
}


//uint8_t EchoChange(void){
//    static uint8_t prevState = LOW;
//    ES_Event thisEvent;
//    uint8_t returnVal = FALSE;
//    if(ECHO_BIT == HIGH && prevState == LOW){
//        prevState = HIGH;
//        thisEvent.EventType = ECHO_HIGH;
//        thisEvent.EventParam = HIGH;
//        returnVal = TRUE;
//        PostUSFSM(thisEvent);
//    }
//    else if(ECHO_BIT == LOW && prevState ==HIGH){
//        prevState = LOW;
//        thisEvent.EventType = ECHO_LOW;
//        thisEvent.EventParam = LOW;
//        returnVal = TRUE;
//        PostUSFSM(thisEvent);
//    }
//    return returnVal;
//} 

/*******************************************************************************
 * PRIVATE FUNCTIONs                                                           *
 ******************************************************************************/

static float rightAverage(void){
    float sum = 0;
    int i;
    for(i=0; i<=rightCount; i++){
       sum += rightValues[i];
    }
    return sum / rightCount;
}

static float leftAverage(void){
    float sum = 0;
    int i;
    for(i=0; i<=leftCount; i++){
       sum += leftValues[i];
    }
    return sum / leftCount;
}