/*
 * File: BumperService.h
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "BOARD.h"
#include "AD.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "Service_Bumper.h"
#include <stdio.h>
#include <xc.h>
#include <sys/attribs.h>


/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define TIMER_BUMPER_TICKS 500
#define BUFFER_SIZE 10
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

static uint8_t MyPriority;

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function ReadFrontLeftBumper(void)
 * @param None.
 * @return BUMPER_TRIPPED or BUMPER_NOT_TRIPPED
 * @brief  Returns the state of the front left bumper
 * @author Max Dunne, 2012.01.06 */
unsigned char ReadFrontBumpers(void){
    return !FRONT_BUMPERS;
}

uint8_t InitBumperService(uint8_t Priority){
    ES_Event ThisEvent;
    MyPriority = Priority;
    // in here you write your initialization code
    // this includes all hardware and software initialization
    // that needs to occur.
    FRONT_BUMPERS = 0;
    TRIS_FRONT_BUMPERS = 1; // input

    // post the initial transition event
    ThisEvent.EventType = ES_INIT;
    if (ES_PostToService(MyPriority, ThisEvent) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

uint8_t PostBumperService(ES_Event ThisEvent){
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function RunBumperService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the service,
 *        as this is called any time a new event is passed to the event queue. 
 * @note Remember to rename to something appropriate.
 *       Returns ES_NO_EVENT if the event have been "consumed." 
 * @author J. Edward Carryer, 2011.10.23 19:25 */
ES_Event RunBumperService(ES_Event ThisEvent){
    ES_Event ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

    /********************************************
     in here you write your service code
     *******************************************/
    static ES_EventTyp_t lastEvent = BUMPER_NOT_TRIPPED;
    ES_EventTyp_t curEvent;
    static unsigned char bumperArray[BUFFER_SIZE] = {0}; // To keep the past ten switch readings
    static unsigned char currentArrayPos = 0; // To track the current buffer position to fill the new data

    switch (ThisEvent.EventType) {
    case ES_INIT:
        // No hardware initialization or single time setups, those
        // go in the init function above.
        //
        // This section is used to reset service for some reason
        break;
    case ES_TIMERACTIVE:
    case ES_TIMERSTOPPED:
        break;
    case ES_TIMEOUT:
        // Reset timer
        ES_Timer_InitTimer(BUMPER_SERVICE_TIMER, TIMER_BUMPER_TICKS);
        
        // Fetch new switch data and store into the buffer
        bumperArray[currentArrayPos] = ReadFrontBumpers();
        // Increment buffer position for next iteration, roll back if it reaches end
        if (currentArrayPos < BUFFER_SIZE - 1) {
            currentArrayPos++;
        } else {
            currentArrayPos = 0;
        }
        // Check if the past ten readings are identical, meaning switch states are stabled
        unsigned char allSame = TRUE;
        for (int i = 0; i < BUFFER_SIZE - 1; i++) {
            if (bumperArray[i] != bumperArray[BUFFER_SIZE - 1]) {
                allSame = FALSE;
            }
        }
        unsigned char currentState = bumperArray[0];        
        // If switch stabled, update current bumper event. If not, keep using the last event
        if (allSame == TRUE) {
            curEvent = BUMPER_TRIPPED;
        } else {
            curEvent = lastEvent;
        }
        if (curEvent != lastEvent) { // check for change from last time
            ReturnEvent.EventType = curEvent;
            ReturnEvent.EventParam = currentState;
            lastEvent = curEvent; // update history
            PostBumperService(ReturnEvent);
        }
        break;
    }

    return ReturnEvent;
}

/*******************************************************************************
 * PRIVATE FUNCTIONs                                                           *
 ******************************************************************************/

