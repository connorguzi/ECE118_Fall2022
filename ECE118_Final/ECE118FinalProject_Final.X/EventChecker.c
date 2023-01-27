/*
 * File:   EventChecker.c
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "EventChecker.h"
#include "ES_Events.h"
#include "serial.h"
#include "BOARD.h"
#include "AD.h"
#include "HSM_Robot.h"
#include "ping.h"
#include "Bumpers.h"
#include <stdio.h>
/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define BEACON_HIGH_THRESHOLD 300
#define BEACON_LOW_THRESHOLD 200
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

//uint8_t CheckBeacon(void){
//    ES_Event thisEvent;
//    uint8_t returnVal = FALSE;
//    static uint8_t previous = FALSE;
//    int8_t current;
//    uint16_t beaconOutput = AD_ReadADPin(AD_PORTV3);
//    if (beaconOutput < BEACON_LOW_THRESHOLD)
//    {
//        current = TRUE;
//    }
//    else
//        current = FALSE;
//    
//    if(current == TRUE && previous == FALSE){
//        returnVal = TRUE;
//        thisEvent.EventType = BEACON_DETECTED;
//        PostRobotHSM(thisEvent);        
//        previous = TRUE;
//    }
//    else if(current == FALSE && previous == TRUE){
//        returnVal = TRUE;
//        thisEvent.EventType = BEACON_UNDETECTED;
//        PostRobotHSM(thisEvent);        
//        previous = FALSE;
//    }
//    return returnVal;
//}
uint8_t countOutput = 0;

uint8_t CheckBeacon(void) {
//    printf("Hello\r\n");
    static ES_EventTyp_t lastEvent = BEACON_UNDETECTED;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    uint16_t beaconOutput = AD_ReadADPin(AD_PORTV3); // read the output of the beacon detector
    if (beaconOutput < BEACON_LOW_THRESHOLD){
        countOutput++;
        if(countOutput >= 100){
//            printf("BEACON_DETECTED \r\n");
            curEvent = BEACON_DETECTED;
            countOutput = 0;
        }
        else 
            curEvent = BEACON_UNDETECTED;            
    }
    else {
        curEvent = BEACON_UNDETECTED;
        countOutput = 0;
    }
//    if (beaconOutput < BEACON_LOW_THRESHOLD) { // is beacon detected?
//        curEvent = BEACON_DETECTED;
//    } else if (beaconOutput > BEACON_HIGH_THRESHOLD){
//        curEvent = BEACON_UNDETECTED;
//    }
    if (curEvent != lastEvent) { // check for change from last time
        thisEvent.EventType = curEvent;
        thisEvent.EventParam = beaconOutput;
        PostRobotHSM(thisEvent);
        
        returnVal = TRUE;
        lastEvent = curEvent; // update history
    }
    return (returnVal);
}

uint8_t PingCheck(void){
    static uint8_t check1 = FALSE, check2 = FALSE, check3 = FALSE, check4 = FALSE;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    PingState sensor = GetState();
    uint16_t distance = PING_GetDistance();

     switch(sensor){
        case WAIT1:
            check2 = FALSE;
            if(!check1){
                thisEvent.EventType = FRONT_SENSOR_UPDATED;
                thisEvent.EventParam = distance;
                PostRobotHSM(thisEvent);
                returnVal = TRUE;
                check1 = TRUE;
            }
            break;
        case WAIT2:
            check3 = FALSE;
            if(!check2){
                thisEvent.EventType = LEFT_SENSOR_UPDATED;
                thisEvent.EventParam = distance;
//                printf("LEFT %d\r\n", distance);
                PostRobotHSM(thisEvent);
                returnVal = TRUE;
                check2 = TRUE;
            }
            break;
        case WAIT3:
            check4 = FALSE;
            if(!check3){
                thisEvent.EventType = REAR_SENSOR_UPDATED;
                thisEvent.EventParam = distance;
//                printf("REAR %d\r\n", distance);
                PostRobotHSM(thisEvent);
                returnVal = TRUE;
                check3 = TRUE;
            }
            break;
         case WAIT4:    
            check1 = FALSE;
            if(!check4){
                thisEvent.EventType = RIGHT_SENSOR_UPDATED;
                thisEvent.EventParam = distance;
//                printf("RIGHT %d\r\n", distance);
                PostRobotHSM(thisEvent);
                returnVal = TRUE;
                check4 = TRUE;
            }
        default:
            break;
        }
    return returnVal;
} 

uint8_t StepCheck(void){
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    static uint8_t previous = FALSE;
    int8_t current = Stepper_IsStepping();
    if(current == TRUE && previous == FALSE){
        returnVal = TRUE;
        thisEvent.EventType = STARTED_STEPPING;
        PostRobotHSM(thisEvent);        
        previous = TRUE;
    }
    else if(current == FALSE && previous == TRUE){
        returnVal = TRUE;
        printf("Stopped Stepping\r\n");
        thisEvent.EventType = STOPPED_STEPPING;
        PostRobotHSM(thisEvent);        
        previous = FALSE;
    }
    return returnVal;
}

uint8_t FrontBumperCheck(void){
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    static uint8_t previous = FALSE;
    uint8_t current = FrontBumper_Read();
    if(current==TRUE && previous==FALSE){
        thisEvent.EventType = FRONT_BUMPER_TRIPPED;
        printf("Front Bumper Tripped\r\n");
        returnVal = TRUE;
        PostRobotHSM(thisEvent);
    }
    else if(current==FALSE && previous==TRUE){
        thisEvent.EventType = FRONT_BUMPER_NOT_TRIPPED;
        returnVal = TRUE;
        PostRobotHSM(thisEvent);
    }
    previous = current;
    return returnVal;
}

uint8_t RearBumperCheck(void){
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    static uint8_t previousLeft = FALSE;
    uint8_t currentLeft = RearLeftBumper_Read();
    static uint8_t previousRight = FALSE;
    uint8_t currentRight = RearRightBumper_Read();
//    printf("%d\t%d\r\n", currentRight, currentLeft);    
    static uint8_t previousBoth = FALSE;
    
    uint8_t currentBoth = currentRight & currentLeft;
    if(currentBoth==TRUE && previousBoth==FALSE){
        thisEvent.EventType = REAR_BUMPERS_TRIPPED;
        printf("Both Rear Bumpers Tripped\r\n");
//        printf("%d\t%d\r\n", currentRight, currentLeft);
        returnVal = TRUE;
        PostRobotHSM(thisEvent);
    }
    
    else if(currentLeft==TRUE && previousLeft==FALSE){
        thisEvent.EventType = REAR_LEFT_BUMPER_TRIPPED;
        printf("Rear Left Bumper Tripped\r\n");
        returnVal = TRUE;
        PostRobotHSM(thisEvent);
    }
    
     else if(currentRight==TRUE && previousRight==FALSE){
        thisEvent.EventType = REAR_LEFT_BUMPER_TRIPPED;
        printf("Rear Right Bumper Tripped\r\n");
        returnVal = TRUE;
        PostRobotHSM(thisEvent);
    }
    previousRight = currentRight;
    previousLeft = currentLeft;
    previousBoth = currentBoth;
    return returnVal; 
}

uint8_t RearLeftBumperCheck(void){
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    static uint8_t previous = FALSE;
    uint8_t current = RearLeftBumper_Read();
    if(current==TRUE && previous==FALSE){
        thisEvent.EventType = REAR_LEFT_BUMPER_TRIPPED;
        printf("Rear Left Bumper Tripped\r\n");
        returnVal = TRUE;
        PostRobotHSM(thisEvent);
    }
    previous = current;
    return returnVal;
}

uint8_t RearRightBumperCheck(void){
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    static uint8_t previous = FALSE;
    uint8_t current = RearRightBumper_Read();
    if(current==TRUE && previous==FALSE){
        thisEvent.EventType = REAR_RIGHT_BUMPER_TRIPPED;
        printf("Rear Right Bumper Tripped\r\n");
        returnVal = TRUE;
        PostRobotHSM(thisEvent);
    }
    previous = current;
    return returnVal;
}

//uint8_t FrontBumperCheck(void){
//    static ES_EventTyp_t lastEvent = FRONT_BUMPER_NOT_TRIPPED;
//    ES_EventTyp_t curEvent;
//    ES_Event thisEvent;    
//    uint8_t returnVal = FALSE;
//    uint8_t bumperRead = FrontBumper_Read();
//    if(bumperRead == TRUE){
////        printf("FRONT_BUMPER_TRIPPED\r\n");
//        curEvent = FRONT_BUMPER_TRIPPED;
//    }
//    else{
////        printf("FRONT_BUMPER_NOT_TRIPPED\r\n");        
//        curEvent = FRONT_BUMPER_NOT_TRIPPED;
//    }
//    if (curEvent != lastEvent) { // check for change from last time
//        thisEvent.EventType = curEvent;
//        thisEvent.EventParam = bumperRead;
//        PostRobotHSM(thisEvent);
//        
//        returnVal = TRUE;
//        lastEvent = curEvent; // update history
//    }
//    return (returnVal);    
//}

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
    printf("\r\n Initializing AD");    
    AD_Init();
    AD_AddPins(AD_PORTV3);    
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