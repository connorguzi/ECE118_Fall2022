#include "StepperDriver.h"
#include "BOARD.h"
#include <stdio.h> 
#include <xc.h>
#include "IO_Ports.h"

int main(void) {

    int32_t stepRate = 2000;
    
    int32_t numSteps = 9847;//98470xiaole
    int32_t numStepsR = 9847;
    printf("Beginning Stepper Test\r\n");
    BOARD_Init();
    Stepper_Init(); // Initializes the Stepper Module, sets up the stepper on PORTZ
//                    // Defaults to a stepping rate of MED_HZ_RATE (77Hz)
    Stepper_SetRate(stepRate);
    Stepper_SetRightRate(stepRate);
    DriveForward(1600 * 2.62);
//    Stepper_SetSteps(REVERSE, numSteps);
//    Stepper_SetRightSteps(FORWARD, numStepsR); 
//    Stepper_StartRightSteps();
//    Stepper_StartSteps();
//    
//    PORTZ04_TRIS = 0;
//    PORTZ08_TRIS = 0;
//    
//    PORTZ04_LAT = 0;
//    PORTZ08_LAT = 0;
    
//    DriveForward(1600);
//    StepperSpin();
//    StepperStop();
    while(1){
//        printf("%d\n", Stepper_GetRemainingSteps());
    };
            
//    while(1) {
//        if (!Stepper_IsStepping() && !Stepper_IsRightStepping()) {
//                Stepper_SetSteps(FORWARD, numSteps);
//                Stepper_StartSteps();                
//                Stepper_SetRightSteps(FORWARD, numStepsR);
//                Stepper_StartRightSteps();
//        }
//    }
/*
    while(1) {
        if (!Stepper_IsStepping() && !Stepper_IsRightStepping()) {        
            if (Stepper_GetDirection() == FORWARD)
            {
                Stepper_SetSteps(REVERSE, numSteps);
                Stepper_StartSteps();                
            }
            else if (Stepper_GetDirection() == REVERSE){
                Stepper_SetSteps(FORWARD, numStepsR);
                Stepper_StartSteps();
            }
            if (Stepper_GetRightDirection() == FORWARD)
            {
                Stepper_SetRightSteps(REVERSE, numSteps);
                Stepper_StartRightSteps();                
            }
            else if (Stepper_GetRightDirection() == REVERSE){
                Stepper_SetRightSteps(FORWARD, numStepsR);
                Stepper_StartRightSteps();
            }
        }
    }    */
}
