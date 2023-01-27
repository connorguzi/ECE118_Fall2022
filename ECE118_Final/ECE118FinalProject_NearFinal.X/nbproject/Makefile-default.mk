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
FINAL_IMAGE=${DISTDIR}/ECE118FinalProject_NearFinal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ECE118FinalProject_NearFinal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=AD.c BOARD.c ES_CheckEvents.c ES_Framework.c ES_KeyboardInput.c ES_PostList.c ES_Queue.c ES_TattleTale.c ES_Timers.c EventChecker.c HSM_LaunchingSub.c HSM_Robot.c IO_Ports.c Robot_Main.c StepperDriver.c ping.c serial.c timers.c HSM_MovementSub.c Bumpers.c HSM_AvoidObstacleSub.c HSM_ReloadingSub.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/AD.o ${OBJECTDIR}/BOARD.o ${OBJECTDIR}/ES_CheckEvents.o ${OBJECTDIR}/ES_Framework.o ${OBJECTDIR}/ES_KeyboardInput.o ${OBJECTDIR}/ES_PostList.o ${OBJECTDIR}/ES_Queue.o ${OBJECTDIR}/ES_TattleTale.o ${OBJECTDIR}/ES_Timers.o ${OBJECTDIR}/EventChecker.o ${OBJECTDIR}/HSM_LaunchingSub.o ${OBJECTDIR}/HSM_Robot.o ${OBJECTDIR}/IO_Ports.o ${OBJECTDIR}/Robot_Main.o ${OBJECTDIR}/StepperDriver.o ${OBJECTDIR}/ping.o ${OBJECTDIR}/serial.o ${OBJECTDIR}/timers.o ${OBJECTDIR}/HSM_MovementSub.o ${OBJECTDIR}/Bumpers.o ${OBJECTDIR}/HSM_AvoidObstacleSub.o ${OBJECTDIR}/HSM_ReloadingSub.o
POSSIBLE_DEPFILES=${OBJECTDIR}/AD.o.d ${OBJECTDIR}/BOARD.o.d ${OBJECTDIR}/ES_CheckEvents.o.d ${OBJECTDIR}/ES_Framework.o.d ${OBJECTDIR}/ES_KeyboardInput.o.d ${OBJECTDIR}/ES_PostList.o.d ${OBJECTDIR}/ES_Queue.o.d ${OBJECTDIR}/ES_TattleTale.o.d ${OBJECTDIR}/ES_Timers.o.d ${OBJECTDIR}/EventChecker.o.d ${OBJECTDIR}/HSM_LaunchingSub.o.d ${OBJECTDIR}/HSM_Robot.o.d ${OBJECTDIR}/IO_Ports.o.d ${OBJECTDIR}/Robot_Main.o.d ${OBJECTDIR}/StepperDriver.o.d ${OBJECTDIR}/ping.o.d ${OBJECTDIR}/serial.o.d ${OBJECTDIR}/timers.o.d ${OBJECTDIR}/HSM_MovementSub.o.d ${OBJECTDIR}/Bumpers.o.d ${OBJECTDIR}/HSM_AvoidObstacleSub.o.d ${OBJECTDIR}/HSM_ReloadingSub.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/AD.o ${OBJECTDIR}/BOARD.o ${OBJECTDIR}/ES_CheckEvents.o ${OBJECTDIR}/ES_Framework.o ${OBJECTDIR}/ES_KeyboardInput.o ${OBJECTDIR}/ES_PostList.o ${OBJECTDIR}/ES_Queue.o ${OBJECTDIR}/ES_TattleTale.o ${OBJECTDIR}/ES_Timers.o ${OBJECTDIR}/EventChecker.o ${OBJECTDIR}/HSM_LaunchingSub.o ${OBJECTDIR}/HSM_Robot.o ${OBJECTDIR}/IO_Ports.o ${OBJECTDIR}/Robot_Main.o ${OBJECTDIR}/StepperDriver.o ${OBJECTDIR}/ping.o ${OBJECTDIR}/serial.o ${OBJECTDIR}/timers.o ${OBJECTDIR}/HSM_MovementSub.o ${OBJECTDIR}/Bumpers.o ${OBJECTDIR}/HSM_AvoidObstacleSub.o ${OBJECTDIR}/HSM_ReloadingSub.o

# Source Files
SOURCEFILES=AD.c BOARD.c ES_CheckEvents.c ES_Framework.c ES_KeyboardInput.c ES_PostList.c ES_Queue.c ES_TattleTale.c ES_Timers.c EventChecker.c HSM_LaunchingSub.c HSM_Robot.c IO_Ports.c Robot_Main.c StepperDriver.c ping.c serial.c timers.c HSM_MovementSub.c Bumpers.c HSM_AvoidObstacleSub.c HSM_ReloadingSub.c



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
ProjectDir="C:\Users\conno\Documents\ECE118_Final\ECE118FinalProject_NearFinal.X"
ProjectName=ECE118FinalProject_NearFinal
ConfName=default
ImagePath="${DISTDIR}\ECE118FinalProject_NearFinal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ImageDir="${DISTDIR}"
ImageName="ECE118FinalProject_NearFinal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif

.build-conf:  .pre ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/ECE118FinalProject_NearFinal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/AD.o: AD.c  .generated_files/flags/default/d536a32de9d2ebe0236a3f067a95d6aa210340e4 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/AD.o.d 
	@${RM} ${OBJECTDIR}/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/AD.o.d" -o ${OBJECTDIR}/AD.o AD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/BOARD.o: BOARD.c  .generated_files/flags/default/ad31a7eb6a12be9d49ce09a32f6a974f4c63761d .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BOARD.o.d 
	@${RM} ${OBJECTDIR}/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/BOARD.o.d" -o ${OBJECTDIR}/BOARD.o BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_CheckEvents.o: ES_CheckEvents.c  .generated_files/flags/default/ee82805d410ffde25ee1ca53f45a2a0842b41b63 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/ES_CheckEvents.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ES_CheckEvents.o.d" -o ${OBJECTDIR}/ES_CheckEvents.o ES_CheckEvents.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_Framework.o: ES_Framework.c  .generated_files/flags/default/51ae23cc65b5112ffb82bf5bc3a5f222121e8c69 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/ES_Framework.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ES_Framework.o.d" -o ${OBJECTDIR}/ES_Framework.o ES_Framework.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_KeyboardInput.o: ES_KeyboardInput.c  .generated_files/flags/default/2a716c18d879e3ad35cb97f76c69982c3138fa6b .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/ES_KeyboardInput.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/ES_KeyboardInput.o ES_KeyboardInput.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_PostList.o: ES_PostList.c  .generated_files/flags/default/72aaac0294813422df7e83765f09fca133db7a .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/ES_PostList.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ES_PostList.o.d" -o ${OBJECTDIR}/ES_PostList.o ES_PostList.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_Queue.o: ES_Queue.c  .generated_files/flags/default/29482f38a522e256458f7140809f8e5fb12cf6cf .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/ES_Queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ES_Queue.o.d" -o ${OBJECTDIR}/ES_Queue.o ES_Queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_TattleTale.o: ES_TattleTale.c  .generated_files/flags/default/45d91ab37877a4ff5c871fe1afc1146717b59b7c .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/ES_TattleTale.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ES_TattleTale.o.d" -o ${OBJECTDIR}/ES_TattleTale.o ES_TattleTale.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_Timers.o: ES_Timers.c  .generated_files/flags/default/93c485b362b5fafaaec63900d1e8eec10f27d009 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/ES_Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ES_Timers.o.d" -o ${OBJECTDIR}/ES_Timers.o ES_Timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/EventChecker.o: EventChecker.c  .generated_files/flags/default/15a29e214878246d30dbde65840f6727b1303f18 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventChecker.o.d 
	@${RM} ${OBJECTDIR}/EventChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/EventChecker.o.d" -o ${OBJECTDIR}/EventChecker.o EventChecker.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HSM_LaunchingSub.o: HSM_LaunchingSub.c  .generated_files/flags/default/4b7c63666c5c54dfee24778bb2c946cf11ebf5dc .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HSM_LaunchingSub.o.d 
	@${RM} ${OBJECTDIR}/HSM_LaunchingSub.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/HSM_LaunchingSub.o.d" -o ${OBJECTDIR}/HSM_LaunchingSub.o HSM_LaunchingSub.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HSM_Robot.o: HSM_Robot.c  .generated_files/flags/default/77ec69629880b94df3ba949e4a7099c9a72ced43 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HSM_Robot.o.d 
	@${RM} ${OBJECTDIR}/HSM_Robot.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/HSM_Robot.o.d" -o ${OBJECTDIR}/HSM_Robot.o HSM_Robot.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/IO_Ports.o: IO_Ports.c  .generated_files/flags/default/58fb074b93cfc55cb987d9e9a755ff53c50081ef .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/IO_Ports.o.d" -o ${OBJECTDIR}/IO_Ports.o IO_Ports.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Robot_Main.o: Robot_Main.c  .generated_files/flags/default/bcdfe866fa847f1928ab984ee729154b16e2bbef .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Robot_Main.o.d 
	@${RM} ${OBJECTDIR}/Robot_Main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/Robot_Main.o.d" -o ${OBJECTDIR}/Robot_Main.o Robot_Main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/StepperDriver.o: StepperDriver.c  .generated_files/flags/default/7fe88ae6f2f9cf647b6a05f3c3a0e2b7cc0d3de3 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/StepperDriver.o.d 
	@${RM} ${OBJECTDIR}/StepperDriver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/StepperDriver.o.d" -o ${OBJECTDIR}/StepperDriver.o StepperDriver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ping.o: ping.c  .generated_files/flags/default/fefac301b8586f572ac2cbbf51d52e8fe3eea641 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ping.o.d 
	@${RM} ${OBJECTDIR}/ping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ping.o.d" -o ${OBJECTDIR}/ping.o ping.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/serial.o: serial.c  .generated_files/flags/default/65cb748cc370959e2e8dcf1ffb5c93f12603eb58 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/serial.o.d 
	@${RM} ${OBJECTDIR}/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/serial.o.d" -o ${OBJECTDIR}/serial.o serial.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/timers.o: timers.c  .generated_files/flags/default/4d12abb33ee4248cf8e0699c7fe68eb8153a9ea7 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timers.o.d 
	@${RM} ${OBJECTDIR}/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/timers.o.d" -o ${OBJECTDIR}/timers.o timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HSM_MovementSub.o: HSM_MovementSub.c  .generated_files/flags/default/51933a36282da1de2b2efac406c1f168ee76f5f1 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HSM_MovementSub.o.d 
	@${RM} ${OBJECTDIR}/HSM_MovementSub.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/HSM_MovementSub.o.d" -o ${OBJECTDIR}/HSM_MovementSub.o HSM_MovementSub.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Bumpers.o: Bumpers.c  .generated_files/flags/default/257f53e4f75976392de156bb33e6e347be940143 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Bumpers.o.d 
	@${RM} ${OBJECTDIR}/Bumpers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/Bumpers.o.d" -o ${OBJECTDIR}/Bumpers.o Bumpers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HSM_AvoidObstacleSub.o: HSM_AvoidObstacleSub.c  .generated_files/flags/default/6a9d8d128e9b01e997925a61eb1625ed9bdd0e2d .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HSM_AvoidObstacleSub.o.d 
	@${RM} ${OBJECTDIR}/HSM_AvoidObstacleSub.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/HSM_AvoidObstacleSub.o.d" -o ${OBJECTDIR}/HSM_AvoidObstacleSub.o HSM_AvoidObstacleSub.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HSM_ReloadingSub.o: HSM_ReloadingSub.c  .generated_files/flags/default/c365c1d02c25d8c001f5fbd73341c1dd0e6c62d2 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HSM_ReloadingSub.o.d 
	@${RM} ${OBJECTDIR}/HSM_ReloadingSub.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/HSM_ReloadingSub.o.d" -o ${OBJECTDIR}/HSM_ReloadingSub.o HSM_ReloadingSub.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/AD.o: AD.c  .generated_files/flags/default/aad265acb3f86c72a918cb1252098f5f02b76f3 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/AD.o.d 
	@${RM} ${OBJECTDIR}/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/AD.o.d" -o ${OBJECTDIR}/AD.o AD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/BOARD.o: BOARD.c  .generated_files/flags/default/70e578c1bb9e81fba5c56bc897e0ec085860d492 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BOARD.o.d 
	@${RM} ${OBJECTDIR}/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/BOARD.o.d" -o ${OBJECTDIR}/BOARD.o BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_CheckEvents.o: ES_CheckEvents.c  .generated_files/flags/default/3bd231c62a495072378ff58a25fe6439e022a817 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/ES_CheckEvents.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ES_CheckEvents.o.d" -o ${OBJECTDIR}/ES_CheckEvents.o ES_CheckEvents.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_Framework.o: ES_Framework.c  .generated_files/flags/default/4e31dd13a9e6e8607d4ad12e7f83d77e288ad81b .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/ES_Framework.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ES_Framework.o.d" -o ${OBJECTDIR}/ES_Framework.o ES_Framework.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_KeyboardInput.o: ES_KeyboardInput.c  .generated_files/flags/default/1f19ef0f3d57908f93e042f0b0d031378c9a9f .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/ES_KeyboardInput.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/ES_KeyboardInput.o ES_KeyboardInput.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_PostList.o: ES_PostList.c  .generated_files/flags/default/845e32a0207695e9ea2e52035fef4036376fcada .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/ES_PostList.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ES_PostList.o.d" -o ${OBJECTDIR}/ES_PostList.o ES_PostList.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_Queue.o: ES_Queue.c  .generated_files/flags/default/8f29136f8b74c61791eb2c459d3efe92f88932d7 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/ES_Queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ES_Queue.o.d" -o ${OBJECTDIR}/ES_Queue.o ES_Queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_TattleTale.o: ES_TattleTale.c  .generated_files/flags/default/be8b28c5e9e5a6452ee67d7e2ba621a965b08511 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/ES_TattleTale.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ES_TattleTale.o.d" -o ${OBJECTDIR}/ES_TattleTale.o ES_TattleTale.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_Timers.o: ES_Timers.c  .generated_files/flags/default/5ec45ced7b9aa63d25c0e789cbba38f62da01552 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/ES_Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ES_Timers.o.d" -o ${OBJECTDIR}/ES_Timers.o ES_Timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/EventChecker.o: EventChecker.c  .generated_files/flags/default/8cb1a20ee74353db22f2693b20e9a65bcc67727e .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventChecker.o.d 
	@${RM} ${OBJECTDIR}/EventChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/EventChecker.o.d" -o ${OBJECTDIR}/EventChecker.o EventChecker.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HSM_LaunchingSub.o: HSM_LaunchingSub.c  .generated_files/flags/default/9b10c9865bdc4478afb19b68893bcdac36f74d8b .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HSM_LaunchingSub.o.d 
	@${RM} ${OBJECTDIR}/HSM_LaunchingSub.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/HSM_LaunchingSub.o.d" -o ${OBJECTDIR}/HSM_LaunchingSub.o HSM_LaunchingSub.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HSM_Robot.o: HSM_Robot.c  .generated_files/flags/default/bb64c435dbcab7d65f77117d2cd58fbad7bc9a12 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HSM_Robot.o.d 
	@${RM} ${OBJECTDIR}/HSM_Robot.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/HSM_Robot.o.d" -o ${OBJECTDIR}/HSM_Robot.o HSM_Robot.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/IO_Ports.o: IO_Ports.c  .generated_files/flags/default/b73f6e8f47e8cae9a01b0514016200aed2dff7fe .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/IO_Ports.o.d" -o ${OBJECTDIR}/IO_Ports.o IO_Ports.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Robot_Main.o: Robot_Main.c  .generated_files/flags/default/c75c35494e8fa37dd1f69c59e75a37796c73cd8a .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Robot_Main.o.d 
	@${RM} ${OBJECTDIR}/Robot_Main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/Robot_Main.o.d" -o ${OBJECTDIR}/Robot_Main.o Robot_Main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/StepperDriver.o: StepperDriver.c  .generated_files/flags/default/f5c250b5106ddafb2f16bcb3eeeec3f739673bed .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/StepperDriver.o.d 
	@${RM} ${OBJECTDIR}/StepperDriver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/StepperDriver.o.d" -o ${OBJECTDIR}/StepperDriver.o StepperDriver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ping.o: ping.c  .generated_files/flags/default/c757953a5de81ee1bdc907655de9f57c3552337b .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ping.o.d 
	@${RM} ${OBJECTDIR}/ping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/ping.o.d" -o ${OBJECTDIR}/ping.o ping.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/serial.o: serial.c  .generated_files/flags/default/2f0a28cfdb6f36fdb29c95c4ffdb3be1d92499d5 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/serial.o.d 
	@${RM} ${OBJECTDIR}/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/serial.o.d" -o ${OBJECTDIR}/serial.o serial.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/timers.o: timers.c  .generated_files/flags/default/66c52bc550f89693e2fa48f87f12679df0256599 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timers.o.d 
	@${RM} ${OBJECTDIR}/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/timers.o.d" -o ${OBJECTDIR}/timers.o timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HSM_MovementSub.o: HSM_MovementSub.c  .generated_files/flags/default/f1b3b8f385db0a430532274a9712f30586c9161e .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HSM_MovementSub.o.d 
	@${RM} ${OBJECTDIR}/HSM_MovementSub.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/HSM_MovementSub.o.d" -o ${OBJECTDIR}/HSM_MovementSub.o HSM_MovementSub.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Bumpers.o: Bumpers.c  .generated_files/flags/default/a873580524668c82183735a2401e4ce73410ed6d .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Bumpers.o.d 
	@${RM} ${OBJECTDIR}/Bumpers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/Bumpers.o.d" -o ${OBJECTDIR}/Bumpers.o Bumpers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HSM_AvoidObstacleSub.o: HSM_AvoidObstacleSub.c  .generated_files/flags/default/63b5781f9f8807c5afbfba61d58bca07bce7735d .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HSM_AvoidObstacleSub.o.d 
	@${RM} ${OBJECTDIR}/HSM_AvoidObstacleSub.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/HSM_AvoidObstacleSub.o.d" -o ${OBJECTDIR}/HSM_AvoidObstacleSub.o HSM_AvoidObstacleSub.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HSM_ReloadingSub.o: HSM_ReloadingSub.c  .generated_files/flags/default/399750c13acfd16dec9d02c4ab5fe4d2ed8b3df8 .generated_files/flags/default/5c6b98b8923ce30ee24d180da03fe6585119c89b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HSM_ReloadingSub.o.d 
	@${RM} ${OBJECTDIR}/HSM_ReloadingSub.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/HSM_ReloadingSub.o.d" -o ${OBJECTDIR}/HSM_ReloadingSub.o HSM_ReloadingSub.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/ECE118FinalProject_NearFinal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../../ECE118/bootloader320.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/ECE118FinalProject_NearFinal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=10,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/ECE118FinalProject_NearFinal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../../ECE118/bootloader320.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/ECE118FinalProject_NearFinal.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=10,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/ECE118FinalProject_NearFinal.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
