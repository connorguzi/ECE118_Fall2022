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
#include "Bumpers.h"
//#include "timers.h"
/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/

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
void Bumper_Init(void){
    FRONT_BUMPERS = 0;
    TRIS_FRONT_BUMPERS = 1; // input
}

uint8_t FrontBumper_Read(void){
    if(FRONT_BUMPERS){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

uint8_t RearBumper_Read(void){
    return FALSE;
}