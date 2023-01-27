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
#include "ES_Timers.h"
#include "timers.h"
#include <stdio.h>
#include "IO_Ports.h"
#include "xc.h"
#include "ping.h"
//#include "timers.h"
/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define US_TIMER_TICKS 1 // 1ms for the trigger to be high
#define INIT_DELAY 500 // was delay to get working with ES Framework
#define CYCLE_DELAY 60000 // 60 ms

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
    ES_Timer_Init();
    TRIGGER1_TRIS = OUTPUT;
    TRIGGER2_TRIS = OUTPUT;
    TRIGGER3_TRIS = OUTPUT;
    TRIGGER4_TRIS = OUTPUT;
    TRIGGER1 = HIGH;
    TRIGGER2 = LOW;
    TRIGGER3 = LOW;
    TRIGGER4 = LOW;
    ECHO_TRIS = INPUT;
    }

//return inches
uint16_t PING_GetDistance(void){
    if((PING_GetTimeofFlight()/148 > 100) || (PING_GetTimeofFlight()/148 == 0)){
        return 100;
    }
    return PING_GetTimeofFlight()/148;
}

unsigned int PING_GetTimeofFlight(void){
    return end_time - start_time;
}

int GetTriggerTime(void){
    return ES_Timer_GetTime()*1000 - trigger_time;
}

PingState GetState(void){
    return ping_state;
}

void printValues (uint16_t *array, int length){
    int i;
    printf("[");
    for(i=0; i< length; i++){
        printf("%d, ",array[i]);
    }
    printf("]\r\n");
}

uint16_t getAverage(uint16_t *array, int length){
    int i;
    uint16_t average = 0;
    for(i = 0; i<length; i++){
        average += array[i];
    }
    return average/(length);
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
            trigger_time = ES_Timer_GetTime() * 1000;
            break;
        case WAIT1:
            TRIGGER1 = LOW;
            if(ES_Timer_GetTime()*1000 - trigger_time > CYCLE_DELAY){
                ping_state = ON2;
            }
            break;
        case ON2:
            TRIGGER2 = HIGH;
            ping_state = WAIT2;
            trigger_time = ES_Timer_GetTime() * 1000;
            break;
        case WAIT2:
            TRIGGER2 = LOW;
            if(ES_Timer_GetTime()*1000 - trigger_time > CYCLE_DELAY){
                ping_state = ON3;
            }
            break;
        case ON3:
            TRIGGER3 = HIGH;
            ping_state = WAIT3;
            trigger_time = ES_Timer_GetTime() * 1000;
            break;
        case WAIT3:
            TRIGGER3 = LOW;
            if(ES_Timer_GetTime()*1000 - trigger_time > CYCLE_DELAY){
                ping_state = ON4;
            }
            break;
        case ON4:
            TRIGGER4 = HIGH;
            ping_state = WAIT4;
            trigger_time = ES_Timer_GetTime() * 1000;
            break;
        case WAIT4:
            TRIGGER4 = LOW;
            if(ES_Timer_GetTime()*1000 - trigger_time > CYCLE_DELAY){
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
        start_time = (ES_Timer_GetTime() * 1000) + (TMR1/TICKS_PER_MICRO);
    }
    else{
        end_time = (ES_Timer_GetTime() * 1000) + (TMR1/TICKS_PER_MICRO);
    }
    
}

void __ISR(_TIMER_4_VECTOR) Timer4IntHandler(void) {
    IFS0bits.T4IF = 0;
    RunPingFSM();
    
}