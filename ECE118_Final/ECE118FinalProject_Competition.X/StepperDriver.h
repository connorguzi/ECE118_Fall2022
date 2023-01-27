/*
 * File:   Stepper.h
 * Author: Elkaim
 *
 * Software module to drive a stepper motor through a normal H-bridge in full-step drive
 * mode. The module uses TIMER3 and is capable of generated 1/2 to 20,000 steps per second.
 * The nominal port used is PORTZ and can be changed by changing the appropriate #defines
 * below.
 *
 * NOTE: Module uses TIMER3 for its interrupts. When modifying this code for your own
 *       use, note that you will need to alter the #defines for modes below, and that
 *       only one of them can be active at any one time.

 * STEPPER_TEST (in the .c file) conditionally compiles the test harness for the code. 
 * Make sure it is commented out for module useage.
 *
 * Created on January 2, 2012, 9:36 PM
 * Updated on October 17, 2021, 8:49PM to update drive module #defines for L298N H-bridge
 */

#ifndef StepperDriver_H
#define StepperDriver_H

#include <BOARD.h>

/*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/

#define FORWARD 0
#define REVERSE 1

#define TRIS_LEFT_ENABLE TRISFbits.TRISF1     	//PORTZ_04
#define TRIS_LEFT_STEP_SIGNAL TRISEbits.TRISE4  	//PORTZ_03
#define TRIS_LEFT_DIRECTION TRISEbits.TRISE3	//PORTZ_05
#define TRIS_RIGHT_ENABLE TRISDbits.TRISD8     	//PORTZ_08
#define TRIS_RIGHT_STEP_SIGNAL TRISEbits.TRISE2  	//PORTZ_07
#define TRIS_RIGHT_DIRECTION TRISEbits.TRISE1  //PORTZ_09

#define LEFT_ENABLE LATFbits.LATF1
#define LEFT_STEP_SIGNAL LATEbits.LATE4
#define LEFT_DIRECTION LATEbits.LATE3
#define RIGHT_ENABLE LATDbits.LATD8
#define RIGHT_STEP_SIGNAL LATEbits.LATE2
#define RIGHT_DIRECTION LATEbits.LATE1

#define STEPS_PER_TURN 9700
#define LARGE_STEPS 4294967290
#define BASE_WIDTH 190 // 190mm distance between the middle of both wheels
#define WHEEL_DIAM 55 // Wheel diameter is 65mm
#define LARGE_SPIN 600
#define STEPS_PER_SPIN 9847
#define STEPS_PER_10 1600*2.62 //1600 steps * 2.62 rotations = 10 inches
/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/

/**
 * @Function: Stepper_Init(void);
 * @param none
 * @return SUCCESS or ERROR
 * @brief Initializes the Stepper Module, sets up the stepper on PORTZ
 * @note Defaults to a stepping rate of MED_HZ_RATE
 * @author Gabriel Hugh Elkaim, 2016.10.13 15:37 */
int8_t Stepper_Init(void);
/**
 * @Function Stepper_SetRate(unsigned short int rate);
 * @param rate, steps per second, 0 is a special case of 0.5Hz
 * @return SUCCESS or ERROR
 * @brief Sets the stepping rate in steps per second
 * @author Gabriel Hugh Elkaim, 2016.10.13 15:37 */
int8_t Stepper_SetRate(uint16_t rate);
int8_t Stepper_SetRightRate(uint16_t rate);
void SetRate(uint16_t rate);
/**
 * @Function Stepper_GetRate(void);
 * @param none
 * @return rate in steps per second
 * @brief Gets the stepping rate in steps per second
 * @author Gabriel Hugh Elkaim, 2016.10.13 15:37 */
uint16_t Stepper_GetRate(void);

/**
 * @Function: Stepper_SetSteps(char direction, unsigned int steps);
 * @param direction - stepper direction (FORWARD or REVERSE)
 * @param steps - number of steps to take
 * @return SUCCESS or ERROR
 * @brief Sets the number of steps and direction for the stepper drive. Wipes
 *        out any previous values, does NOT start stepping. If the stepper is
 *        already stepping, then the stepper will continue stepping.
 * @author Gabriel Hugh Elkaim, 2016.10.13 15:37 */
int8_t Stepper_SetSteps(uint8_t direction, uint32_t steps);
int8_t Stepper_SetRightSteps(uint8_t direction, uint32_t steps);

/**
 * @Function: Stepper_InitSteps(char direction, unsigned int steps);
 * @param direction - stepper direction (FORWARD or REVERSE)
 * @param steps - number of steps to take
 * @return SUCCESS or ERROR
 * @brief Sets the number of steps and direction for the stepper drive. Wipes
 *        out any previous stepper command and starts stepping.
 * @author Gabriel Hugh Elkaim, 2016.10.13 15:37 */
int8_t Stepper_InitSteps(uint8_t direction, uint32_t steps);
int8_t Stepper_InitRightSteps(uint8_t direction, uint32_t steps);

/**
 * @Function: Stepper_StartSteps(void);
 * @param none
 * @return SUCCESS or ERROR
 * @brief Starts the stepper motor stepping
 * @author Gabriel Hugh Elkaim, 2016.10.13 15:37 */
int8_t Stepper_StartSteps(void);
int8_t Stepper_StartRightSteps(void);

/**
 * @Function: Stepper_StopSteps(void);
 * @param none
 * @return SUCCESS or ERROR
 * @brief Stops the stepper motor stepping
 * @author Gabriel Hugh Elkaim, 2016.10.13 15:37 */
int8_t Stepper_StopsSteps(void);
int8_t Stepper_StopsRightSteps(void);

/**
 * @Function: Stepper_GetRemainingSteps(void);
 * @return number of remaining steps
 * @brief Returns the number of remaining steps
 * @author Gabriel Hugh Elkaim, 2012.01.28 23:21 */
int32_t Stepper_GetRemainingSteps(void);
int32_t Stepper_GetRightRemainingSteps(void);

/**
 * @Function: Stepper_GetDirection(void);
 * @return FORWARD or REVERSE
 * @brief Returns the current direction (or previous if stopped)
 * @author Gabriel Hugh Elkaim, 2012.01.28 23:21 */
int8_t Stepper_GetDirection(void);
int8_t Stepper_GetRightDirection(void);

/**
 * @Function: Stepper_IsStepping(void);
 * @return TRUE or FALSE
 * @brief Returns TRUE if the stepper is currently stepping, FALSE otherwise
 * @author Gabriel Hugh Elkaim, 2016.10.13 15:37 */
int8_t Stepper_IsStepping(void);
int8_t Stepper_IsRightStepping(void);

/**
 * @Function: Stepper_End(void);
 * @return SUCCESS or ERROR
 * @brief Shuts down the stepper driver software module. Module can be re-enabled
 *        using a stepper init.
 * @author Gabriel Hugh Elkaim, 2012.01.28 23:21 */
int8_t Stepper_End(void);

void TurnRight(int angle);
void TurnLeft(int angle);
void DriveForward(uint32_t steps);
void DriveBackward(uint32_t steps);
void driveInches(float inches);
void driveInchesBackward(float inches);
void StepperStop(void);
void setEnableHigh(void);
void StepperSpin(void);

#endif
