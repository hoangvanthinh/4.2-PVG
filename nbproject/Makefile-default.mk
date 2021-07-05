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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/drivers/i2c_types.c mcc_generated_files/drivers/i2c_master.c mcc_generated_files/drivers/i2c_simple_master.c mcc_generated_files/spi1.c mcc_generated_files/reset.c mcc_generated_files/system.c mcc_generated_files/clock.c mcc_generated_files/traps.c mcc_generated_files/interrupt_manager.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/tmr2.c mcc_generated_files/uart1.c mcc_generated_files/uart2.c mcc_generated_files/EEPROM3_example.c mcc_generated_files/EEPROM3_driver.c mcc_generated_files/i2c2_driver.c Modbus/ModbusTCPClient.c Modbus/ModbusRTU_Slave.c Modbus/ModbusRTU_Master.c PV/Inverter/0_Inverter.c PV/Inverter/1_SunGrow.c PV/Weather/Weather.c PV/PV.c Framework/tcpip/src/common/arc4.c Framework/tcpip/src/common/big_int.c Framework/tcpip/src/common/delay.c Framework/tcpip/src/common/hashes.c Framework/tcpip/src/common/helpers.c Framework/tcpip/src/common/mpfs2.c Framework/tcpip/src/common/rsa.c Framework/tcpip/src/common/stack_task.c Framework/tcpip/src/common/tick.c Framework/tcpip/src/common/big_int_helper.S Framework/tcpip/src/arp.c Framework/tcpip/src/custom_ssl_cert.c Framework/tcpip/src/ddns.c Framework/tcpip/src/dhcp_client.c Framework/tcpip/src/dhcp_server.c Framework/tcpip/src/dns_client.c Framework/tcpip/src/dns_server.c Framework/tcpip/src/enc28j60.c Framework/tcpip/src/FTP.c Framework/tcpip/src/http2.c Framework/tcpip/src/icmp.c Framework/tcpip/src/ip.c Framework/tcpip/src/nbns.c Framework/tcpip/src/random.c Framework/tcpip/src/smtp.c Framework/tcpip/src/ssl.c Framework/tcpip/src/tcp.c Framework/tcpip/src/telnet.c Framework/tcpip/src/udp.c Framework/tcpip/src/announce.c main.c user.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o ${OBJECTDIR}/mcc_generated_files/spi1.o ${OBJECTDIR}/mcc_generated_files/reset.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/tmr2.o ${OBJECTDIR}/mcc_generated_files/uart1.o ${OBJECTDIR}/mcc_generated_files/uart2.o ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o ${OBJECTDIR}/Modbus/ModbusTCPClient.o ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o ${OBJECTDIR}/Modbus/ModbusRTU_Master.o ${OBJECTDIR}/PV/Inverter/0_Inverter.o ${OBJECTDIR}/PV/Inverter/1_SunGrow.o ${OBJECTDIR}/PV/Weather/Weather.o ${OBJECTDIR}/PV/PV.o ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o ${OBJECTDIR}/Framework/tcpip/src/common/delay.o ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o ${OBJECTDIR}/Framework/tcpip/src/common/tick.o ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o ${OBJECTDIR}/Framework/tcpip/src/arp.o ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o ${OBJECTDIR}/Framework/tcpip/src/ddns.o ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o ${OBJECTDIR}/Framework/tcpip/src/dns_client.o ${OBJECTDIR}/Framework/tcpip/src/dns_server.o ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o ${OBJECTDIR}/Framework/tcpip/src/FTP.o ${OBJECTDIR}/Framework/tcpip/src/http2.o ${OBJECTDIR}/Framework/tcpip/src/icmp.o ${OBJECTDIR}/Framework/tcpip/src/ip.o ${OBJECTDIR}/Framework/tcpip/src/nbns.o ${OBJECTDIR}/Framework/tcpip/src/random.o ${OBJECTDIR}/Framework/tcpip/src/smtp.o ${OBJECTDIR}/Framework/tcpip/src/ssl.o ${OBJECTDIR}/Framework/tcpip/src/tcp.o ${OBJECTDIR}/Framework/tcpip/src/telnet.o ${OBJECTDIR}/Framework/tcpip/src/udp.o ${OBJECTDIR}/Framework/tcpip/src/announce.o ${OBJECTDIR}/main.o ${OBJECTDIR}/user.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d ${OBJECTDIR}/mcc_generated_files/spi1.o.d ${OBJECTDIR}/mcc_generated_files/reset.o.d ${OBJECTDIR}/mcc_generated_files/system.o.d ${OBJECTDIR}/mcc_generated_files/clock.o.d ${OBJECTDIR}/mcc_generated_files/traps.o.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d ${OBJECTDIR}/mcc_generated_files/mcc.o.d ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d ${OBJECTDIR}/mcc_generated_files/tmr2.o.d ${OBJECTDIR}/mcc_generated_files/uart1.o.d ${OBJECTDIR}/mcc_generated_files/uart2.o.d ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o.d ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o.d ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o.d ${OBJECTDIR}/Modbus/ModbusTCPClient.o.d ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o.d ${OBJECTDIR}/Modbus/ModbusRTU_Master.o.d ${OBJECTDIR}/PV/Inverter/0_Inverter.o.d ${OBJECTDIR}/PV/Inverter/1_SunGrow.o.d ${OBJECTDIR}/PV/Weather/Weather.o.d ${OBJECTDIR}/PV/PV.o.d ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o.d ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o.d ${OBJECTDIR}/Framework/tcpip/src/common/delay.o.d ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o.d ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o.d ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o.d ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o.d ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o.d ${OBJECTDIR}/Framework/tcpip/src/common/tick.o.d ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o.d ${OBJECTDIR}/Framework/tcpip/src/arp.o.d ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o.d ${OBJECTDIR}/Framework/tcpip/src/ddns.o.d ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o.d ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o.d ${OBJECTDIR}/Framework/tcpip/src/dns_client.o.d ${OBJECTDIR}/Framework/tcpip/src/dns_server.o.d ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o.d ${OBJECTDIR}/Framework/tcpip/src/FTP.o.d ${OBJECTDIR}/Framework/tcpip/src/http2.o.d ${OBJECTDIR}/Framework/tcpip/src/icmp.o.d ${OBJECTDIR}/Framework/tcpip/src/ip.o.d ${OBJECTDIR}/Framework/tcpip/src/nbns.o.d ${OBJECTDIR}/Framework/tcpip/src/random.o.d ${OBJECTDIR}/Framework/tcpip/src/smtp.o.d ${OBJECTDIR}/Framework/tcpip/src/ssl.o.d ${OBJECTDIR}/Framework/tcpip/src/tcp.o.d ${OBJECTDIR}/Framework/tcpip/src/telnet.o.d ${OBJECTDIR}/Framework/tcpip/src/udp.o.d ${OBJECTDIR}/Framework/tcpip/src/announce.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/user.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o ${OBJECTDIR}/mcc_generated_files/spi1.o ${OBJECTDIR}/mcc_generated_files/reset.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/tmr2.o ${OBJECTDIR}/mcc_generated_files/uart1.o ${OBJECTDIR}/mcc_generated_files/uart2.o ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o ${OBJECTDIR}/Modbus/ModbusTCPClient.o ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o ${OBJECTDIR}/Modbus/ModbusRTU_Master.o ${OBJECTDIR}/PV/Inverter/0_Inverter.o ${OBJECTDIR}/PV/Inverter/1_SunGrow.o ${OBJECTDIR}/PV/Weather/Weather.o ${OBJECTDIR}/PV/PV.o ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o ${OBJECTDIR}/Framework/tcpip/src/common/delay.o ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o ${OBJECTDIR}/Framework/tcpip/src/common/tick.o ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o ${OBJECTDIR}/Framework/tcpip/src/arp.o ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o ${OBJECTDIR}/Framework/tcpip/src/ddns.o ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o ${OBJECTDIR}/Framework/tcpip/src/dns_client.o ${OBJECTDIR}/Framework/tcpip/src/dns_server.o ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o ${OBJECTDIR}/Framework/tcpip/src/FTP.o ${OBJECTDIR}/Framework/tcpip/src/http2.o ${OBJECTDIR}/Framework/tcpip/src/icmp.o ${OBJECTDIR}/Framework/tcpip/src/ip.o ${OBJECTDIR}/Framework/tcpip/src/nbns.o ${OBJECTDIR}/Framework/tcpip/src/random.o ${OBJECTDIR}/Framework/tcpip/src/smtp.o ${OBJECTDIR}/Framework/tcpip/src/ssl.o ${OBJECTDIR}/Framework/tcpip/src/tcp.o ${OBJECTDIR}/Framework/tcpip/src/telnet.o ${OBJECTDIR}/Framework/tcpip/src/udp.o ${OBJECTDIR}/Framework/tcpip/src/announce.o ${OBJECTDIR}/main.o ${OBJECTDIR}/user.o

# Source Files
SOURCEFILES=mcc_generated_files/drivers/i2c_types.c mcc_generated_files/drivers/i2c_master.c mcc_generated_files/drivers/i2c_simple_master.c mcc_generated_files/spi1.c mcc_generated_files/reset.c mcc_generated_files/system.c mcc_generated_files/clock.c mcc_generated_files/traps.c mcc_generated_files/interrupt_manager.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/tmr2.c mcc_generated_files/uart1.c mcc_generated_files/uart2.c mcc_generated_files/EEPROM3_example.c mcc_generated_files/EEPROM3_driver.c mcc_generated_files/i2c2_driver.c Modbus/ModbusTCPClient.c Modbus/ModbusRTU_Slave.c Modbus/ModbusRTU_Master.c PV/Inverter/0_Inverter.c PV/Inverter/1_SunGrow.c PV/Weather/Weather.c PV/PV.c Framework/tcpip/src/common/arc4.c Framework/tcpip/src/common/big_int.c Framework/tcpip/src/common/delay.c Framework/tcpip/src/common/hashes.c Framework/tcpip/src/common/helpers.c Framework/tcpip/src/common/mpfs2.c Framework/tcpip/src/common/rsa.c Framework/tcpip/src/common/stack_task.c Framework/tcpip/src/common/tick.c Framework/tcpip/src/common/big_int_helper.S Framework/tcpip/src/arp.c Framework/tcpip/src/custom_ssl_cert.c Framework/tcpip/src/ddns.c Framework/tcpip/src/dhcp_client.c Framework/tcpip/src/dhcp_server.c Framework/tcpip/src/dns_client.c Framework/tcpip/src/dns_server.c Framework/tcpip/src/enc28j60.c Framework/tcpip/src/FTP.c Framework/tcpip/src/http2.c Framework/tcpip/src/icmp.c Framework/tcpip/src/ip.c Framework/tcpip/src/nbns.c Framework/tcpip/src/random.c Framework/tcpip/src/smtp.c Framework/tcpip/src/ssl.c Framework/tcpip/src/tcp.c Framework/tcpip/src/telnet.c Framework/tcpip/src/udp.c Framework/tcpip/src/announce.c main.c user.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP512MU810
MP_LINKER_FILE_OPTION=,--script=p33EP512MU810.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o: mcc_generated_files/drivers/i2c_types.c  .generated_files/2b0caa12ca3a961434e9ef513078f76095dcebd.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/drivers/i2c_types.c  -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o: mcc_generated_files/drivers/i2c_master.c  .generated_files/72c2d2daf38eda3175f13b11de849e6ea6cfc5dc.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/drivers/i2c_master.c  -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o: mcc_generated_files/drivers/i2c_simple_master.c  .generated_files/e2dfcfb9671a0c17ce831eec14d600bc45130882.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/drivers/i2c_simple_master.c  -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/spi1.o: mcc_generated_files/spi1.c  .generated_files/565c2b83b8f04ea2272430ce3dab0d496987bdca.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/spi1.c  -o ${OBJECTDIR}/mcc_generated_files/spi1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/spi1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/reset.o: mcc_generated_files/reset.c  .generated_files/39c848fec85fbd179972fa0ea8e63d71566e8dd3.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/reset.c  -o ${OBJECTDIR}/mcc_generated_files/reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/reset.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/e79e256bda6bc57be9ba6b25d3ba744e2a459123.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/c332ce556973c1792cdcbbee3cea00923ef5235a.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/4a964da82b859264f24eaa9b67dcbedf9a7aa106.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/6c25e5a941d8ad675b164da0ed6ef3818a20c07c.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/3ae43ba06df141bf34f78fc0a82f7853a56e69a7.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/7a72b4bf541df420904b658a262411cf57677433.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/tmr2.o: mcc_generated_files/tmr2.c  .generated_files/3c6c4ba989f98d13fd47a4993630718aedb61078.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr2.c  -o ${OBJECTDIR}/mcc_generated_files/tmr2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr2.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/uart1.o: mcc_generated_files/uart1.c  .generated_files/a5775a26e5e35913e05037f5bccf1dacc640cec5.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart1.c  -o ${OBJECTDIR}/mcc_generated_files/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/uart2.o: mcc_generated_files/uart2.c  .generated_files/387ee2c7040cb449186108614ca950514a901b8f.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart2.c  -o ${OBJECTDIR}/mcc_generated_files/uart2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart2.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o: mcc_generated_files/EEPROM3_example.c  .generated_files/c19deaa525c91d5af0d67d1cb05f3d4ce217fa78.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/EEPROM3_example.c  -o ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o: mcc_generated_files/EEPROM3_driver.c  .generated_files/d72da59af2a430939220e52abf84952401841996.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/EEPROM3_driver.c  -o ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/i2c2_driver.o: mcc_generated_files/i2c2_driver.c  .generated_files/bcd1cab021e073915f62e2900da7f657f2170bcd.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/i2c2_driver.c  -o ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/i2c2_driver.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Modbus/ModbusTCPClient.o: Modbus/ModbusTCPClient.c  .generated_files/c060ed24a2d6bad9abb1b63eefd2e3bc2bef97b2.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Modbus" 
	@${RM} ${OBJECTDIR}/Modbus/ModbusTCPClient.o.d 
	@${RM} ${OBJECTDIR}/Modbus/ModbusTCPClient.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Modbus/ModbusTCPClient.c  -o ${OBJECTDIR}/Modbus/ModbusTCPClient.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Modbus/ModbusTCPClient.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Modbus/ModbusRTU_Slave.o: Modbus/ModbusRTU_Slave.c  .generated_files/fecb01cdd602cdbbf9236e93e25dfcf8428f0a3e.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Modbus" 
	@${RM} ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o.d 
	@${RM} ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Modbus/ModbusRTU_Slave.c  -o ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Modbus/ModbusRTU_Slave.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Modbus/ModbusRTU_Master.o: Modbus/ModbusRTU_Master.c  .generated_files/f2902e1826f1feacb364efd48aa1b3d8d2cd1455.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Modbus" 
	@${RM} ${OBJECTDIR}/Modbus/ModbusRTU_Master.o.d 
	@${RM} ${OBJECTDIR}/Modbus/ModbusRTU_Master.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Modbus/ModbusRTU_Master.c  -o ${OBJECTDIR}/Modbus/ModbusRTU_Master.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Modbus/ModbusRTU_Master.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PV/Inverter/0_Inverter.o: PV/Inverter/0_Inverter.c  .generated_files/44109507d6d7f06d730a17b29cf6209d53efdce5.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/PV/Inverter" 
	@${RM} ${OBJECTDIR}/PV/Inverter/0_Inverter.o.d 
	@${RM} ${OBJECTDIR}/PV/Inverter/0_Inverter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PV/Inverter/0_Inverter.c  -o ${OBJECTDIR}/PV/Inverter/0_Inverter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PV/Inverter/0_Inverter.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PV/Inverter/1_SunGrow.o: PV/Inverter/1_SunGrow.c  .generated_files/70f40234bc3a2050a26093906131427b83d88bd2.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/PV/Inverter" 
	@${RM} ${OBJECTDIR}/PV/Inverter/1_SunGrow.o.d 
	@${RM} ${OBJECTDIR}/PV/Inverter/1_SunGrow.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PV/Inverter/1_SunGrow.c  -o ${OBJECTDIR}/PV/Inverter/1_SunGrow.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PV/Inverter/1_SunGrow.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PV/Weather/Weather.o: PV/Weather/Weather.c  .generated_files/cf8a0257c50b418bb353b340ec2f43b4a5477544.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/PV/Weather" 
	@${RM} ${OBJECTDIR}/PV/Weather/Weather.o.d 
	@${RM} ${OBJECTDIR}/PV/Weather/Weather.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PV/Weather/Weather.c  -o ${OBJECTDIR}/PV/Weather/Weather.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PV/Weather/Weather.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PV/PV.o: PV/PV.c  .generated_files/194f7ba4938ee26833bcd01895caa199251ad499.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/PV" 
	@${RM} ${OBJECTDIR}/PV/PV.o.d 
	@${RM} ${OBJECTDIR}/PV/PV.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PV/PV.c  -o ${OBJECTDIR}/PV/PV.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PV/PV.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/arc4.o: Framework/tcpip/src/common/arc4.c  .generated_files/eb0143ba1b8ee2250341c803a1c0f59b873b6d42.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/arc4.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/arc4.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/big_int.o: Framework/tcpip/src/common/big_int.c  .generated_files/b2f542f64534584a962a0a5b5ad530511849b2f9.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/big_int.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/big_int.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/delay.o: Framework/tcpip/src/common/delay.c  .generated_files/87219b05b180fa2f2ee304761e2e7b4158ecbd22.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/delay.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/delay.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/delay.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/hashes.o: Framework/tcpip/src/common/hashes.c  .generated_files/d16588590333707a347bff0b3d726f41a9a2e4b.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/hashes.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/hashes.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/helpers.o: Framework/tcpip/src/common/helpers.c  .generated_files/78f2e0ce598c31f5a7b7764a18d503b416f54eed.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/helpers.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/helpers.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o: Framework/tcpip/src/common/mpfs2.c  .generated_files/b484bf28186ac93607111589545b77a53d50a930.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/mpfs2.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/rsa.o: Framework/tcpip/src/common/rsa.c  .generated_files/50ada5a02e9fef142f929789c81bdbe981cac0e2.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/rsa.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/rsa.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o: Framework/tcpip/src/common/stack_task.c  .generated_files/656222159d23b83acd2f5ab41f93d1421a7da974.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/stack_task.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/tick.o: Framework/tcpip/src/common/tick.c  .generated_files/8fd7ca34c5c44c5bfb3198916ba243c5fc11515e.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/tick.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/tick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/tick.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/tick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/tick.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/arp.o: Framework/tcpip/src/arp.c  .generated_files/1d29e5fcffcc0bf4433ebff57fdf06e4b5b13d2e.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/arp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/arp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/arp.c  -o ${OBJECTDIR}/Framework/tcpip/src/arp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/arp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o: Framework/tcpip/src/custom_ssl_cert.c  .generated_files/56e480a619643b4d0328d25ce7858404be6e7980.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/custom_ssl_cert.c  -o ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/ddns.o: Framework/tcpip/src/ddns.c  .generated_files/9b78d9228afa6aff0b868f70bfbce0ea800640b5.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ddns.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ddns.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/ddns.c  -o ${OBJECTDIR}/Framework/tcpip/src/ddns.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/ddns.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o: Framework/tcpip/src/dhcp_client.c  .generated_files/12e29152ee0b80e2ce9c6d6c1e7651f1f7e24db7.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dhcp_client.c  -o ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o: Framework/tcpip/src/dhcp_server.c  .generated_files/e9bb7a75b29075f718a530e5836b62f9dde62e05.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dhcp_server.c  -o ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/dns_client.o: Framework/tcpip/src/dns_client.c  .generated_files/79a1b412d6c82c1f6a83a0c0d8b3761615c2ed7e.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_client.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dns_client.c  -o ${OBJECTDIR}/Framework/tcpip/src/dns_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dns_client.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/dns_server.o: Framework/tcpip/src/dns_server.c  .generated_files/3110eff9ccafa9461217adeaa5d896e309a7ecfd.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_server.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_server.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dns_server.c  -o ${OBJECTDIR}/Framework/tcpip/src/dns_server.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dns_server.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/enc28j60.o: Framework/tcpip/src/enc28j60.c  .generated_files/71c803f28bad978ed9c305cfa55feea811db3be5.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/enc28j60.c  -o ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/enc28j60.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/FTP.o: Framework/tcpip/src/FTP.c  .generated_files/5d8f89676ee0a9d1eeaa1d611e09b84c12ddbc11.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/FTP.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/FTP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/FTP.c  -o ${OBJECTDIR}/Framework/tcpip/src/FTP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/FTP.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/http2.o: Framework/tcpip/src/http2.c  .generated_files/237aab2ab138f436944c385b6f682fc74ab48137.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/http2.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/http2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/http2.c  -o ${OBJECTDIR}/Framework/tcpip/src/http2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/http2.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/icmp.o: Framework/tcpip/src/icmp.c  .generated_files/60336335a4a00852084f062e440dc6961e6c7808.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/icmp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/icmp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/icmp.c  -o ${OBJECTDIR}/Framework/tcpip/src/icmp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/icmp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/ip.o: Framework/tcpip/src/ip.c  .generated_files/5e4d420daee320c5a7b3cea65124d91f3bc7cbb1.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ip.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ip.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/ip.c  -o ${OBJECTDIR}/Framework/tcpip/src/ip.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/ip.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/nbns.o: Framework/tcpip/src/nbns.c  .generated_files/3a9917ca95d0886fb017a3ea329c29cd2f237bf4.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/nbns.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/nbns.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/nbns.c  -o ${OBJECTDIR}/Framework/tcpip/src/nbns.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/nbns.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/random.o: Framework/tcpip/src/random.c  .generated_files/8a58f6c83c9de65c16e208b8472b25dc5feee035.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/random.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/random.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/random.c  -o ${OBJECTDIR}/Framework/tcpip/src/random.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/random.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/smtp.o: Framework/tcpip/src/smtp.c  .generated_files/8c7d5e185b6b25f55806e11c54f08aff94eaa02f.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/smtp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/smtp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/smtp.c  -o ${OBJECTDIR}/Framework/tcpip/src/smtp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/smtp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/ssl.o: Framework/tcpip/src/ssl.c  .generated_files/8149eaf61ed0743e3f840c2c88c13c204ccd7de9.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ssl.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ssl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/ssl.c  -o ${OBJECTDIR}/Framework/tcpip/src/ssl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/ssl.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/tcp.o: Framework/tcpip/src/tcp.c  .generated_files/f3dbd0fbadef2489bda76ae4c0ddf7a42cab11f.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/tcp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/tcp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/tcp.c  -o ${OBJECTDIR}/Framework/tcpip/src/tcp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/tcp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/telnet.o: Framework/tcpip/src/telnet.c  .generated_files/e51e468d306b85ec62c6bde9a676f43ae1354ced.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/telnet.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/telnet.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/telnet.c  -o ${OBJECTDIR}/Framework/tcpip/src/telnet.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/telnet.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/udp.o: Framework/tcpip/src/udp.c  .generated_files/1d9564360ff19087931817cd3a4e99682d082d3e.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/udp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/udp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/udp.c  -o ${OBJECTDIR}/Framework/tcpip/src/udp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/udp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/announce.o: Framework/tcpip/src/announce.c  .generated_files/2338cd1d33cbdbbecc6726ca01f7bd594d798b15.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/announce.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/announce.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/announce.c  -o ${OBJECTDIR}/Framework/tcpip/src/announce.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/announce.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/204f06a78de4cc7f4ae628289675fcafce217218.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/user.o: user.c  .generated_files/800301d3acb38eb8787b2f2572db58b3c99eac41.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${RM} ${OBJECTDIR}/user.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  user.c  -o ${OBJECTDIR}/user.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/user.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o: mcc_generated_files/drivers/i2c_types.c  .generated_files/94abd446a9083069631656faa9fac32b771d6958.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/drivers/i2c_types.c  -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o: mcc_generated_files/drivers/i2c_master.c  .generated_files/cf1fa80586b8665b73d4b421fac6378998b20d36.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/drivers/i2c_master.c  -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o: mcc_generated_files/drivers/i2c_simple_master.c  .generated_files/12434f98cf84d333122be91f683e95e237b163cc.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/drivers/i2c_simple_master.c  -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/spi1.o: mcc_generated_files/spi1.c  .generated_files/bb77dab1a8a8c0a5735a8f0ce06e54e5dd38f437.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/spi1.c  -o ${OBJECTDIR}/mcc_generated_files/spi1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/spi1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/reset.o: mcc_generated_files/reset.c  .generated_files/91bc4482d541d073b9a0a4ca608b16d17c6e43d7.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/reset.c  -o ${OBJECTDIR}/mcc_generated_files/reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/reset.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/9e35872011dc4ef9156f623c865d6986557fd61d.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/83a98ae71be0ea93faca22e307cad432ace38e5f.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/c69a8aba48e0afd5873e34ddfd0399d43f68efa1.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/f139f9cf419b2ff87803084a27d4dee900131dd1.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/e2f2a7c3f2c2a6100f634de346a8f8a85fc89f73.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/4a4ef32105188442180c99cc1ef861a5a17be6a1.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/tmr2.o: mcc_generated_files/tmr2.c  .generated_files/b3d8961270338ac2d6ae81ab83b65d397cf3b99f.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr2.c  -o ${OBJECTDIR}/mcc_generated_files/tmr2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/uart1.o: mcc_generated_files/uart1.c  .generated_files/9f83fa8d52ac52794efb28fda04e978c8f2b2213.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart1.c  -o ${OBJECTDIR}/mcc_generated_files/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/uart2.o: mcc_generated_files/uart2.c  .generated_files/c944b314b9e127528c4fa106886c080f89188f49.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart2.c  -o ${OBJECTDIR}/mcc_generated_files/uart2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o: mcc_generated_files/EEPROM3_example.c  .generated_files/deb1d2548198d9fd05ddd760445f2d0489f9c00c.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/EEPROM3_example.c  -o ${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/EEPROM3_example.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o: mcc_generated_files/EEPROM3_driver.c  .generated_files/51f5af0146c095eca43e5ff896241aaca4feafe.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/EEPROM3_driver.c  -o ${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/EEPROM3_driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/i2c2_driver.o: mcc_generated_files/i2c2_driver.c  .generated_files/a99ed261b2e8e5d33820f6fba546cb05371ce9c0.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/i2c2_driver.c  -o ${OBJECTDIR}/mcc_generated_files/i2c2_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/i2c2_driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Modbus/ModbusTCPClient.o: Modbus/ModbusTCPClient.c  .generated_files/2cdc47b2bad7c01fcb9c16134ebed3e4466e35e0.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Modbus" 
	@${RM} ${OBJECTDIR}/Modbus/ModbusTCPClient.o.d 
	@${RM} ${OBJECTDIR}/Modbus/ModbusTCPClient.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Modbus/ModbusTCPClient.c  -o ${OBJECTDIR}/Modbus/ModbusTCPClient.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Modbus/ModbusTCPClient.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Modbus/ModbusRTU_Slave.o: Modbus/ModbusRTU_Slave.c  .generated_files/3cad0b0432d44c24d179a2f7b975eefa57f14aeb.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Modbus" 
	@${RM} ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o.d 
	@${RM} ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Modbus/ModbusRTU_Slave.c  -o ${OBJECTDIR}/Modbus/ModbusRTU_Slave.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Modbus/ModbusRTU_Slave.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Modbus/ModbusRTU_Master.o: Modbus/ModbusRTU_Master.c  .generated_files/cabc4950e85defa605eea78631b619ea27b9776d.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Modbus" 
	@${RM} ${OBJECTDIR}/Modbus/ModbusRTU_Master.o.d 
	@${RM} ${OBJECTDIR}/Modbus/ModbusRTU_Master.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Modbus/ModbusRTU_Master.c  -o ${OBJECTDIR}/Modbus/ModbusRTU_Master.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Modbus/ModbusRTU_Master.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PV/Inverter/0_Inverter.o: PV/Inverter/0_Inverter.c  .generated_files/a73fff097098d42c9651650c652bd0e9a823be33.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/PV/Inverter" 
	@${RM} ${OBJECTDIR}/PV/Inverter/0_Inverter.o.d 
	@${RM} ${OBJECTDIR}/PV/Inverter/0_Inverter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PV/Inverter/0_Inverter.c  -o ${OBJECTDIR}/PV/Inverter/0_Inverter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PV/Inverter/0_Inverter.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PV/Inverter/1_SunGrow.o: PV/Inverter/1_SunGrow.c  .generated_files/10b2fc0defdf261ab758ef65514814b9290d187f.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/PV/Inverter" 
	@${RM} ${OBJECTDIR}/PV/Inverter/1_SunGrow.o.d 
	@${RM} ${OBJECTDIR}/PV/Inverter/1_SunGrow.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PV/Inverter/1_SunGrow.c  -o ${OBJECTDIR}/PV/Inverter/1_SunGrow.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PV/Inverter/1_SunGrow.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PV/Weather/Weather.o: PV/Weather/Weather.c  .generated_files/9d78700d6a692eac7e4d80737db875f423ed6b19.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/PV/Weather" 
	@${RM} ${OBJECTDIR}/PV/Weather/Weather.o.d 
	@${RM} ${OBJECTDIR}/PV/Weather/Weather.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PV/Weather/Weather.c  -o ${OBJECTDIR}/PV/Weather/Weather.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PV/Weather/Weather.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PV/PV.o: PV/PV.c  .generated_files/cb7b59c437b9177f0f963986be833fa3cf33bbb5.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/PV" 
	@${RM} ${OBJECTDIR}/PV/PV.o.d 
	@${RM} ${OBJECTDIR}/PV/PV.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PV/PV.c  -o ${OBJECTDIR}/PV/PV.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PV/PV.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/arc4.o: Framework/tcpip/src/common/arc4.c  .generated_files/ddfa20927435fa662dc4d5c98acf6d14965c3145.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/arc4.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/arc4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/arc4.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/big_int.o: Framework/tcpip/src/common/big_int.c  .generated_files/b562a23cf79351b36ec020fc79d409951f1162f9.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/big_int.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/big_int.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/big_int.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/delay.o: Framework/tcpip/src/common/delay.c  .generated_files/27381ae607da86eed7a3c1eb62215daf85303c38.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/delay.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/delay.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/delay.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/hashes.o: Framework/tcpip/src/common/hashes.c  .generated_files/47a42cf6398ae1a72e034f4318ed7c61b523c56b.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/hashes.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/hashes.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/hashes.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/helpers.o: Framework/tcpip/src/common/helpers.c  .generated_files/7e0f12bcc3a922baebd2946f6bfcf46ee6df5f7b.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/helpers.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/helpers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/helpers.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o: Framework/tcpip/src/common/mpfs2.c  .generated_files/cdab09b4f3d143bef7ac0e1bb7b9f96e59b1a54c.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/mpfs2.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/mpfs2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/rsa.o: Framework/tcpip/src/common/rsa.c  .generated_files/4a5fb1d3842ce17e6c4eb75465ddca2a49f0cfed.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/rsa.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/rsa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/rsa.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o: Framework/tcpip/src/common/stack_task.c  .generated_files/947b3315fedebd97292262fe8c66fd143177f7af.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/stack_task.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/stack_task.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/common/tick.o: Framework/tcpip/src/common/tick.c  .generated_files/8794ac31cf69da6101b10175d6238b5304e34299.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/tick.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/tick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/common/tick.c  -o ${OBJECTDIR}/Framework/tcpip/src/common/tick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/tick.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/arp.o: Framework/tcpip/src/arp.c  .generated_files/7f00a90f7f0756c4f0c8d2f23c93fd6d533d51c1.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/arp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/arp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/arp.c  -o ${OBJECTDIR}/Framework/tcpip/src/arp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/arp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o: Framework/tcpip/src/custom_ssl_cert.c  .generated_files/c5871e18ea3df7900002021c3d79400946e122ae.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/custom_ssl_cert.c  -o ${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/custom_ssl_cert.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/ddns.o: Framework/tcpip/src/ddns.c  .generated_files/404e41ce2dcde35824b38bbb11c2f4ada0b523a0.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ddns.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ddns.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/ddns.c  -o ${OBJECTDIR}/Framework/tcpip/src/ddns.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/ddns.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o: Framework/tcpip/src/dhcp_client.c  .generated_files/93357b0c3376d8b6a02e10c4bb726fd3d0073e47.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dhcp_client.c  -o ${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dhcp_client.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o: Framework/tcpip/src/dhcp_server.c  .generated_files/a29da73aff9a207e01aa6c7ed640ce5f4dfd606f.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dhcp_server.c  -o ${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dhcp_server.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/dns_client.o: Framework/tcpip/src/dns_client.c  .generated_files/f6b192dbf262aab60c7218eb5a3b8b23ce9c4c3f.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_client.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dns_client.c  -o ${OBJECTDIR}/Framework/tcpip/src/dns_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dns_client.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/dns_server.o: Framework/tcpip/src/dns_server.c  .generated_files/c0c1a9d0f4ee217a8c41fa2e0ef93e990175b649.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_server.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/dns_server.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/dns_server.c  -o ${OBJECTDIR}/Framework/tcpip/src/dns_server.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/dns_server.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/enc28j60.o: Framework/tcpip/src/enc28j60.c  .generated_files/9eb7056e4adac735e5415ceeaaf959958922826.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/enc28j60.c  -o ${OBJECTDIR}/Framework/tcpip/src/enc28j60.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/enc28j60.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/FTP.o: Framework/tcpip/src/FTP.c  .generated_files/c00c5eab84ca74f15ee4be0b461c2d1601ce08d8.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/FTP.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/FTP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/FTP.c  -o ${OBJECTDIR}/Framework/tcpip/src/FTP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/FTP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/http2.o: Framework/tcpip/src/http2.c  .generated_files/41597ab76230e5468b88e81a3b4f9e9fd45d2ff3.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/http2.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/http2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/http2.c  -o ${OBJECTDIR}/Framework/tcpip/src/http2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/http2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/icmp.o: Framework/tcpip/src/icmp.c  .generated_files/8b12f2b0e1bd3f4048159ae8f5f5a01cec962887.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/icmp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/icmp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/icmp.c  -o ${OBJECTDIR}/Framework/tcpip/src/icmp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/icmp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/ip.o: Framework/tcpip/src/ip.c  .generated_files/4a6f6400668add27300a9ce8f32ca616d1cf0983.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ip.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ip.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/ip.c  -o ${OBJECTDIR}/Framework/tcpip/src/ip.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/ip.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/nbns.o: Framework/tcpip/src/nbns.c  .generated_files/852ed6857191ac5831a416e19b2c86b867936144.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/nbns.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/nbns.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/nbns.c  -o ${OBJECTDIR}/Framework/tcpip/src/nbns.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/nbns.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/random.o: Framework/tcpip/src/random.c  .generated_files/65eb4e4f2d38ba9d590f72fda5f7d55846831772.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/random.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/random.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/random.c  -o ${OBJECTDIR}/Framework/tcpip/src/random.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/random.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/smtp.o: Framework/tcpip/src/smtp.c  .generated_files/e9f1554ef0cea85fecac3a90b57d6c7635dcea1c.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/smtp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/smtp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/smtp.c  -o ${OBJECTDIR}/Framework/tcpip/src/smtp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/smtp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/ssl.o: Framework/tcpip/src/ssl.c  .generated_files/f678fd00a0442c6a0d52ec2bffb4c5c3a923b811.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ssl.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/ssl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/ssl.c  -o ${OBJECTDIR}/Framework/tcpip/src/ssl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/ssl.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/tcp.o: Framework/tcpip/src/tcp.c  .generated_files/efc9bbdfcbc347d90cb287305b40e20af13cbb5f.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/tcp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/tcp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/tcp.c  -o ${OBJECTDIR}/Framework/tcpip/src/tcp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/tcp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/telnet.o: Framework/tcpip/src/telnet.c  .generated_files/7f8b59bd000931bdd465c0f4879fbb54e183b3cd.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/telnet.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/telnet.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/telnet.c  -o ${OBJECTDIR}/Framework/tcpip/src/telnet.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/telnet.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/udp.o: Framework/tcpip/src/udp.c  .generated_files/b6daef8c37717de1cbd74fa575285258c9b365ff.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/udp.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/udp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/udp.c  -o ${OBJECTDIR}/Framework/tcpip/src/udp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/udp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Framework/tcpip/src/announce.o: Framework/tcpip/src/announce.c  .generated_files/6eeb42e844e14af577a72607424c8b3901c79352.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/announce.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/announce.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Framework/tcpip/src/announce.c  -o ${OBJECTDIR}/Framework/tcpip/src/announce.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/announce.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/4b7a97678c326393e4ff0e1dcce5b78728ae6c01.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/user.o: user.c  .generated_files/d016a02e47b7135b862fecc6c699248b1feaf381.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${RM} ${OBJECTDIR}/user.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  user.c  -o ${OBJECTDIR}/user.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/user.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -menable-large-arrays -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o: Framework/tcpip/src/common/big_int_helper.S  .generated_files/7613a21ce7083eec6ddcf8416d6df6a15014c61a.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  Framework/tcpip/src/common/big_int_helper.S  -o ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o.d"  -D__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o.asm.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o: Framework/tcpip/src/common/big_int_helper.S  .generated_files/20aa7434048b887b5daa3b1ffa7eaa06215ea9ad.flag .generated_files/f48298c4a5db53e5ff163868c7024333ab1edf90.flag
	@${MKDIR} "${OBJECTDIR}/Framework/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o.d 
	@${RM} ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  Framework/tcpip/src/common/big_int_helper.S  -o ${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o.d"  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/Framework/tcpip/src/common/big_int_helper.o.asm.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/4.2-PVG.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
