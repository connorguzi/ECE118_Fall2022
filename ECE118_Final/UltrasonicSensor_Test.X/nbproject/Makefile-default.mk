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
FINAL_IMAGE=${DISTDIR}/UltrasonicSensor_Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/UltrasonicSensor_Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../../ECE118/src/AD.c ../../ECE118/src/BOARD.c ../../ECE118/src/IO_Ports.c ../../ECE118/src/pwm.c ../../ECE118/src/serial.c ../../ECE118/src/timers.c ping_test.c ping.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/720413242/AD.o ${OBJECTDIR}/_ext/720413242/BOARD.o ${OBJECTDIR}/_ext/720413242/IO_Ports.o ${OBJECTDIR}/_ext/720413242/pwm.o ${OBJECTDIR}/_ext/720413242/serial.o ${OBJECTDIR}/_ext/720413242/timers.o ${OBJECTDIR}/ping_test.o ${OBJECTDIR}/ping.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/720413242/AD.o.d ${OBJECTDIR}/_ext/720413242/BOARD.o.d ${OBJECTDIR}/_ext/720413242/IO_Ports.o.d ${OBJECTDIR}/_ext/720413242/pwm.o.d ${OBJECTDIR}/_ext/720413242/serial.o.d ${OBJECTDIR}/_ext/720413242/timers.o.d ${OBJECTDIR}/ping_test.o.d ${OBJECTDIR}/ping.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/720413242/AD.o ${OBJECTDIR}/_ext/720413242/BOARD.o ${OBJECTDIR}/_ext/720413242/IO_Ports.o ${OBJECTDIR}/_ext/720413242/pwm.o ${OBJECTDIR}/_ext/720413242/serial.o ${OBJECTDIR}/_ext/720413242/timers.o ${OBJECTDIR}/ping_test.o ${OBJECTDIR}/ping.o

# Source Files
SOURCEFILES=../../ECE118/src/AD.c ../../ECE118/src/BOARD.c ../../ECE118/src/IO_Ports.c ../../ECE118/src/pwm.c ../../ECE118/src/serial.c ../../ECE118/src/timers.c ping_test.c ping.c



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

# The following macros may be used in the pre and post step lines
_/_=\\
ShExtension=.bat
Device=PIC32MX320F128H
ProjectDir="C:\Users\conno\Documents\ECE118_Final\UltrasonicSensor_Test.X"
ProjectName=UltrasonicSensor_Test
ConfName=default
ImagePath="${DISTDIR}\UltrasonicSensor_Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ImageDir="${DISTDIR}"
ImageName="UltrasonicSensor_Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif

.build-conf:  .pre ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/UltrasonicSensor_Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/720413242/AD.o: ../../ECE118/src/AD.c  .generated_files/flags/default/c038969027ce5878e6864ee7d9eceba96ce0d230 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/AD.o.d" -o ${OBJECTDIR}/_ext/720413242/AD.o ../../ECE118/src/AD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/BOARD.o: ../../ECE118/src/BOARD.c  .generated_files/flags/default/eb96113fa200135f380a8a42b5ffa10a12aa317a .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/BOARD.o.d" -o ${OBJECTDIR}/_ext/720413242/BOARD.o ../../ECE118/src/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/IO_Ports.o: ../../ECE118/src/IO_Ports.c  .generated_files/flags/default/f0400a067442822f2340caa4e6b2441f24d31a88 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/720413242/IO_Ports.o ../../ECE118/src/IO_Ports.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
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
	
${OBJECTDIR}/ping_test.o: ping_test.c  .generated_files/flags/default/6e896643617fb80691570fe70ae1c193349f530b .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ping_test.o.d 
	@${RM} ${OBJECTDIR}/ping_test.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ping_test.o.d" -o ${OBJECTDIR}/ping_test.o ping_test.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ping.o: ping.c  .generated_files/flags/default/53106d2d09ebeb70a7bcbba5699e4f51ce96463b .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ping.o.d 
	@${RM} ${OBJECTDIR}/ping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ping.o.d" -o ${OBJECTDIR}/ping.o ping.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/720413242/AD.o: ../../ECE118/src/AD.c  .generated_files/flags/default/7849f8ef44638223d65697a8624738ef5b13c13d .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/AD.o.d" -o ${OBJECTDIR}/_ext/720413242/AD.o ../../ECE118/src/AD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/BOARD.o: ../../ECE118/src/BOARD.c  .generated_files/flags/default/1ea1a2c1b0067476019c0cd13c4fa9ddaafe45fa .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/BOARD.o.d" -o ${OBJECTDIR}/_ext/720413242/BOARD.o ../../ECE118/src/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/720413242/IO_Ports.o: ../../ECE118/src/IO_Ports.c  .generated_files/flags/default/f8a4e2932ac2938b7837c71b0856369c442da21c .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}/_ext/720413242" 
	@${RM} ${OBJECTDIR}/_ext/720413242/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/720413242/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/720413242/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/720413242/IO_Ports.o ../../ECE118/src/IO_Ports.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
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
	
${OBJECTDIR}/ping_test.o: ping_test.c  .generated_files/flags/default/c9dadde0835ae2b7a22cc18d84ce23ec46b5b6ae .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ping_test.o.d 
	@${RM} ${OBJECTDIR}/ping_test.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ping_test.o.d" -o ${OBJECTDIR}/ping_test.o ping_test.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ping.o: ping.c  .generated_files/flags/default/3ccb1756abfc8724531e176ba11f77f737cdf119 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ping.o.d 
	@${RM} ${OBJECTDIR}/ping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ping.o.d" -o ${OBJECTDIR}/ping.o ping.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/UltrasonicSensor_Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../../ECE118/bootloader320.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/UltrasonicSensor_Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/UltrasonicSensor_Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../../ECE118/bootloader320.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/UltrasonicSensor_Test.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/UltrasonicSensor_Test.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif

.pre:
	@echo "--------------------------------------"
	@echo "User defined pre-build step: [python C:\Users\conno\Documents\ECE118\scripts\Enum_To_String.py]"
	@python C:\Users\conno\Documents\ECE118\scripts\Enum_To_String.py
	@echo "--------------------------------------"

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
