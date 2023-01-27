#include <BOARD.h>
#include <xc.h>
#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "StepperDriver.h"
#include "ping.h"
#include "Bumpers.h"
#include "AD.h"

void main(void)
{
    ES_Return_t ErrorType;
    uint16_t stepRate = 1500;
    BOARD_Init();

    printf("Starting ES Framework Template\r\n");
    printf("using the 2nd Generation Events & Services Framework\r\n");

    // Your hardware initialization function calls go here
    AD_Init();
    AD_AddPins(AD_PORTV3);
    PING_Init();
    Bumper_Init();
    Stepper_Init();
    Stepper_SetRate(stepRate);
    Stepper_SetRightRate(stepRate);

    // now initialize the Events and Services Framework and start it running
    ErrorType = ES_Initialize();
    if (ErrorType == Success) {
        ErrorType = ES_Run();

    }
    //if we got to here, there was an error
    switch (ErrorType) {
    case FailedPointer:
        printf("Failed on NULL pointer");
        break;
    case FailedInit:
        printf("Failed Initialization");
        break;
    default:
        printf("Other Failure: %d", ErrorType);
        break;
    }
    for (;;)
        ;

};

/*------------------------------- Footnotes -------------------------------*/
/*------------------------------ End of file ------------------------------*/
