#include "BOARD.h"
#include "AD.h"
#include <stdio.h>
#include <stdlib.h>
#include "IO_Ports.h"
#include "xc.h"
#include "timers.h"
#include "ping.h"

int main(void){
    BOARD_Init();
    PING_Init();
    float distance = 0;
    uint8_t flag1 = FALSE, flag2 = FALSE, flag3 = FALSE, flag4 = FALSE;
    
    PingState sensor = GetState();
    printf("Beginning Ping Test\r\n");
//    TRIGGER_TRIS = OUTPUT;
//    TRIGGER_LAT = HIGH;
//    ECHO_TRIS = INPUT;
    while(1){
        distance = PING_GetDistance();
        sensor = GetState();
        
        switch(sensor){
            case WAIT1:
                flag2 = FALSE;
                if(!flag1){
                    printf("Sensor 1: %f\r\n", distance);
                    flag1 = TRUE;
                }
                break;
            case WAIT2:
                flag3 = FALSE;
                if(!flag2){
                    printf("Sensor 2: %f\r\n", distance);
                    flag2 = TRUE;
                }
                break;
            case WAIT3:
                flag4 = FALSE;
                if(!flag3){
                    printf("Sensor 3: %f\r\n", distance);
                    flag3 = TRUE;
                }
                break;
            case WAIT4:
                flag1 = FALSE;
                if(!flag4){
                    printf("Sensor 4: %f\r\n", distance);
                    flag4 = TRUE;
                }
                break;
                
            default:
                break;
        }
        
        
        
//        if(distance > 29010000){
//            printf("%d\t%d\r\n", distance, GetTriggerTime());
//        }
//        else{
//            printf("%d\r\n", distance);
//        }
        
//        PING_GetDistance();
    }
}