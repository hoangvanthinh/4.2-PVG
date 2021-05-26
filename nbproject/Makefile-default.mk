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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/drivers/i2c_types.c mcc_generated_files/drivers/i2c_master.c mcc_generated_files/drivers/i2c_simple_master.c mcc_generated_files/spi1.c mcc_generated_files/reset.c mcc_generated_files/system.c mcc_generated_files/clock.c mcc_generated_files/traps.c mcc_generated_files/interrupt_manager.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/tmr2.c mcc_generated_files/uart1.c mcc_generated_files/uart2.c mcc_generated_files/EEPROM3_example.c mcc_generated_files/EEPROM3_driver.c mcc_generated_files/i2c2_driver.c Modbus/ModbusTCPClient.c Modbus/ModbusRTU_Slave.c Framework/tcpip/src/common/arc4.c Framework/tcpip/src/common/big_int.c Framework/tcpip/src/common/delay.c Framework/tcpip/src/common/hashes.c Framework/tcpip/src/common/helpers.c Framework/tcpip/src/common/mpfs2.c Framework/tcpip/src/common/rsa.c Framework/tcpip/src/common/stack_task.c Framework/tcpip/src/common/tick.c Framework/tcpip/src/common/big_int_helper.S Framework/tcpip/src/arp.c Framework/tcpip/src/custom_ssl_cert.c Framework/tcpip/src/ddns.c Framework/tcpip/src/dhcp_client.c Framework/tcpip/src/dhcp_server.c Framework/tcpip/src/dns_client.c Framework/tcpip/src/dns_server.c Framework/tcpip/src/enc28j60.c Framework/tcpip/src/FTP.c Framework/tcpip/src/http2.c Framework/tcpip/src/icmp.c Framework/tcpip/src/ip.c Framework/tcpip/src/nbns.c Framework/tcpip/src/random.c Framework/tcpip/src/smtp.c Framework/tcpip/src/ssl.c Framework/tcpip/src/tcp.c Framework/tcpip/src/telnet.c Framework/tcpip/src/udp.c Framework/tcpip/src/announce.c main.c user.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o ${OBJECTDIR}/mcc_generated_files/spi1.o ${OBJECTDIR}/mcc_generated_files/reset.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/tmr2.o ${OBJECTDIR}/mcc_generated_files/uart1.o ${OBJECTDIR}/mcc_generated_files/uart2.o ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o ${OBJECTDIR}/Modbus/ModbusTCPClient.o ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o ${OBJECTDIR}/Framework/tcpip/src/common/delay.o ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o ${OBJECTDIR}/Framework/tcpip/src/common/tick.o ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o ${OBJECTDIR}/Framework/tcpip/src/arp.o ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o ${OBJECTDIR}/Framework/tcpip/src/ddns.o ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o ${OBJECTDIR}/Framework/tcpip/src/dns_client.o ${OBJECTDIR}/Framework/tcpip/src/dns_server.o ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o ${OBJECTDIR}/Framework/tcpip/src/FTP.o ${OBJECTDIR}/Framework/tcpip/src/http2.o ${OBJECTDIR}/Framework/tcpip/src/icmp.o ${OBJECTDIR}/Framework/tcpip/src/ip.o ${OBJECTDIR}/Framework/tcpip/src/nbns.o ${OBJECTDIR}/Framework/tcpip/src/random.o ${OBJECTDIR}/Framework/tcpip/src/smtp.o ${OBJECTDIR}/Framework/tcpip/src/ssl.o ${OBJECTDIR}/Framework/tcpip/src/tcp.o ${OBJECTDIR}/Framework/tcpip/src/telnet.o ${OBJECTDIR}/Framework/tcpip/src/udp.o ${OBJECTDIR}/Framework/tcpip/src/announce.o ${OBJECTDIR}/main.o ${OBJECTDIR}/user.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d ${OBJECTDIR}/mcc_generated_files/spi1.o.d ${OBJECTDIR}/mcc_generated_files/reset.o.d ${OBJECTDIR}/mcc_generated_files/system.o.d ${OBJECTDIR}/mcc_generated_files/clock.o.d ${OBJECTDIR}/mcc_generated_files/traps.o.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d ${OBJECTDIR}/mcc_generated_files/mcc.o.d ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d ${OBJECTDIR}/mcc_generated_files/tmr2.o.d ${OBJECTDIR}/mcc_generated_files/uart1.o.d ${OBJECTDIR}/mcc_generated_files/uart2.o.d ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o.d ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o.d ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o.d ${OBJECTDIR}/Modbus/ModbusTCPClient.o.d ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o.d ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o.d ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o.d ${OBJECTDIR}/Framework/tcpip/src/common/delay.o.d ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o.d ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o.d ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o.d ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o.d ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o.d ${OBJECTDIR}/Framework/tcpip/src/common/tick.o.d ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o.d ${OBJECTDIR}/Framework/tcpip/src/arp.o.d ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o.d ${OBJECTDIR}/Framework/tcpip/src/ddns.o.d ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o.d ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o.d ${OBJECTDIR}/Framework/tcpip/src/dns_client.o.d ${OBJECTDIR}/Framework/tcpip/src/dns_server.o.d ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o.d ${OBJECTDIR}/Framework/tcpip/src/FTP.o.d ${OBJECTDIR}/Framework/tcpip/src/http2.o.d ${OBJECTDIR}/Framework/tcpip/src/icmp.o.d ${OBJECTDIR}/Framework/tcpip/src/ip.o.d ${OBJECTDIR}/Framework/tcpip/src/nbns.o.d ${OBJECTDIR}/Framework/tcpip/src/random.o.d ${OBJECTDIR}/Framework/tcpip/src/smtp.o.d ${OBJECTDIR}/Framework/tcpip/src/ssl.o.d ${OBJECTDIR}/Framework/tcpip/src/tcp.o.d ${OBJECTDIR}/Framework/tcpip/src/telnet.o.d ${OBJECTDIR}/Framework/tcpip/src/udp.o.d ${OBJECTDIR}/Framework/tcpip/src/announce.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/user.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o ${OBJECTDIR}/mcc_generated_files/spi1.o ${OBJECTDIR}/mcc_generated_files/reset.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/tmr2.o ${OBJECTDIR}/mcc_generated_files/uart1.o ${OBJECTDIR}/mcc_generated_files/uart2.o ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o ${OBJECTDIR}/Modbus/ModbusTCPClient.o ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o ${OBJECTDIR}/Framework/tcpip/src/common/delay.o ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o ${OBJECTDIR}/Framework/tcpip/src/common/tick.o ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o ${OBJECTDIR}/Framework/tcpip/src/arp.o ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o ${OBJECTDIR}/Framework/tcpip/src/ddns.o ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o ${OBJECTDIR}/Framework/tcpip/src/dns_client.o ${OBJECTDIR}/Framework/tcpip/src/dns_server.o ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o ${OBJECTDIR}/Framework/tcpip/src/FTP.o ${OBJECTDIR}/Framework/tcpip/src/http2.o ${OBJECTDIR}/Framework/tcpip/src/icmp.o ${OBJECTDIR}/Framework/tcpip/src/ip.o ${OBJECTDIR}/Framework/tcpip/src/nbns.o ${OBJECTDIR}/Framework/tcpip/src/random.o ${OBJECTDIR}/Framework/tcpip/src/smtp.o ${OBJECTDIR}/Framework/tcpip/src/ssl.o ${OBJECTDIR}/Framework/tcpip/src/tcp.o ${OBJECTDIR}/Framework/tcpip/src/telnet.o ${OBJECTDIR}/Framework/tcpip/src/udp.o ${OBJECTDIR}/Framework/tcpip/src/announce.o ${OBJECTDIR}/main.o ${OBJECTDIR}/user.o

# Source Files
SOURCEFILES=mcc_generated_files/drivers/i2c_types.c mcc_generated_files/drivers/i2c_master.c mcc_generated_files/drivers/i2c_simple_master.c mcc_generated_files/spi1.c mcc_generated_files/reset.c mcc_generated_files/system.c mcc_generated_files/clock.c mcc_generated_files/traps.c mcc_generated_files/interrupt_manager.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/tmr2.c mcc_generated_files/uart1.c mcc_generated_files/uart2.c mcc_generated_files/EEPROM3_example.c mcc_generated_files/EEPROM3_driver.c mcc_generated_files/i2c2_driver.c Modbus/ModbusTCPClient.c Modbus/ModbusRTU_Slave.c Framework/tcpip/src/common/arc4.c Framework/tcpip/src/common/big_int.c Framework/tcpip/src/common/delay.c Framework/tcpip/src/common/hashes.c Framework/tcpip/src/common/helpers.c Framework/tcpip/src/common/mpfs2.c Framework/tcpip/src/common/rsa.c Framework/tcpip/src/common/stack_task.c Framework/tcpip/src/common/tick.c Framework/tcpip/src/common/big_int_helper.S Framework/tcpip/src/arp.c Framework/tcpip/src/custom_ssl_cert.c Framework/tcpip/src/ddns.c Framework/tcpip/src/dhcp_client.c Framework/tcpip/src/dhcp_server.c Framework/tcpip/src/dns_client.c Framework/tcpip/src/dns_server.c Framework/tcpip/src/enc28j60.c Framework/tcpip/src/FTP.c Framework/tcpip/src/http2.c Framework/tcpip/src/icmp.c Framework/tcpip/src/ip.c Framework/tcpip/src/nbns.c Framework/tcpip/src/random.c Framework/tcpip/src/smtp.c Framework/tcpip/src/ssl.c Framework/tcpip/src/tcp.c Framework/tcpip/src/telnet.c Framework/tcpip/src/udp.c Framework/tcpip/src/announce.c main.c user.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP512MU810
MP_LINKER_FILE_OPTION=,--script=p33EP512MU810.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o: mcc_generated_files/drivers/i2c_types.c  .generated_files/bfbe5879d72064d90a8ab0e768db1c5a76b0b883.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/drivers/i2c_types.c  -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o: mcc_generated_files/drivers/i2c_master.c  .generated_files/21fdff9578f36964c498ef6964e001259fe7e226.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/drivers/i2c_master.c  -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o: mcc_generated_files/drivers/i2c_simple_master.c  .generated_files/c8c7c6056113613f6d6069e9900ee12b8aed085f.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/drivers/i2c_simple_master.c  -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/spi1.o: mcc_generated_files/spi1.c  .generated_files/6132f2f58cfc44547f4be523bbf02bb9f9a88dff.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/spi1.c  -o ${OBJECTDIR}/mcc_generated_files/spi1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/spi1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/reset.o: mcc_generated_files/reset.c  .generated_files/c63ee80afdd3acbb1198979eb01c3ec6e9d292fb.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/reset.c  -o ${OBJECTDIR}/mcc_generated_files/reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/reset.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/9f3ec120cf12c82fca26005c1260530254f99b90.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/324a46cac2281a5e3742607fff9d26439d4c0436.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/6cc2837371c3ca49c09f183f662a8c47e8b09987.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/823f4f2ef5aef0b57decac42efe85de480a13aa4.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/17a19c8087cc86eb8747314489db489b39cdb98e.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/98160828ccb86f8c489fdb4b857bac807633c471.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/tmr2.o: mcc_generated_files/tmr2.c  .generated_files/5599476baa1b73133e093e5678631a2740bf785a.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr2.c  -o ${OBJECTDIR}/mcc_generated_files/tmr2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr2.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/uart1.o: mcc_generated_files/uart1.c  .generated_files/4a6613e69eec66b17a45d57e12ac16b74a37c98a.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart1.c  -o ${OBJECTDIR}/mcc_generated_files/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/uart2.o: mcc_generated_files/uart2.c  .generated_files/9dda06033ee77bcf4464eeabb444f13c4fa054c5.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart2.c  -o ${OBJECTDIR}/mcc_generated_files/uart2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart2.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o: mcc_generated_files/EEPROM3_example.c  .generated_files/c96362b43f2fff1c3708e421a8ff26dcb7ccda69.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/EEPROM3_example.c  -o ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o: mcc_generated_files/EEPROM3_driver.c  .generated_files/71c30bc9b8c0e1fce125b71732f2554560ba4f95.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/EEPROM3_driver.c  -o ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/i2c2_driver.o: mcc_generated_files/i2c2_driver.c  .generated_files/4bdb52c027eaf826e348daa1b1fbfcfb4f52ac6b.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/i2c2_driver.c  -o ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/i2c2_driver.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Modbus/ModbusTCPClient.o: Modbus/ModbusTCPClient.c  .generated_files/bf387d4cf512ff90d6d76201b861a3ce7eaaf64c.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Modbus" 
	@${RM} ${OBJECTDIR}/Modbus/ModbusTCPClient.o.d 
	@${RM} ${OBJECTDIR}/Modbus/ModbusTCPClient.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Modbus/ModbusTCPClient.c  -o ${OBJECTDIR}/Modbus/ModbusTCPClient.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Modbus/ModbusTCPClient.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Modbus/ModbusRTU_Slave.o: Modbus/ModbusRTU_Slave.c  .generated_files/ee56b701cd22e358d41b43b566bc8651681cf5b0.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Modbus" 
	@${RM} ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o.d 
	@${RM} ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Modbus/ModbusRTU_Slave.c  -o ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Modbus/ModbusRTU_Slave.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/arc4.o: Framework/tcpip/src/common/arc4.c  .generated_files/67a548d00b4656f8a44f9fd2833ebc4479783ce0.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/arc4.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/arc4.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/big_int.o: Framework/tcpip/src/common/big_int.c  .generated_files/d538bbfa700e98474f6968cf4afd89866ecc52b4.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/big_int.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/big_int.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/delay.o: Framework/tcpip/src/common/delay.c  .generated_files/78385b78a0b623ff495695332826af31ba1362b7.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/delay.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/delay.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/delay.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/hashes.o: Framework/tcpip/src/common/hashes.c  .generated_files/13ccb2d21028f1073e3bafa03bbfa239851af46b.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/hashes.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/hashes.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/helpers.o: Framework/tcpip/src/common/helpers.c  .generated_files/8e58ca2bc237004d2f597325c2a7b457a43f007d.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/helpers.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/helpers.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o: Framework/tcpip/src/common/mpfs2.c  .generated_files/633e4b92211d7d4d4284ade94a0da0a90fcef4a0.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/mpfs2.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/rsa.o: Framework/tcpip/src/common/rsa.c  .generated_files/95bddf93fb0673719847b2d2f586825fa6e5e061.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/rsa.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/rsa.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o: Framework/tcpip/src/common/stack_task.c  .generated_files/7dd06e8acb34eb46bc6ee9c41ea1a5bf102a53f1.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/stack_task.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/tick.o: Framework/tcpip/src/common/tick.c  .generated_files/b408b52b195a7c32a87908f94ad48ac5a795deda.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/tick.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/tick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/tick.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/tick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/tick.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/arp.o: Framework/tcpip/src/arp.c  .generated_files/4d5e3782ac441ab479d6651c228f050a61a2985d.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/arp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/arp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/arp.c  -o ${OBJECTDIR}/Framework/tcpip/src/arp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/arp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o: Framework/tcpip/src/custom_ssl_cert.c  .generated_files/53660a5a2a483012c994f36dc6aec610ba7de7ee.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/custom_ssl_cert.c  -o ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/ddns.o: Framework/tcpip/src/ddns.c  .generated_files/2bae7f46fe0ab8ccc46043e5165e87ac611da4ef.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ddns.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ddns.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/ddns.c  -o ${OBJECTDIR}/Framework/tcpip/src/ddns.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/ddns.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o: Framework/tcpip/src/dhcp_client.c  .generated_files/d2f9540e6663059a5366db7e1a41cfa504813444.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dhcp_client.c  -o ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o: Framework/tcpip/src/dhcp_server.c  .generated_files/d1edb93f709f4f478429537bfe8db5f663fb927c.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dhcp_server.c  -o ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/dns_client.o: Framework/tcpip/src/dns_client.c  .generated_files/9bbb04d16f7b96560183f87daa1c559e8321ccdb.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_client.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dns_client.c  -o ${OBJECTDIR}/Framework/tcpip/src/dns_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dns_client.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/dns_server.o: Framework/tcpip/src/dns_server.c  .generated_files/901f0be53efe2a5ee644f7ebc92b766ab311e7a9.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_server.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_server.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dns_server.c  -o ${OBJECTDIR}/Framework/tcpip/src/dns_server.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dns_server.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/enc28j60.o: Framework/tcpip/src/enc28j60.c  .generated_files/9cfbef04481078c9e816092625dd338cff9c5477.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/enc28j60.c  -o ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/enc28j60.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/FTP.o: Framework/tcpip/src/FTP.c  .generated_files/c5dc3e9948ba3eb621b2effbed60838a5c33b9b2.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/FTP.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/FTP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/FTP.c  -o ${OBJECTDIR}/Framework/tcpip/src/FTP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/FTP.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/http2.o: Framework/tcpip/src/http2.c  .generated_files/a67d9f9872b35c73b4c47a0632325226e736039a.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/http2.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/http2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/http2.c  -o ${OBJECTDIR}/Framework/tcpip/src/http2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/http2.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/icmp.o: Framework/tcpip/src/icmp.c  .generated_files/bc22d4b406ba413d38eb5938abbc2afe61201571.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/icmp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/icmp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/icmp.c  -o ${OBJECTDIR}/Framework/tcpip/src/icmp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/icmp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/ip.o: Framework/tcpip/src/ip.c  .generated_files/5aabb27542ee6c39dcb25a47277e0d9562efbf08.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ip.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ip.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/ip.c  -o ${OBJECTDIR}/Framework/tcpip/src/ip.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/ip.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/nbns.o: Framework/tcpip/src/nbns.c  .generated_files/31110b1309c4cff20f5e276b698fe019e472d54f.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/nbns.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/nbns.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/nbns.c  -o ${OBJECTDIR}/Framework/tcpip/src/nbns.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/nbns.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/random.o: Framework/tcpip/src/random.c  .generated_files/ab18f6f751fb561949bb9ebffd13f81b21bd93ad.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/random.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/random.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/random.c  -o ${OBJECTDIR}/Framework/tcpip/src/random.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/random.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/smtp.o: Framework/tcpip/src/smtp.c  .generated_files/1ebeb955107d8c40908648f2ae1154acfa31504d.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/smtp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/smtp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/smtp.c  -o ${OBJECTDIR}/Framework/tcpip/src/smtp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/smtp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/ssl.o: Framework/tcpip/src/ssl.c  .generated_files/ad466cd86ab90484438b4a4534f0bd5fd5267d24.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ssl.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ssl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/ssl.c  -o ${OBJECTDIR}/Framework/tcpip/src/ssl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/ssl.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/tcp.o: Framework/tcpip/src/tcp.c  .generated_files/647959b0525780cf7540596971d2e5a04d907fcc.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/tcp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/tcp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/tcp.c  -o ${OBJECTDIR}/Framework/tcpip/src/tcp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/tcp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/telnet.o: Framework/tcpip/src/telnet.c  .generated_files/9ab5b50506f3cdd469cdf1b7ad5709907dafdbc5.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/telnet.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/telnet.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/telnet.c  -o ${OBJECTDIR}/Framework/tcpip/src/telnet.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/telnet.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/udp.o: Framework/tcpip/src/udp.c  .generated_files/ec6168e2930b50a140df5b3bd806f8674085df.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/udp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/udp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/udp.c  -o ${OBJECTDIR}/Framework/tcpip/src/udp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/udp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/announce.o: Framework/tcpip/src/announce.c  .generated_files/66f68d49a7b6035097c2d4ef901303dc14b94cb.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/announce.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/announce.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/announce.c  -o ${OBJECTDIR}/Framework/tcpip/src/announce.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/announce.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/main.o: main.c  .generated_files/9812e1d46b3c5e34613a7503d363aa7794078cce.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/user.o: user.c  .generated_files/1dc34665544377f66cff0ec53fd976dd074449e9.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${RM} ${OBJECTDIR}/user.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  user.c  -o ${OBJECTDIR}/user.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/user.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
else
${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o: mcc_generated_files/drivers/i2c_types.c  .generated_files/bf2aa1f26554ca4359bdd3ad3ae0525db5cd193d.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/drivers/i2c_types.c  -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o: mcc_generated_files/drivers/i2c_master.c  .generated_files/9c6cdbe1402626d14ac1266dea9e6faf93b89116.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/drivers/i2c_master.c  -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o: mcc_generated_files/drivers/i2c_simple_master.c  .generated_files/70d5b4a97c6c0bfa6b1b524f38b09c269d9441c7.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/drivers/i2c_simple_master.c  -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/spi1.o: mcc_generated_files/spi1.c  .generated_files/bcc9407459f38cc65b54970dc4af7b00602170a0.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/spi1.c  -o ${OBJECTDIR}/mcc_generated_files/spi1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/spi1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/reset.o: mcc_generated_files/reset.c  .generated_files/afc3a3930029d601e21c0a5ae44549c7d221db7f.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/reset.c  -o ${OBJECTDIR}/mcc_generated_files/reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/reset.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/39e8b070a0521b6a0428d03d73af51ed4b9f6d99.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/8832d71de5fc6d7e3fc887686d92d71232b2184e.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/79df1a2141db3767dce38e6b821d86e6b38dffa7.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/6dd6dfbdb32cbd2c4c3d90225716b43454c43b3a.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/b166e07cd7fb6d2e9ea7f0ae4386da1b1be11dc7.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/ff4102ed6658d550a00110804302e91cf6756779.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/tmr2.o: mcc_generated_files/tmr2.c  .generated_files/4ab8d12b0e0232cd2958f596c11dc70c15cd5022.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr2.c  -o ${OBJECTDIR}/mcc_generated_files/tmr2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/uart1.o: mcc_generated_files/uart1.c  .generated_files/45a88cae0d35fe10b701dfa4eb11b49e9c277985.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart1.c  -o ${OBJECTDIR}/mcc_generated_files/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/uart2.o: mcc_generated_files/uart2.c  .generated_files/46315d193192e4fa45ccf9ff100893221fe71f1.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart2.c  -o ${OBJECTDIR}/mcc_generated_files/uart2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o: mcc_generated_files/EEPROM3_example.c  .generated_files/34cfb7b4eabe3eb8946c1716c8cd92a8d872a3aa.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/EEPROM3_example.c  -o ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o: mcc_generated_files/EEPROM3_driver.c  .generated_files/eda63dd601188d6b3889b08a9360cc2e92c3574c.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/EEPROM3_driver.c  -o ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/i2c2_driver.o: mcc_generated_files/i2c2_driver.c  .generated_files/4707bae32e86fefefa1ac5403df6ee5304ddfc53.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/i2c2_driver.c  -o ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/i2c2_driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Modbus/ModbusTCPClient.o: Modbus/ModbusTCPClient.c  .generated_files/3ba92e60b24d60611f9d3b0d6b4ed9f724c183b7.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Modbus" 
	@${RM} ${OBJECTDIR}/Modbus/ModbusTCPClient.o.d 
	@${RM} ${OBJECTDIR}/Modbus/ModbusTCPClient.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Modbus/ModbusTCPClient.c  -o ${OBJECTDIR}/Modbus/ModbusTCPClient.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Modbus/ModbusTCPClient.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Modbus/ModbusRTU_Slave.o: Modbus/ModbusRTU_Slave.c  .generated_files/47ecf671e8cd4f926f9744e8633511b6ee8664e5.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Modbus" 
	@${RM} ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o.d 
	@${RM} ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Modbus/ModbusRTU_Slave.c  -o ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Modbus/ModbusRTU_Slave.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/arc4.o: Framework/tcpip/src/common/arc4.c  .generated_files/d24899eb5a5aeb8aaa5c917b95e644f1a9735092.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/arc4.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/arc4.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/big_int.o: Framework/tcpip/src/common/big_int.c  .generated_files/acc0cac83d139f88d8484dfd4e893d7f5961b291.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/big_int.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/big_int.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/delay.o: Framework/tcpip/src/common/delay.c  .generated_files/655512b922d1b257dccc337e3572d6664bc9c0bc.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/delay.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/delay.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/delay.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/hashes.o: Framework/tcpip/src/common/hashes.c  .generated_files/15c264692fe8343824dedb71765cd393974c3a7c.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/hashes.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/hashes.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/helpers.o: Framework/tcpip/src/common/helpers.c  .generated_files/95504e5c2039533a48fb8454b09d83933218a29e.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/helpers.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/helpers.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o: Framework/tcpip/src/common/mpfs2.c  .generated_files/75ff169ed23030e7daf0303bb0ff1d7bd8d5f93c.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/mpfs2.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/rsa.o: Framework/tcpip/src/common/rsa.c  .generated_files/1c50d90821ff64b4f17fcbc24ed3f5a6b60f0e35.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/rsa.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/rsa.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o: Framework/tcpip/src/common/stack_task.c  .generated_files/1cfac94b5baa37989fe98b4dc08a46d706399804.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/stack_task.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/common/tick.o: Framework/tcpip/src/common/tick.c  .generated_files/4e8ed7403e8964c3d9ea674948ee30c97ec2bf0a.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/tick.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/tick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/tick.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/tick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/tick.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/arp.o: Framework/tcpip/src/arp.c  .generated_files/160f4073968c10496c834b7327f4cb0febfb6cc.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/arp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/arp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/arp.c  -o ${OBJECTDIR}/Framework/tcpip/src/arp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/arp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o: Framework/tcpip/src/custom_ssl_cert.c  .generated_files/c9366fbbca93506f8c280d1bd9213cbd643c3afb.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/custom_ssl_cert.c  -o ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/ddns.o: Framework/tcpip/src/ddns.c  .generated_files/759745f38be1d6811a370080fd83bbbf896cb779.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ddns.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ddns.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/ddns.c  -o ${OBJECTDIR}/Framework/tcpip/src/ddns.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/ddns.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o: Framework/tcpip/src/dhcp_client.c  .generated_files/34e1e1c8a1e4f8f966583f92413f620e1f1a3fca.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dhcp_client.c  -o ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o: Framework/tcpip/src/dhcp_server.c  .generated_files/5d00fada5fa0241695e2630e58ab0a9cfeb2b393.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dhcp_server.c  -o ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/dns_client.o: Framework/tcpip/src/dns_client.c  .generated_files/43d052fbfc58e0f4ad060650d966de4de00a6d48.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_client.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dns_client.c  -o ${OBJECTDIR}/Framework/tcpip/src/dns_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dns_client.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/dns_server.o: Framework/tcpip/src/dns_server.c  .generated_files/3b7b2a9c4ae2b879a45405d20d1eed86d5b446da.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_server.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_server.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dns_server.c  -o ${OBJECTDIR}/Framework/tcpip/src/dns_server.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dns_server.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/enc28j60.o: Framework/tcpip/src/enc28j60.c  .generated_files/d0ffdab050fd430c5ceec5b007fd826525103040.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/enc28j60.c  -o ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/enc28j60.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/FTP.o: Framework/tcpip/src/FTP.c  .generated_files/af38618d38bb8b10a9432bf05fcd1aa4e7ce91c1.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/FTP.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/FTP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/FTP.c  -o ${OBJECTDIR}/Framework/tcpip/src/FTP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/FTP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/http2.o: Framework/tcpip/src/http2.c  .generated_files/f26dcc66f90bc2c79e82014e2ee564559601afc4.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/http2.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/http2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/http2.c  -o ${OBJECTDIR}/Framework/tcpip/src/http2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/http2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/icmp.o: Framework/tcpip/src/icmp.c  .generated_files/1ceff739e6dd9e1f9d53a621f5321c0b3ce2d45f.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/icmp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/icmp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/icmp.c  -o ${OBJECTDIR}/Framework/tcpip/src/icmp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/icmp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/ip.o: Framework/tcpip/src/ip.c  .generated_files/91a336a687ac6988bd5be677bd15ab178f865d31.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ip.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ip.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/ip.c  -o ${OBJECTDIR}/Framework/tcpip/src/ip.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/ip.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/nbns.o: Framework/tcpip/src/nbns.c  .generated_files/53246f60cf8d293d4fda15f6be071ed9869a3701.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/nbns.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/nbns.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/nbns.c  -o ${OBJECTDIR}/Framework/tcpip/src/nbns.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/nbns.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/random.o: Framework/tcpip/src/random.c  .generated_files/2319f274d2e679f5a9676d9f0beeaccfa44d4664.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/random.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/random.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/random.c  -o ${OBJECTDIR}/Framework/tcpip/src/random.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/random.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/smtp.o: Framework/tcpip/src/smtp.c  .generated_files/9fb3121d2f3183426923fdf92afdff4ffb6655e5.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/smtp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/smtp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/smtp.c  -o ${OBJECTDIR}/Framework/tcpip/src/smtp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/smtp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/ssl.o: Framework/tcpip/src/ssl.c  .generated_files/c7a38cf6c1af6558f9a75f0f5f9a2f8515677453.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ssl.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ssl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/ssl.c  -o ${OBJECTDIR}/Framework/tcpip/src/ssl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/ssl.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/tcp.o: Framework/tcpip/src/tcp.c  .generated_files/b16ef693322612b8ec3c9da19cee707e9acb35c3.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/tcp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/tcp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/tcp.c  -o ${OBJECTDIR}/Framework/tcpip/src/tcp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/tcp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/telnet.o: Framework/tcpip/src/telnet.c  .generated_files/8d58cb1493a1b5d94cdcd5e028352363c0e745d4.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/telnet.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/telnet.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/telnet.c  -o ${OBJECTDIR}/Framework/tcpip/src/telnet.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/telnet.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/udp.o: Framework/tcpip/src/udp.c  .generated_files/3a0fa23a1a5674ac96cd3069d5692f7df587820b.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/udp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/udp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/udp.c  -o ${OBJECTDIR}/Framework/tcpip/src/udp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/udp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/Framework/tcpip/src/announce.o: Framework/tcpip/src/announce.c  .generated_files/ffd66f8a2745dae92715cff3a51ae098c8266a81.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/announce.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/announce.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/announce.c  -o ${OBJECTDIR}/Framework/tcpip/src/announce.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/announce.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/main.o: main.c  .generated_files/ff6c3b7a2d2ce0c6380b17ff3cd598ecb7d8a065.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/user.o: user.c  .generated_files/e07d8841163123a8c5741cbd34ec401c9a061ae6.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${RM} ${OBJECTDIR}/user.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  user.c  -o ${OBJECTDIR}/user.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/user.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o: Framework/tcpip/src/common/big_int_helper.S  .generated_files/1aff6be1e27e19935b732824bdb637f14291a1e7.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  Framework/tcpip/src/common/big_int_helper.S  -o ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o.d"  -D__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o.asm.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST) 
	
else
${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o: Framework/tcpip/src/common/big_int_helper.S  .generated_files/46c4aa6a96bafddb7b876115f2efcdbae35738b0.flag .generated_files/bf1f80e92fa5a949fe4260b520a0a6528f89acac.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  Framework/tcpip/src/common/big_int_helper.S  -o ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o.d"  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o.asm.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
