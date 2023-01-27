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
//#include "ES_Timers.h"
#include <stdio.h>
#include "IO_Ports.h"
#include "xc.h"
#include "ping.h"
#include "timers.h"
/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define US_TIMER_TICKS 1 // 1ms for the trigger to be high
#define INIT_DELAY 500 // was delay to get working with ES Framework
#define CYCLE_DELAY 90000 // 60 ms

#define F_PB (BOARD_GetPBClock())
#define TIMER_FREQUENCY 1000

static int trigger_time;
static int start_time;
static int end_time;


static PingState ping_state = ON1;
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


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/
char PING_Init(void) {
    // following block inits the timer
    T4CON = 0;
//    T4CONbits.TCKPS = 0b110;
    PR4 = F_PB / TIMER_FREQUENCY; 
    T4CONbits.ON = 1;
    IFS0bits.T4IF = 0;
    IPC4bits.T4IP = 3;
    IEC0bits.T4IE = 1;
    
    // following block inits change notify
    CNCONbits.ON = 1; // Change Notify On
    CNENbits.CNEN17 = 1; // Port X06
    CNPUEbits.CNPUE17 = 0; // Disable Pull up
    int temp = ECHO_BIT; // this is intentional to ensure a interrupt occur immediately upon enabling
    IFS1bits.CNIF = 0; // clear interrupt flag
    IPC6bits.CNIP = 1; //set priority
    IPC6bits.CNIS = 3; // and sub priority
    IEC1bits.CNIE = 1; // enable change notify
    // Hardware initialization
    TIMERS_Init();
    TRIGGER1_TRIS = OUTPUT;
    TRIGGER2_TRIS = OUTPUT;
    TRIGGER3_TRIS = OUTPUT;
    TRIGGER1 = HIGH;
    TRIGGER2 = LOW;
    TRIGGER3 = LOW;
    ECHO_TRIS = INPUT;
    }

float PING_GetDistance(void){
    if(PING_GetTimeofFlight() / 148.0 > 100){
        return 100.0;
    }
    return PING_GetTimeofFlight() / 148.0;
}

unsigned int PING_GetTimeofFlight(void){
    return end_time - start_time;
}

int GetTriggerTime(void){
    return TIMERS_GetTime()*1000 - trigger_time;
}

PingState GetState(void){
    return ping_state;
}
/*******************************************************************************
 * PRIVATE FUNCTIONs                                                           *
 ******************************************************************************/

// Meant to run at 1khz
static void RunPingFSM(void){
    switch(ping_state){
        // Immediately go from the trigger state to the wait state as 
            // by the time this function has been ran, the time to be on has passed
        case ON1:
            TRIGGER1 = HIGH;
            ping_state = WAIT1;
            trigger_time = TIMERS_GetTime() * 1000;
            break;
        case WAIT1:
            TRIGGER1 = LOW;
            if(TIMERS_GetTime()*1000 - trigger_time > CYCLE_DELAY){
                ping_state = ON2;
            }
            break;
        case ON2:
            TRIGGER2 = HIGH;
            ping_state = WAIT2;
            trigger_time = TIMERS_GetTime() * 1000;
            break;
        case WAIT2:
            TRIGGER2 = LOW;
            if(TIMERS_GetTime()*1000 - trigger_time > CYCLE_DELAY){
                ping_state = ON3;
            }
            break;
        case ON3:
            TRIGGER3 = HIGH;
            ping_state = WAIT3;
            trigger_time = TIMERS_GetTime() * 1000;
            break;
        case WAIT3:
            TRIGGER3 = LOW;
            if(TIMERS_GetTime()*1000 - trigger_time > CYCLE_DELAY){
                ping_state = ON4;
            }
            break;
        case ON4:
            TRIGGER4 = HIGH;
            ping_state = WAIT4;
            trigger_time = TIMERS_GetTime() * 1000;
            break;
        case WAIT4:
            TRIGGER4 = LOW;
            if(TIMERS_GetTime()*1000 - trigger_time > CYCLE_DELAY){
                ping_state = ON1;
            }
            break;
    }
}

void __ISR(_CHANGE_NOTICE_VECTOR) ChangeNotice_Handler(void) {
    static char readPort = 0;
//    printf("%d\r\n", readPort);
    readPort = ECHO_BIT; // this read is required to make the interrupt work
    IFS1bits.CNIF = 0; 
    //Anything else that needs to occur goes here
    if(readPort){
        start_time = (TIMERS_GetTime() * 1000) + (TMR5/TICKS_PER_MICRO);
    }
    else{
        end_time = (TIMERS_GetTime() * 1000) + (TMR5/TICKS_PER_MICRO);
    }
    
}

void __ISR(_TIMER_4_VECTOR) Timer4IntHandler(void) {
    IFS0bits.T4IF = 0;
    RunPingFSM();
//    printf("%d\r\n", TIMERS_GetTime());
    //Anything else that needs to occur goes here
//    printf("%d\r\n", TIMERS_GetTime()*1000- start_time);
//    if(ping_state==TRIGGER1){
//        trigger_time = TIMERS_GetTime() * 1000;
//        ping_state=WAIT;
//        TRIGGER1_LAT = LOW;
//    }
//    else{
//        // If the time elapsed from the trigger is greater than 60ms, send a new trigger
//        if(((TIMERS_GetTime()*1000) - trigger_time) > CYCLE_DELAY){
//            ping_state=TRIGGER;
//            TRIGGER1_LAT = HIGH;
//        }
////        else{
////            TRIGGER_LAT = LOW;
////
////        }
//    }
}