#include "BOARD.h"
#include "AD.h"
#include <stdio.h>
#include <stdlib.h>
#include "IO_Ports.h"
#include "xc.h"
#include "timers.h"

#define TRIGGER_TRIS PORTX03_TRIS
#define ECHO_TRIS PORTX06_TRIS
#define TRIGGER_LAT PORTX03_LAT
#define ECHO_BIT PORTX06_BIT
#define TICKS_PER_MICRO 40
#define TRIGGER PIN4
#define ECHO PIN3

#define F_PB (BOARD_GetPBClock())
#define TIMER_FREQUENCY 1000

float GetDistance(void){

    TRIGGER_LAT = 1;
    unsigned int trigger_time = (TIMERS_GetTime());
    // Wait for trigger time to be at least 10 micro seconds (lowest we can do is 1ms)
    while(TIMERS_GetTime() - trigger_time < 1 ){

    }
    TRIGGER_LAT = 0;
//     Wait for echo bit to go high
    while(!ECHO_BIT){

    }
    unsigned int echo_time = (TIMERS_GetTime() * 1000) + TMR5/TICKS_PER_MICRO;
    // Wait for echo bit to go low
    while(ECHO_BIT){
        
    }
    int micro = TMR5/TICKS_PER_MICRO;
    float on_time = (TIMERS_GetTime()*1000) - echo_time + micro;
//    float on_time = (TIMERS_GetTime()- echo_time)*1000  + micro;
    while(TIMERS_GetTime() - trigger_time < 60);
    // Return the distance
    return on_time / 148;
}

// Smallest resolution we can have is 1000 / 148 which is 6.8, but since we work with integers we can only do 6 inches resolution

int main(void){
    BOARD_Init();
    TIMERS_Init();
    printf("Beginning Ping Test\r\n");
    TRIGGER_TRIS = 0;
    ECHO_TRIS = 1;
//    IO_PortsSetPortInputs(PORTZ, ECHO);
//    IO_PortsSetPortOutputs(PORTZ, TRIGGER);
//    IO_PortsSetPortBits(PORTZ, 0);
    TRIGGER_LAT = 0;
//    PORTZ05_LAT = 1;
//    printf("%f\r\n", GetDistance());
//    TRIGGER_LAT = 1;
//    GetDistance();
    while(1){
//        printf("%d\r\n", ECHO_BIT);
//        GetDistance();
//        printf("%d\r\n", TIMERS_GetTime());
//        printf("%d\r\n", TMR5);
        printf("%f\r\n", GetDistance());
    }
}