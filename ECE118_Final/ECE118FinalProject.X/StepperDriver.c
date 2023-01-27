/*
 * File:   Stepper.c
 * Author: Elkaim
 *
 * Created on January 2, 2012, 9:49 PM
 */

#include <StepperDriver.h>
#include <stdio.h>
#include <xc.h>
#include <sys/attribs.h>
//#include <peripheral/timer.h>

/*******************************************************************************
 * PRIVATE #DEFINES                                                            *
 ******************************************************************************/
//#define STEPPER_TEST

/* Note that you need to set the prescalar and peripheral clock appropriate to
 * the processor board that you are using. In order to calculate the minimal
 * prescalar: Prescalar = (2000*F_PB/(1000000*0xFFFF))+1, round down */
#ifndef F_CPU
#define F_CPU       80000000L
#define F_PB        (F_CPU/2)
#define F_PB_DIV8   (F_PB/8)
#define F_PB_DIV64  (F_PB/64)
#define ONE_KHZ_RATE  (F_PB_DIV8-1)/1000
#endif

#define MED_HZ_RATE 77
#define LOW_HZ_RATE 10
#define LOW_REP_NUM 64

#define ONE_HUNDRED_HZ 100
#define TWENTY_KILOHERTZ 20000

#define DEFAULT_STEP_RATE ONE_HUNDRED_HZ

#define LED_BANK1_3 LATDbits.LATD6
#define LED_BANK1_2 LATDbits.LATD11
#define LED_BANK1_1 LATDbits.LATD3
#define LED_BANK1_0 LATDbits.LATD5

#define ShutDownDrive() (LEFT_ENABLE = 1, RIGHT_ENABLE = 1)
#define TurnOnDrive() (LEFT_ENABLE = 0, RIGHT_ENABLE = 0)
//#define TurnOnDriveR() (RIGHT_ENABLE = 0)


/*******************************************************************************
 * PRIVATE STRUCTS and TYPEDEFS                                                *
 ******************************************************************************/
//integer round: (x - 1)/y + 1
/*******************************************************************************
 * PRIVATE VARIABLES                                                           *
 ******************************************************************************/

static int32_t stepCount = 0;
static int32_t stepCountR = 0;
static uint32_t overflowReps = 0;
static uint32_t overflowRepsR = 0;

static uint8_t stepDir = FORWARD;
static uint8_t stepDirR = FORWARD;
static uint16_t stepsPerSecondRate = DEFAULT_STEP_RATE;

static enum {
    off, inited, stepping, halted,
} stepperLeftState = off;

static enum {
    offR, initedR, steppingR, haltedR,
} stepperRightState = offR;

static enum {
    step_one, step_two, step_three, step_four
} coilState = step_one;

static enum {
    step_oneR, step_twoR, step_threeR, step_fourR
} coilStateR = step_oneR;

/*******************************************************************************
 * PRIVATE FUNCTIONS PROTOTYPES                                                *
 ******************************************************************************/
/**
 * @Function: CalculateOverflowPeriod(uint16_t rate);
 * @param pulse rate is steps per second (0 = 0.5Hz, special case)
 * @return period overflow for timer to match step rate
 * @remark Calculates the overflow period and sets the module variable
 *         overflowReps to match for the right step rate.
 *         Note: rate 0 is a special case corresponding to 0.5Hz
 * @author Gabriel Hugh Elkaim
 * @date 2012.01.28 23:21 */
uint32_t CalculateOverflowPeriod(uint16_t rate);
uint32_t CalculateOverflowPeriodR(uint16_t rate);

static void LeftMotorDriver(void);
static void RightMotorDriver(void);

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                           *
 ******************************************************************************/

int8_t SetHigh(void)
{
    LEFT_STEP_SIGNAL = 1;
}
/* Stepper_Init(void) initializes the stepper module to step at 100Hz and makes
 * sure that all module level variables are initialized correctly. 
 */
int8_t Stepper_Init(void)
{
    uint16_t overflowPeriod;
    uint16_t overflowPeriodR;
    
    if (stepperLeftState != off || stepperRightState != offR) {
        return ERROR;
    }
    stepCount = 0;
    stepCountR = 0;
    overflowReps = 0;
    overflowRepsR = 0;
    
    stepsPerSecondRate = DEFAULT_STEP_RATE;
    // Initialize hardware (no current flow)
    LEFT_STEP_SIGNAL = 1;
    LEFT_DIRECTION = FORWARD;
    RIGHT_STEP_SIGNAL = 1;
    RIGHT_DIRECTION = FORWARD;
    
    TRIS_LEFT_STEP_SIGNAL = 0;
    TRIS_LEFT_DIRECTION = 0;
    TRIS_LEFT_ENABLE = 0;
    TRIS_RIGHT_STEP_SIGNAL = 0;
    TRIS_RIGHT_DIRECTION = 0;
    TRIS_RIGHT_ENABLE = 0;
    // Calculate overflow time and prescalar
    overflowPeriod = CalculateOverflowPeriod(stepsPerSecondRate);
    overflowPeriodR = CalculateOverflowPeriodR(stepsPerSecondRate);
    // Setup timer and interrupt (Timer 3)
    T3CON = 0; // reset everything
    T3CONbits.TCKPS = 0b011;    // set prescaler 8:1
    TMR3 = 0; // start timer at 0
    PR3 = overflowPeriod;
    // timer 3
    IFS0bits.T3IF = 0; // clear remnant flag
    IPC3bits.T3IP = 3; // set interrupt priority
    IEC0bits.T3IE = 1; // start interrupts for timer
    T3CONbits.ON = 1;
    stepperLeftState = inited;
    stepperRightState = initedR;
    return SUCCESS;
}

/* Sets the module variable with rate, and changes the overflow period
 * of the TIMER3 to generate the correct interrupt and repetition number
 * to match the number of steps per second.
 */
int8_t Stepper_SetRate(uint16_t rate)
{
    uint16_t overflowPeriod;
    stepsPerSecondRate = rate;
    if ((rate > TWENTY_KILOHERTZ)) {
        return ERROR;
    }
    T3CONbits.ON = 0; // halt timer3
    overflowPeriod = CalculateOverflowPeriod(rate);
    PR3 = overflowPeriod;
    if (stepperLeftState != halted) {
        T3CONbits.ON = 1; // restart timer3
    }
    return SUCCESS;
}

int8_t Stepper_SetRightRate(uint16_t rate)
{
    uint16_t overflowPeriodR;
    stepsPerSecondRate = rate;
    if ((rate > TWENTY_KILOHERTZ)) {
        return ERROR;
    }
    T3CONbits.ON = 0; // halt timer2
    overflowPeriodR = CalculateOverflowPeriodR(rate);
    PR3 = overflowPeriodR;
    if (stepperRightState != haltedR) {
        T3CONbits.ON = 1; // restart timer2
    }
    return SUCCESS;
}

//// Wrapper function for the module variable that tracks rate
//uint16_t Stepper_GetRate(void)
//{
//    return stepsPerSecondRate;
//}

// Sets the module level variable of direction and number of steps
int8_t Stepper_SetSteps(uint8_t direction, uint32_t steps)
{
    if (stepperLeftState == off) return ERROR;
    if ((direction == FORWARD) || (direction == REVERSE)) {
        stepDir = direction;
        stepCount = steps;
        return SUCCESS;
    }
    return ERROR;
}

// Sets the module level variable of direction and number of steps
int8_t Stepper_SetRightSteps(uint8_t direction, uint32_t steps)
{
    if (stepperRightState == offR) return ERROR;
    if ((direction == FORWARD) || (direction == REVERSE)) {
        stepDirR = direction;
        stepCountR = steps;
        return SUCCESS;
    }
    return ERROR;
}
// Sets the steps and directions, and starts the stepper going
int8_t Stepper_InitSteps(uint8_t direction, uint32_t steps)
{
    int8_t result = ERROR;
    LEFT_ENABLE = 0;
    if ((stepperLeftState == off) || (steps == 0)) return ERROR;
    result = Stepper_SetSteps(direction, steps);
    if (result == ERROR) {
        return result;
    }
    result = Stepper_StartSteps();
    return result;
}

// Sets the steps and directions, and starts the stepper going
int8_t Stepper_InitRightSteps(uint8_t direction, uint32_t steps)
{
    int8_t result = ERROR;
    RIGHT_ENABLE = 0;
    if ((stepperRightState == offR) || (steps == 0)) return ERROR;
    result = Stepper_SetRightSteps(direction, steps);
    if (result == ERROR) {
        return result;
    }
    result = Stepper_StartRightSteps();
    return result;
}

// Sets the enum for the stepper state to stepping
int8_t Stepper_StartSteps(void)
{
    if ((stepCount == 0) || (stepperLeftState == stepping)) {
        return ERROR;
    }
    stepperLeftState = stepping;
    TurnOnDrive();
    return SUCCESS;
}

int8_t Stepper_StartRightSteps(void)
{
    if ((stepCountR == 0) || (stepperRightState == steppingR)) {
        return ERROR;
    }
    stepperRightState = steppingR;
    TurnOnDrive();
    return SUCCESS;
}

// Sets the enum for the stepper state to halted
int8_t Stepper_StopsSteps(void)
{
    if ((stepperLeftState == off) || (stepperLeftState == halted)) return ERROR;
    stepperLeftState = halted;
    return SUCCESS;
}

// Sets the enum for the stepper state to halted
int8_t Stepper_StopsRightSteps(void)
{
    if ((stepperRightState == offR) || (stepperRightState == haltedR)) return ERROR;
    stepperRightState = haltedR;
    return SUCCESS;
}

// Wrapper to return the step count
int32_t Stepper_GetRemainingSteps(void)
{
    return stepCount;
}
int32_t Stepper_GetRightRemainingSteps(void)
{
    return stepCountR;
}

int8_t Stepper_GetDirection(void)
{
    return stepDir;
}
int8_t Stepper_GetRightDirection(void)
{
    return stepDirR;
}

// wrapper function to check state
int8_t Stepper_IsStepping(void)
{
    return (stepperLeftState == stepping);
}
int8_t Stepper_IsRightStepping(void)
{
    return (stepperRightState == steppingR);
}
int8_t Stepper_End(void)
{
    if (stepperLeftState == off) {
        return ERROR;
    }
    T3CONbits.ON = 0; // halt timer3
    stepperLeftState = off;
    ShutDownDrive();
    // turn hardware pins back to inputs
    TRIS_LEFT_STEP_SIGNAL = 1;
    TRIS_LEFT_DIRECTION = 1;
    TRIS_LEFT_ENABLE = 1;
    TRIS_RIGHT_STEP_SIGNAL = 1;
    TRIS_RIGHT_DIRECTION = 1;
    TRIS_RIGHT_ENABLE = 1;
    // reset module variables
    stepCount = 0;
    stepCountR = 0;
    
    overflowReps = 0;
    overflowRepsR = 0;

    coilState = step_one;
    coilStateR = step_oneR;
    
    stepsPerSecondRate = DEFAULT_STEP_RATE;
    // turn off timer and interrupt
    T3CONbits.ON = 0; // shut down timer 3
    IEC0bits.T3IE = 0; // shut down interrupt
    return SUCCESS;
}

/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/

/* There are three possibilities for the step rate calculation that keep the
   step rate error to under 0.2% of the desired value, from within 0.5 to 2KHz:
   from 78 to 20Khz, Prescale is 1:8, Rollover = (F_PB/8-1)/PPS
   from 10 to 77Hz, Prescale is 1:64, Rollover = (F_PB/64-1)/PPS
   from 0.5 to 10Hz, Set rollover for a constant 1Khz, and increment to reach
   the desired time, Prescale is 1:8, Rollover = (F_PB/8-1)/1000 and the number
   of times to repeat is (1000-1)/PPS + 1                                     */
uint32_t CalculateOverflowPeriod(uint16_t rate)
{
    if (rate == 0) {
        overflowReps = 2000;
        return (ONE_KHZ_RATE);
    }
    if (rate > MED_HZ_RATE) {
        overflowReps = 0;
        return ((F_PB_DIV8 - 1) / rate);
    }
    if (rate > LOW_HZ_RATE) {
       overflowReps = (1000 - 1) / rate;
        return ONE_KHZ_RATE;
    }
    // rate is less than 10Hz, switch to counted 1KHz pulses
    overflowReps = (1000 - 1) / rate + 1;
    return ONE_KHZ_RATE;
}

uint32_t CalculateOverflowPeriodR(uint16_t rate)
{
    if (rate == 0) {
        overflowRepsR = 2000;
        return (ONE_KHZ_RATE);
    }
    if (rate > MED_HZ_RATE) {
        overflowRepsR = 0;
        return ((F_PB_DIV8 - 1) / rate);
    }
    if (rate > LOW_HZ_RATE) {
       overflowRepsR = (1000 - 1) / rate;
        return ONE_KHZ_RATE;
    }
    // rate is less than 10Hz, switch to counted 1KHz pulses
    overflowRepsR = (1000 - 1) / rate + 1;
    return ONE_KHZ_RATE;
}

void LeftMotorDriver(void)
{
    LEFT_DIRECTION = stepDir;
    switch (coilState) {
    case step_one:
        LEFT_STEP_SIGNAL = 1;
        coilState = step_two;
        break;

    case step_two:
        LEFT_STEP_SIGNAL = 0;
        coilState = step_one;
        break;
    }
}

void RightMotorDriver(void)
{
    RIGHT_DIRECTION = stepDirR;    
    switch (coilStateR) {
    case step_oneR:
        RIGHT_STEP_SIGNAL = 1;
        coilStateR = step_twoR;
        break;

    case step_twoR:
        RIGHT_STEP_SIGNAL = 0;
        coilStateR = step_oneR;
        break;
    }
}

void TurnRight(int angle){
    int steps = STEPS_PER_SPIN * angle / 360;
    // int steps = (angle * BASE_WIDTH * STEP_DRIVE)/(WHEEL_DIAM * 1.8); //STEP_DRIVE is the microsteps we're using (8 in this case)
    Stepper_InitRightSteps(REVERSE, steps);
    Stepper_InitSteps(FORWARD, steps);
}
void TurnLeft(int angle){
    int steps = STEPS_PER_SPIN * angle / 360;
    Stepper_InitSteps(REVERSE, steps);
    Stepper_InitRightSteps(FORWARD, steps);
}
void DriveForward(uint32_t steps){
    Stepper_InitRightSteps(FORWARD, steps);
    Stepper_InitSteps(FORWARD, steps);
}
void DriveBackward(uint32_t steps){
    Stepper_InitRightSteps(REVERSE, steps);
    Stepper_InitSteps(REVERSE, steps);
}
void StepperStop(void){
    Stepper_StopsSteps();
    Stepper_StopsRightSteps();
}
void setEnableHigh(void){
    LEFT_ENABLE = 1;
    RIGHT_ENABLE = 1;
}
void driveInches(float inches){
    uint32_t steps = inches * STEPS_PER_10 / 10;
    printf("steps = %d\n\r", steps);
    DriveForward(steps);
}
void driveInchesBackward(float inches){
    uint32_t steps = inches * STEPS_PER_10 / 10;
    printf("steps = %d\n\r", steps);
    DriveBackward(steps);    
}
void StepperSpin(void){
    printf("StepperSpin\r\n");
    TurnRight(2*STEPS_PER_SPIN);
}
void SetRate(uint16_t rate){
    Stepper_SetRate(rate);
    Stepper_SetRightRate(rate);
}
/****************************************************************************
 Function: Timer3IntHandler

 Parameters: None.

 Returns: None.

 Description
    Implements the Stepper motor FULL STEP drive state machine.

 Notes
    

 Author: Gabriel Hugh Elkaim, 2011.12.15 16:42
 ****************************************************************************/
void __ISR(_TIMER_3_VECTOR) Timer3IntHandler(void)
{
    static uint16_t timerLoopCount = 0;
    static uint16_t timerLoopCountR = 0;
    timerLoopCountR++;
    timerLoopCount++;
    
    if (timerLoopCount > overflowReps) {
        timerLoopCount = 0;
        // execute Stepper Drive state machine here
        switch (stepperLeftState) {
        case off: // should not get here
            if (stepperLeftState == off && stepperRightState == offR)
            {
                ShutDownDrive();
                T3CONbits.ON = 0; // halt timer3
                
                IEC0bits.T3IE = 0;
                break;                
            }
            break;

        case inited:
        case halted:
            if (stepCount < 0) {
                stepCount = 0;
            }
            break;

        case stepping:
            if (--stepCount <= 0) {
                stepperLeftState = halted;
            }
            TurnOnDrive();

            LeftMotorDriver();
            break;
        }        
    }

    if (timerLoopCountR > overflowRepsR) {
        timerLoopCountR = 0;
        switch (stepperRightState) {
        case offR: // should not get here
            if (stepperLeftState == off && stepperRightState == offR)
            {
                ShutDownDrive();
                T3CONbits.ON = 0; // halt timer3
                IEC0bits.T3IE = 0;
                break;               
            }
            break;

        case initedR:
        case haltedR:
            if (stepCountR < 0) {
                stepCountR = 0;
            }
            break;

        case steppingR:
            if (--stepCountR <= 0) {
                stepperRightState = haltedR;
            }
            TurnOnDrive();
            RightMotorDriver();
            break;
        }        
    }
    IFS0bits.T3IF = 0;  // clear interrupt flag
}
