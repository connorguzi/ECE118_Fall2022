/*
 * 
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "EventChecker.h"
#include "ES_Events.h"
#include "serial.h"
#include "AD.h"
#include "timers.h"
#include "navigation.h"
#include "ping.h"
#include "StepperDriver.h"
/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/

/*******************************************************************************
 * EVENTCHECKER_TEST SPECIFIC CODE                                                             *
 ******************************************************************************/

//#define EVENTCHECKER_TEST
#ifdef EVENTCHECKER_TEST
#include <stdio.h>
#define SaveEvent(x) do {eventName=__func__; storedEvent=x;} while (0)

static const char *eventName;
static ES_Event storedEvent;
#endif

/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this EventChecker. They should be functions
   relevant to the behavior of this particular event checker */

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                    *
 ******************************************************************************/

/* Any private module level variable that you might need for keeping track of
   events would be placed here. Private variables should be STATIC so that they
   are limited in scope to this module. */

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/
uint8_t PingCheck(void){
    static uint8_t check1 = FALSE, check2 = FALSE, check3 = FALSE, check4 = FALSE;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    PingState sensor = GetState();
    float distance = PING_GetDistance();
     switch(sensor){
        case WAIT1:
            check2 = FALSE;
            if(!check1){
                thisEvent.EventType = FRONT_SENSOR_UPDATED;
                thisEvent.EventParam = distance;
                PostNAVFSM(thisEvent);
                returnVal = TRUE;
                check1 = TRUE;
            }
            break;
        case WAIT2:
            check3 = FALSE;
            if(!check2){
                thisEvent.EventType = LEFT_SENSOR_UPDATED;
                thisEvent.EventParam = distance;
                PostNAVFSM(thisEvent);
                returnVal = TRUE;
                check2 = TRUE;
            }
            break;
        case WAIT3:
            check4 = FALSE;
            if(!check3){
                thisEvent.EventType = RIGHT_SENSOR_UPDATED;
                thisEvent.EventParam = distance;
                PostNAVFSM(thisEvent);
                returnVal = TRUE;
                check3 = TRUE;
            }
            break;
         case WAIT4:    
            check1 = FALSE;
            if(!check4){
                thisEvent.EventType = REAR_SENSOR_UPDATED;
                thisEvent.EventParam = distance;
                PostNAVFSM(thisEvent);
                returnVal = TRUE;
                check3 = TRUE;
            }
        default:
            break;
        }
    return returnVal;
} 

uint8_t StepCheck(void){
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    static previous = FALSE;
    int8_t current = Stepper_IsStepping();
    if(current == FALSE && previous == TRUE){
        returnVal = TRUE;
        thisEvent.EventType = STOPPED_STEPPING;
        PostNAVFSM(thisEvent);        
    }
    return returnVal;
}

/* 
 * The Test Harness for the event checkers is conditionally compiled using
 * the EVENTCHECKER_TEST macro (defined either in the file or at the project level).
 * No other main() can exist within the project.
 * 
 * It requires a valid ES_Configure.h file in the project with the correct events in 
 * the enum, and the correct list of event checkers in the EVENT_CHECK_LIST.
 * 
 * The test harness will run each of your event detectors identically to the way the
 * ES_Framework will call them, and if an event is detected it will print out the function
 * name, event, and event parameter. Use this to test your event checking code and
 * ensure that it is fully functional.
 * 
 * If you are locking up the output, most likely you are generating too many events.
 * Remember that events are detectable changes, not a state in itself.
 * 
 * Once you have fully tested your event checking code, you can leave it in its own
 * project and point to it from your other projects. If the EVENTCHECKER_TEST marco is
 * defined in the project, no changes are necessary for your event checkers to work
 * with your other projects.
 */
#ifdef EVENTCHECKER_TEST
#include <stdio.h>
static uint8_t(*EventList[])(void) = {EVENT_CHECK_LIST};

void PrintEvent(void);

void main(void) {
    BOARD_Init();
    /* user initialization code goes here */
    Roach_Init();
    // Do not alter anything below this line
    int i;

    printf("\r\nEvent checking test harness for %s", __FILE__);

    while (1) {
        if (IsTransmitEmpty()) {
            for (i = 0; i< sizeof (EventList) >> 2; i++) {
                if (EventList[i]() == TRUE) {
                    PrintEvent();
                    break;
                }

            }
        }
    }
}

void PrintEvent(void) {
    printf("\r\nFunc: %s\tEvent: %s\tParam: 0x%X", eventName,
            EventNames[storedEvent.EventType], storedEvent.EventParam);
}
#endif