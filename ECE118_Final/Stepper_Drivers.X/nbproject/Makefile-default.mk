#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Stepper_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Stepper_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=StepperDriver.c steppermain.c ../../ECE118/src/BOARD.c ../../ECE118/src/AD.c ../../ECE118/src/IO_Ports.c ../../ECE118/src/LED.c ../../ECE118/src/pwm.c ../../ECE118/src/serial.c ../../ECE118/src/timers.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/StepperDriver.o ${OBJECTDIR}/steppermain.o ${OBJECTDIR}/_ext/720413242/BOARD.o ${OBJECTDIR}/_ext/720413242/AD.o ${OBJECTDIR}/_ext/720413242/IO_Ports.o ${OBJECTDIR}/_ext/720413242/LED.o ${OBJECTDIR}/_ext/720413242/pwm.o ${OBJECTDIR}/_ext/720413242/serial.o ${OBJECTDIR}/_ext/720413242/timers.o
POSSIBLE_DEPFILES=${OBJECTDIR}/StepperDriver.o.d ${OBJECTDIR}/steppermain.o.d ${OBJECTDIR}/_ext/720413242/BOARD.o.d ${OBJECTDIR}/_ext/720413242/AD.o.d ${OBJECTDIR}/_ext/720413242/IO_Ports.o.d ${OBJECTDIR}/_ext/720413242/LED.o.d ${OBJECTDIR}/_ext/720413242/pwm.o.d ${OBJECTDIR}/_ext/720413242/serial.o.d ${OBJECTDIR}/_ext/720413242/timers.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/StepperDriver.o ${OBJECTDIR}/steppermain.o ${OBJECTDIR}/_ext/720413242/BOARD.o ${OBJECTDIR}/_ext/720413242/AD.o ${OBJECTDIR}/_ext/720413242/IO_Ports.o ${OBJECTDIR}/_ext/720413242/LED.o ${OBJECTDIR}/_ext/720413242/pwm.o ${OBJECTDIR}/_ext/720413242/serial.o ${OBJECTDIR}/_ext/720413242/timers.o

# Source Files
SOURCEFILES=StepperDriver.c steppermain.c ../../ECE118/src/BOARD.c ../../ECE118/src/AD.c ../../ECE118/src/IO_Ports.c ../../ECE118/src/LED.c ../../ECE118/src/pwm.c ../../ECE118/src/serial.c ../../ECE118/src/timers.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Stepper_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX320F128H
MP_LINKER_FILE_OPTION=,--script="..\..\ECE118\bootloader320.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/StepperDriver.o: StepperDriver.c  .generated_files/flags/default/f0d32d5a76a4478339f3b0066566eb50c27da508 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/StepperDriver.o.d 
	@${RM} ${OBJECTDIR}/StepperDriver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/StepperDriver.o.d" -o ${OBJECTDIR}/StepperDriver.o StepperDriver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/steppermain.o: steppermain.c  .generated_files/flags/default/15a38831f09d10bf692c5d1a2b583b34c193deb9 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/steppermain.o.d 
	@${RM} ${OBJECTDIR}/steppermain.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/steppermain.o.d" -o ${OBJECTDIR}/steppermain.o steppermain.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/BOARD.o: ../../ECE118/src/BOARD.c  .generated_files/flags/default/eb96113fa200135f380a8a42b5ffa10a12aa317a .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/BOARD.o.d" -o ${OBJECTDIR}/_ext/720413242/BOARD.o ../../ECE118/src/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/AD.o: ../../ECE118/src/AD.c  .generated_files/flags/default/c038969027ce5878e6864ee7d9eceba96ce0d230 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/AD.o.d" -o ${OBJECTDIR}/_ext/720413242/AD.o ../../ECE118/src/AD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/IO_Ports.o: ../../ECE118/src/IO_Ports.c  .generated_files/flags/default/f0400a067442822f2340caa4e6b2441f24d31a88 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/720413242/IO_Ports.o ../../ECE118/src/IO_Ports.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/LED.o: ../../ECE118/src/LED.c  .generated_files/flags/default/902898a2b7f6f69f34bd506005ed842afe94629a .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/LED.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/LED.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/LED.o.d" -o ${OBJECTDIR}/_ext/720413242/LED.o ../../ECE118/src/LED.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/pwm.o: ../../ECE118/src/pwm.c  .generated_files/flags/default/4b84c6c4c7965448ef234a7801a462703461e521 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/pwm.o.d" -o ${OBJECTDIR}/_ext/720413242/pwm.o ../../ECE118/src/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/serial.o: ../../ECE118/src/serial.c  .generated_files/flags/default/a688f387dbc8ff15ef78352b71d98f903f31f26b .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/serial.o.d" -o ${OBJECTDIR}/_ext/720413242/serial.o ../../ECE118/src/serial.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/timers.o: ../../ECE118/src/timers.c  .generated_files/flags/default/856ae5396c50d22f004c1933704dcd63d6ebade .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/timers.o.d" -o ${OBJECTDIR}/_ext/720413242/timers.o ../../ECE118/src/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/StepperDriver.o: StepperDriver.c  .generated_files/flags/default/a668d1922d05ecc833132c075294d7f716bf51ce .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/StepperDriver.o.d 
	@${RM} ${OBJECTDIR}/StepperDriver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/StepperDriver.o.d" -o ${OBJECTDIR}/StepperDriver.o StepperDriver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/steppermain.o: steppermain.c  .generated_files/flags/default/1449115aec7a40bf85ce1d45d0c19348563ba26a .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/steppermain.o.d 
	@${RM} ${OBJECTDIR}/steppermain.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/steppermain.o.d" -o ${OBJECTDIR}/steppermain.o steppermain.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/BOARD.o: ../../ECE118/src/BOARD.c  .generated_files/flags/default/1ea1a2c1b0067476019c0cd13c4fa9ddaafe45fa .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/BOARD.o.d" -o ${OBJECTDIR}/_ext/720413242/BOARD.o ../../ECE118/src/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/AD.o: ../../ECE118/src/AD.c  .generated_files/flags/default/7849f8ef44638223d65697a8624738ef5b13c13d .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/AD.o.d" -o ${OBJECTDIR}/_ext/720413242/AD.o ../../ECE118/src/AD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/IO_Ports.o: ../../ECE118/src/IO_Ports.c  .generated_files/flags/default/f8a4e2932ac2938b7837c71b0856369c442da21c .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/720413242/IO_Ports.o ../../ECE118/src/IO_Ports.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/LED.o: ../../ECE118/src/LED.c  .generated_files/flags/default/4640d418fb4f750b9b280e177076bd67f504d889 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/LED.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/LED.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/LED.o.d" -o ${OBJECTDIR}/_ext/720413242/LED.o ../../ECE118/src/LED.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/pwm.o: ../../ECE118/src/pwm.c  .generated_files/flags/default/7b229b3be6a7ce71639c782af20e70a6183f3bd7 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/pwm.o.d" -o ${OBJECTDIR}/_ext/720413242/pwm.o ../../ECE118/src/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/serial.o: ../../ECE118/src/serial.c  .generated_files/flags/default/ec818b085cd4b3dbbc79439d558c854aeb6723d8 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/serial.o.d" -o ${OBJECTDIR}/_ext/720413242/serial.o ../../ECE118/src/serial.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/timers.o: ../../ECE118/src/timers.c  .generated_files/flags/default/8a953f46823518face276772fb561cafe3833bb5 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/timers.o.d" -o ${OBJECTDIR}/_ext/720413242/timers.o ../../ECE118/src/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Stepper_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../../ECE118/bootloader320.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Stepper_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/Stepper_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../../ECE118/bootloader320.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Stepper_Drivers.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/Stepper_Drivers.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
