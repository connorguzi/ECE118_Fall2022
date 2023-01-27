/**
 * @file    Bumpers.h
 * @brief   Bumper Module
 * @author  Connor Guzikowski
 * @date    11/19/2022
 * @detail  This module is used to read the bumpers
          
 */

#ifndef Bumpers_H
#define Bumpers_H

/*******************************************************************************
 * INCLUDES                                                                    *
 ******************************************************************************/
#include "BOARD.h"
#include <xc.h>
#include <sys/attribs.h>
#include "IO_Ports.h"

/*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/
// Bumper pins
#define TRIS_FRONT_BUMPERS PORTV05_TRIS //Port V5
#define FRONT_BUMPERS PORTV05_BIT //Reading input
// Common values used
#define HIGH 1
#define LOW 0
#define OUTPUT 0
#define INPUT 1

// States for cycling through ping sensors

/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/

/**
 * @function    Bumper_Init(void)
 * @brief       Sets up the pins to be used for the bumpers
 * @return      SUCCESS or ERROR (as defined in BOARD.h)
 */
void Bumper_Init(void);

/**
 * @function    FrontBumper_Read(void)
 * @brief       Returns true or false depending on the reading of the front bumpers
 *              
 * @return      True/False
 */
uint8_t FrontBumper_Read(void);

/**
 * @function    RearBumper_Read(void)
 * @brief       Returns true or false depending on the reading of the rear bumpers
 *              
 * @return      True/False
 */
uint8_t RearBumper_Read(void);

#endif