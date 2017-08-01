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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Ethernet.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Ethernet.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../src/system_config/default/framework/net/pres/net_pres_enc_glue.c ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/framework/system/reset/src/sys_reset.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/system_config/default/system_tasks.c ../src/app.c ../src/main.c ../src/app_command.c ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac.c ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac_lib.c ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_ethphy.c ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_extphy_smsc8720.c ../../../../v2_03b/framework/driver/miim/src/dynamic/drv_miim.c ../../../../v2_03b/framework/driver/tmr/src/dynamic/drv_tmr.c ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart.c ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_buffer_queue.c ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_read_write.c ../../../../v2_03b/framework/net/pres/src/net_pres.c ../../../../v2_03b/framework/system/command/src/sys_command.c ../../../../v2_03b/framework/system/console/src/sys_console.c ../../../../v2_03b/framework/system/console/src/sys_console_uart.c ../../../../v2_03b/framework/system/debug/src/sys_debug.c ../../../../v2_03b/framework/system/int/src/sys_int_pic32.c ../../../../v2_03b/framework/system/random/src/sys_random.c ../../../../v2_03b/framework/system/tmr/src/sys_tmr.c ../../../../v2_03b/framework/tcpip/src/common/helpers.c ../../../../v2_03b/framework/tcpip/src/ipv4.c ../../../../v2_03b/framework/tcpip/src/tcp.c ../../../../v2_03b/framework/tcpip/src/udp.c ../../../../v2_03b/framework/tcpip/src/tcpip_heap_alloc.c ../../../../v2_03b/framework/tcpip/src/tcpip_heap_internal.c ../../../../v2_03b/framework/tcpip/src/arp.c ../../../../v2_03b/framework/tcpip/src/dhcp.c ../../../../v2_03b/framework/tcpip/src/dns.c ../../../../v2_03b/framework/tcpip/src/icmp.c ../../../../v2_03b/framework/tcpip/src/nbns.c ../../../../v2_03b/framework/tcpip/src/zero_conf_helper.c ../../../../v2_03b/framework/tcpip/src/zero_conf_link_local.c ../../../../v2_03b/framework/tcpip/src/tcpip_announce.c ../../../../v2_03b/framework/tcpip/src/tcpip_commands.c ../../../../v2_03b/framework/tcpip/src/hash_fnv.c ../../../../v2_03b/framework/tcpip/src/oahash.c ../../../../v2_03b/framework/tcpip/src/tcpip_helpers.c ../../../../v2_03b/framework/tcpip/src/tcpip_helper_c32.S ../../../../v2_03b/framework/tcpip/src/tcpip_manager.c ../../../../v2_03b/framework/tcpip/src/tcpip_notify.c ../../../../v2_03b/framework/tcpip/src/tcpip_packet.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/68765530/sys_reset.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/app_command.o ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o ${OBJECTDIR}/_ext/573518448/drv_ethphy.o ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o ${OBJECTDIR}/_ext/1568515672/drv_miim.o ${OBJECTDIR}/_ext/528688037/drv_tmr.o ${OBJECTDIR}/_ext/427015431/drv_usart.o ${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o ${OBJECTDIR}/_ext/2146114523/net_pres.o ${OBJECTDIR}/_ext/1167192164/sys_command.o ${OBJECTDIR}/_ext/710479984/sys_console.o ${OBJECTDIR}/_ext/710479984/sys_console_uart.o ${OBJECTDIR}/_ext/429005716/sys_debug.o ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o ${OBJECTDIR}/_ext/1584847572/sys_random.o ${OBJECTDIR}/_ext/1482654414/sys_tmr.o ${OBJECTDIR}/_ext/157393855/helpers.o ${OBJECTDIR}/_ext/1836803193/ipv4.o ${OBJECTDIR}/_ext/1836803193/tcp.o ${OBJECTDIR}/_ext/1836803193/udp.o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o ${OBJECTDIR}/_ext/1836803193/arp.o ${OBJECTDIR}/_ext/1836803193/dhcp.o ${OBJECTDIR}/_ext/1836803193/dns.o ${OBJECTDIR}/_ext/1836803193/icmp.o ${OBJECTDIR}/_ext/1836803193/nbns.o ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o ${OBJECTDIR}/_ext/1836803193/tcpip_commands.o ${OBJECTDIR}/_ext/1836803193/hash_fnv.o ${OBJECTDIR}/_ext/1836803193/oahash.o ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o.d ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d ${OBJECTDIR}/_ext/68765530/sys_reset.o.d ${OBJECTDIR}/_ext/1688732426/system_init.o.d ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/app_command.o.d ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o.d ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o.d ${OBJECTDIR}/_ext/573518448/drv_ethphy.o.d ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o.d ${OBJECTDIR}/_ext/1568515672/drv_miim.o.d ${OBJECTDIR}/_ext/528688037/drv_tmr.o.d ${OBJECTDIR}/_ext/427015431/drv_usart.o.d ${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o.d ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o.d ${OBJECTDIR}/_ext/2146114523/net_pres.o.d ${OBJECTDIR}/_ext/1167192164/sys_command.o.d ${OBJECTDIR}/_ext/710479984/sys_console.o.d ${OBJECTDIR}/_ext/710479984/sys_console_uart.o.d ${OBJECTDIR}/_ext/429005716/sys_debug.o.d ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o.d ${OBJECTDIR}/_ext/1584847572/sys_random.o.d ${OBJECTDIR}/_ext/1482654414/sys_tmr.o.d ${OBJECTDIR}/_ext/157393855/helpers.o.d ${OBJECTDIR}/_ext/1836803193/ipv4.o.d ${OBJECTDIR}/_ext/1836803193/tcp.o.d ${OBJECTDIR}/_ext/1836803193/udp.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o.d ${OBJECTDIR}/_ext/1836803193/arp.o.d ${OBJECTDIR}/_ext/1836803193/dhcp.o.d ${OBJECTDIR}/_ext/1836803193/dns.o.d ${OBJECTDIR}/_ext/1836803193/icmp.o.d ${OBJECTDIR}/_ext/1836803193/nbns.o.d ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o.d ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_commands.o.d ${OBJECTDIR}/_ext/1836803193/hash_fnv.o.d ${OBJECTDIR}/_ext/1836803193/oahash.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/68765530/sys_reset.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/app_command.o ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o ${OBJECTDIR}/_ext/573518448/drv_ethphy.o ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o ${OBJECTDIR}/_ext/1568515672/drv_miim.o ${OBJECTDIR}/_ext/528688037/drv_tmr.o ${OBJECTDIR}/_ext/427015431/drv_usart.o ${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o ${OBJECTDIR}/_ext/2146114523/net_pres.o ${OBJECTDIR}/_ext/1167192164/sys_command.o ${OBJECTDIR}/_ext/710479984/sys_console.o ${OBJECTDIR}/_ext/710479984/sys_console_uart.o ${OBJECTDIR}/_ext/429005716/sys_debug.o ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o ${OBJECTDIR}/_ext/1584847572/sys_random.o ${OBJECTDIR}/_ext/1482654414/sys_tmr.o ${OBJECTDIR}/_ext/157393855/helpers.o ${OBJECTDIR}/_ext/1836803193/ipv4.o ${OBJECTDIR}/_ext/1836803193/tcp.o ${OBJECTDIR}/_ext/1836803193/udp.o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o ${OBJECTDIR}/_ext/1836803193/arp.o ${OBJECTDIR}/_ext/1836803193/dhcp.o ${OBJECTDIR}/_ext/1836803193/dns.o ${OBJECTDIR}/_ext/1836803193/icmp.o ${OBJECTDIR}/_ext/1836803193/nbns.o ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o ${OBJECTDIR}/_ext/1836803193/tcpip_commands.o ${OBJECTDIR}/_ext/1836803193/hash_fnv.o ${OBJECTDIR}/_ext/1836803193/oahash.o ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o

# Source Files
SOURCEFILES=../src/system_config/default/framework/net/pres/net_pres_enc_glue.c ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/framework/system/reset/src/sys_reset.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/system_config/default/system_tasks.c ../src/app.c ../src/main.c ../src/app_command.c ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac.c ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac_lib.c ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_ethphy.c ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_extphy_smsc8720.c ../../../../v2_03b/framework/driver/miim/src/dynamic/drv_miim.c ../../../../v2_03b/framework/driver/tmr/src/dynamic/drv_tmr.c ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart.c ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_buffer_queue.c ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_read_write.c ../../../../v2_03b/framework/net/pres/src/net_pres.c ../../../../v2_03b/framework/system/command/src/sys_command.c ../../../../v2_03b/framework/system/console/src/sys_console.c ../../../../v2_03b/framework/system/console/src/sys_console_uart.c ../../../../v2_03b/framework/system/debug/src/sys_debug.c ../../../../v2_03b/framework/system/int/src/sys_int_pic32.c ../../../../v2_03b/framework/system/random/src/sys_random.c ../../../../v2_03b/framework/system/tmr/src/sys_tmr.c ../../../../v2_03b/framework/tcpip/src/common/helpers.c ../../../../v2_03b/framework/tcpip/src/ipv4.c ../../../../v2_03b/framework/tcpip/src/tcp.c ../../../../v2_03b/framework/tcpip/src/udp.c ../../../../v2_03b/framework/tcpip/src/tcpip_heap_alloc.c ../../../../v2_03b/framework/tcpip/src/tcpip_heap_internal.c ../../../../v2_03b/framework/tcpip/src/arp.c ../../../../v2_03b/framework/tcpip/src/dhcp.c ../../../../v2_03b/framework/tcpip/src/dns.c ../../../../v2_03b/framework/tcpip/src/icmp.c ../../../../v2_03b/framework/tcpip/src/nbns.c ../../../../v2_03b/framework/tcpip/src/zero_conf_helper.c ../../../../v2_03b/framework/tcpip/src/zero_conf_link_local.c ../../../../v2_03b/framework/tcpip/src/tcpip_announce.c ../../../../v2_03b/framework/tcpip/src/tcpip_commands.c ../../../../v2_03b/framework/tcpip/src/hash_fnv.c ../../../../v2_03b/framework/tcpip/src/oahash.c ../../../../v2_03b/framework/tcpip/src/tcpip_helpers.c ../../../../v2_03b/framework/tcpip/src/tcpip_helper_c32.S ../../../../v2_03b/framework/tcpip/src/tcpip_manager.c ../../../../v2_03b/framework/tcpip/src/tcpip_notify.c ../../../../v2_03b/framework/tcpip/src/tcpip_packet.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Ethernet.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512H
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o: ../../../../v2_03b/framework/tcpip/src/tcpip_helper_c32.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.ok ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.d" "${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.d"  -o ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o ../../../../v2_03b/framework/tcpip/src/tcpip_helper_c32.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1
	
else
${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o: ../../../../v2_03b/framework/tcpip/src/tcpip_helper_c32.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.ok ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.d" "${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.d"  -o ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o ../../../../v2_03b/framework/tcpip/src/tcpip_helper_c32.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.asm.d",--gdwarf-2
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o: ../src/system_config/default/framework/net/pres/net_pres_enc_glue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1278673032" 
	@${RM} ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o.d" -o ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o ../src/system_config/default/framework/net/pres/net_pres_enc_glue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/68765530/sys_reset.o: ../src/system_config/default/framework/system/reset/src/sys_reset.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/68765530" 
	@${RM} ${OBJECTDIR}/_ext/68765530/sys_reset.o.d 
	@${RM} ${OBJECTDIR}/_ext/68765530/sys_reset.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/68765530/sys_reset.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/68765530/sys_reset.o.d" -o ${OBJECTDIR}/_ext/68765530/sys_reset.o ../src/system_config/default/framework/system/reset/src/sys_reset.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/app_command.o: ../src/app_command.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_command.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_command.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app_command.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/app_command.o.d" -o ${OBJECTDIR}/_ext/1360937237/app_command.o ../src/app_command.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1749672254/drv_ethmac.o: ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1749672254" 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1749672254/drv_ethmac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1749672254/drv_ethmac.o.d" -o ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o: ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1749672254" 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o.d" -o ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/573518448/drv_ethphy.o: ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_ethphy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/573518448" 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_ethphy.o.d 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_ethphy.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/573518448/drv_ethphy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/573518448/drv_ethphy.o.d" -o ${OBJECTDIR}/_ext/573518448/drv_ethphy.o ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_ethphy.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o: ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_extphy_smsc8720.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/573518448" 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o.d 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o.d" -o ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_extphy_smsc8720.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1568515672/drv_miim.o: ../../../../v2_03b/framework/driver/miim/src/dynamic/drv_miim.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1568515672" 
	@${RM} ${OBJECTDIR}/_ext/1568515672/drv_miim.o.d 
	@${RM} ${OBJECTDIR}/_ext/1568515672/drv_miim.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1568515672/drv_miim.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1568515672/drv_miim.o.d" -o ${OBJECTDIR}/_ext/1568515672/drv_miim.o ../../../../v2_03b/framework/driver/miim/src/dynamic/drv_miim.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/528688037/drv_tmr.o: ../../../../v2_03b/framework/driver/tmr/src/dynamic/drv_tmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/528688037" 
	@${RM} ${OBJECTDIR}/_ext/528688037/drv_tmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/528688037/drv_tmr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/528688037/drv_tmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/528688037/drv_tmr.o.d" -o ${OBJECTDIR}/_ext/528688037/drv_tmr.o ../../../../v2_03b/framework/driver/tmr/src/dynamic/drv_tmr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/427015431/drv_usart.o: ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427015431" 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/427015431/drv_usart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/427015431/drv_usart.o.d" -o ${OBJECTDIR}/_ext/427015431/drv_usart.o ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o: ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_buffer_queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427015431" 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o.d" -o ${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_buffer_queue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o: ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_read_write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427015431" 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o.d 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o.d" -o ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_read_write.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2146114523/net_pres.o: ../../../../v2_03b/framework/net/pres/src/net_pres.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2146114523" 
	@${RM} ${OBJECTDIR}/_ext/2146114523/net_pres.o.d 
	@${RM} ${OBJECTDIR}/_ext/2146114523/net_pres.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2146114523/net_pres.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/2146114523/net_pres.o.d" -o ${OBJECTDIR}/_ext/2146114523/net_pres.o ../../../../v2_03b/framework/net/pres/src/net_pres.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1167192164/sys_command.o: ../../../../v2_03b/framework/system/command/src/sys_command.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1167192164" 
	@${RM} ${OBJECTDIR}/_ext/1167192164/sys_command.o.d 
	@${RM} ${OBJECTDIR}/_ext/1167192164/sys_command.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1167192164/sys_command.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1167192164/sys_command.o.d" -o ${OBJECTDIR}/_ext/1167192164/sys_command.o ../../../../v2_03b/framework/system/command/src/sys_command.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/710479984/sys_console.o: ../../../../v2_03b/framework/system/console/src/sys_console.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/710479984" 
	@${RM} ${OBJECTDIR}/_ext/710479984/sys_console.o.d 
	@${RM} ${OBJECTDIR}/_ext/710479984/sys_console.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/710479984/sys_console.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/710479984/sys_console.o.d" -o ${OBJECTDIR}/_ext/710479984/sys_console.o ../../../../v2_03b/framework/system/console/src/sys_console.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/710479984/sys_console_uart.o: ../../../../v2_03b/framework/system/console/src/sys_console_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/710479984" 
	@${RM} ${OBJECTDIR}/_ext/710479984/sys_console_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/710479984/sys_console_uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/710479984/sys_console_uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/710479984/sys_console_uart.o.d" -o ${OBJECTDIR}/_ext/710479984/sys_console_uart.o ../../../../v2_03b/framework/system/console/src/sys_console_uart.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/429005716/sys_debug.o: ../../../../v2_03b/framework/system/debug/src/sys_debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/429005716" 
	@${RM} ${OBJECTDIR}/_ext/429005716/sys_debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/429005716/sys_debug.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/429005716/sys_debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/429005716/sys_debug.o.d" -o ${OBJECTDIR}/_ext/429005716/sys_debug.o ../../../../v2_03b/framework/system/debug/src/sys_debug.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o: ../../../../v2_03b/framework/system/int/src/sys_int_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1670183176" 
	@${RM} ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o ../../../../v2_03b/framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1584847572/sys_random.o: ../../../../v2_03b/framework/system/random/src/sys_random.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1584847572" 
	@${RM} ${OBJECTDIR}/_ext/1584847572/sys_random.o.d 
	@${RM} ${OBJECTDIR}/_ext/1584847572/sys_random.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1584847572/sys_random.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1584847572/sys_random.o.d" -o ${OBJECTDIR}/_ext/1584847572/sys_random.o ../../../../v2_03b/framework/system/random/src/sys_random.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1482654414/sys_tmr.o: ../../../../v2_03b/framework/system/tmr/src/sys_tmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1482654414" 
	@${RM} ${OBJECTDIR}/_ext/1482654414/sys_tmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1482654414/sys_tmr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1482654414/sys_tmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1482654414/sys_tmr.o.d" -o ${OBJECTDIR}/_ext/1482654414/sys_tmr.o ../../../../v2_03b/framework/system/tmr/src/sys_tmr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/157393855/helpers.o: ../../../../v2_03b/framework/tcpip/src/common/helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/157393855" 
	@${RM} ${OBJECTDIR}/_ext/157393855/helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/157393855/helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/157393855/helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/157393855/helpers.o.d" -o ${OBJECTDIR}/_ext/157393855/helpers.o ../../../../v2_03b/framework/tcpip/src/common/helpers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/ipv4.o: ../../../../v2_03b/framework/tcpip/src/ipv4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/ipv4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/ipv4.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/ipv4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/ipv4.o.d" -o ${OBJECTDIR}/_ext/1836803193/ipv4.o ../../../../v2_03b/framework/tcpip/src/ipv4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcp.o: ../../../../v2_03b/framework/tcpip/src/tcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcp.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcp.o ../../../../v2_03b/framework/tcpip/src/tcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/udp.o: ../../../../v2_03b/framework/tcpip/src/udp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/udp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/udp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/udp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/udp.o.d" -o ${OBJECTDIR}/_ext/1836803193/udp.o ../../../../v2_03b/framework/tcpip/src/udp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o: ../../../../v2_03b/framework/tcpip/src/tcpip_heap_alloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o ../../../../v2_03b/framework/tcpip/src/tcpip_heap_alloc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o: ../../../../v2_03b/framework/tcpip/src/tcpip_heap_internal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o ../../../../v2_03b/framework/tcpip/src/tcpip_heap_internal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/arp.o: ../../../../v2_03b/framework/tcpip/src/arp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/arp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/arp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/arp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/arp.o.d" -o ${OBJECTDIR}/_ext/1836803193/arp.o ../../../../v2_03b/framework/tcpip/src/arp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/dhcp.o: ../../../../v2_03b/framework/tcpip/src/dhcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dhcp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dhcp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/dhcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/dhcp.o.d" -o ${OBJECTDIR}/_ext/1836803193/dhcp.o ../../../../v2_03b/framework/tcpip/src/dhcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/dns.o: ../../../../v2_03b/framework/tcpip/src/dns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dns.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/dns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/dns.o.d" -o ${OBJECTDIR}/_ext/1836803193/dns.o ../../../../v2_03b/framework/tcpip/src/dns.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/icmp.o: ../../../../v2_03b/framework/tcpip/src/icmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/icmp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/icmp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/icmp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/icmp.o.d" -o ${OBJECTDIR}/_ext/1836803193/icmp.o ../../../../v2_03b/framework/tcpip/src/icmp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/nbns.o: ../../../../v2_03b/framework/tcpip/src/nbns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/nbns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/nbns.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/nbns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/nbns.o.d" -o ${OBJECTDIR}/_ext/1836803193/nbns.o ../../../../v2_03b/framework/tcpip/src/nbns.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o: ../../../../v2_03b/framework/tcpip/src/zero_conf_helper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o.d" -o ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o ../../../../v2_03b/framework/tcpip/src/zero_conf_helper.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o: ../../../../v2_03b/framework/tcpip/src/zero_conf_link_local.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o.d" -o ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o ../../../../v2_03b/framework/tcpip/src/zero_conf_link_local.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_announce.o: ../../../../v2_03b/framework/tcpip/src/tcpip_announce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_announce.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_announce.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o ../../../../v2_03b/framework/tcpip/src/tcpip_announce.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_commands.o: ../../../../v2_03b/framework/tcpip/src/tcpip_commands.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_commands.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_commands.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_commands.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_commands.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_commands.o ../../../../v2_03b/framework/tcpip/src/tcpip_commands.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/hash_fnv.o: ../../../../v2_03b/framework/tcpip/src/hash_fnv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/hash_fnv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/hash_fnv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/hash_fnv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/hash_fnv.o.d" -o ${OBJECTDIR}/_ext/1836803193/hash_fnv.o ../../../../v2_03b/framework/tcpip/src/hash_fnv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/oahash.o: ../../../../v2_03b/framework/tcpip/src/oahash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/oahash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/oahash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/oahash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/oahash.o.d" -o ${OBJECTDIR}/_ext/1836803193/oahash.o ../../../../v2_03b/framework/tcpip/src/oahash.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o: ../../../../v2_03b/framework/tcpip/src/tcpip_helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o ../../../../v2_03b/framework/tcpip/src/tcpip_helpers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_manager.o: ../../../../v2_03b/framework/tcpip/src/tcpip_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_manager.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o ../../../../v2_03b/framework/tcpip/src/tcpip_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_notify.o: ../../../../v2_03b/framework/tcpip/src/tcpip_notify.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_notify.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_notify.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o ../../../../v2_03b/framework/tcpip/src/tcpip_notify.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_packet.o: ../../../../v2_03b/framework/tcpip/src/tcpip_packet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_packet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_packet.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o ../../../../v2_03b/framework/tcpip/src/tcpip_packet.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o: ../src/system_config/default/framework/net/pres/net_pres_enc_glue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1278673032" 
	@${RM} ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o.d" -o ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o ../src/system_config/default/framework/net/pres/net_pres_enc_glue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/68765530/sys_reset.o: ../src/system_config/default/framework/system/reset/src/sys_reset.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/68765530" 
	@${RM} ${OBJECTDIR}/_ext/68765530/sys_reset.o.d 
	@${RM} ${OBJECTDIR}/_ext/68765530/sys_reset.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/68765530/sys_reset.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/68765530/sys_reset.o.d" -o ${OBJECTDIR}/_ext/68765530/sys_reset.o ../src/system_config/default/framework/system/reset/src/sys_reset.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/app_command.o: ../src/app_command.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_command.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_command.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app_command.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/app_command.o.d" -o ${OBJECTDIR}/_ext/1360937237/app_command.o ../src/app_command.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1749672254/drv_ethmac.o: ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1749672254" 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1749672254/drv_ethmac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1749672254/drv_ethmac.o.d" -o ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o: ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1749672254" 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o.d" -o ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/573518448/drv_ethphy.o: ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_ethphy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/573518448" 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_ethphy.o.d 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_ethphy.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/573518448/drv_ethphy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/573518448/drv_ethphy.o.d" -o ${OBJECTDIR}/_ext/573518448/drv_ethphy.o ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_ethphy.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o: ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_extphy_smsc8720.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/573518448" 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o.d 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o.d" -o ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8720.o ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_extphy_smsc8720.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1568515672/drv_miim.o: ../../../../v2_03b/framework/driver/miim/src/dynamic/drv_miim.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1568515672" 
	@${RM} ${OBJECTDIR}/_ext/1568515672/drv_miim.o.d 
	@${RM} ${OBJECTDIR}/_ext/1568515672/drv_miim.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1568515672/drv_miim.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1568515672/drv_miim.o.d" -o ${OBJECTDIR}/_ext/1568515672/drv_miim.o ../../../../v2_03b/framework/driver/miim/src/dynamic/drv_miim.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/528688037/drv_tmr.o: ../../../../v2_03b/framework/driver/tmr/src/dynamic/drv_tmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/528688037" 
	@${RM} ${OBJECTDIR}/_ext/528688037/drv_tmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/528688037/drv_tmr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/528688037/drv_tmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/528688037/drv_tmr.o.d" -o ${OBJECTDIR}/_ext/528688037/drv_tmr.o ../../../../v2_03b/framework/driver/tmr/src/dynamic/drv_tmr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/427015431/drv_usart.o: ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427015431" 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/427015431/drv_usart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/427015431/drv_usart.o.d" -o ${OBJECTDIR}/_ext/427015431/drv_usart.o ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o: ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_buffer_queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427015431" 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o.d" -o ${OBJECTDIR}/_ext/427015431/drv_usart_buffer_queue.o ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_buffer_queue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o: ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_read_write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427015431" 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o.d 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o.d" -o ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_read_write.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2146114523/net_pres.o: ../../../../v2_03b/framework/net/pres/src/net_pres.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2146114523" 
	@${RM} ${OBJECTDIR}/_ext/2146114523/net_pres.o.d 
	@${RM} ${OBJECTDIR}/_ext/2146114523/net_pres.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2146114523/net_pres.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/2146114523/net_pres.o.d" -o ${OBJECTDIR}/_ext/2146114523/net_pres.o ../../../../v2_03b/framework/net/pres/src/net_pres.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1167192164/sys_command.o: ../../../../v2_03b/framework/system/command/src/sys_command.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1167192164" 
	@${RM} ${OBJECTDIR}/_ext/1167192164/sys_command.o.d 
	@${RM} ${OBJECTDIR}/_ext/1167192164/sys_command.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1167192164/sys_command.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1167192164/sys_command.o.d" -o ${OBJECTDIR}/_ext/1167192164/sys_command.o ../../../../v2_03b/framework/system/command/src/sys_command.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/710479984/sys_console.o: ../../../../v2_03b/framework/system/console/src/sys_console.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/710479984" 
	@${RM} ${OBJECTDIR}/_ext/710479984/sys_console.o.d 
	@${RM} ${OBJECTDIR}/_ext/710479984/sys_console.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/710479984/sys_console.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/710479984/sys_console.o.d" -o ${OBJECTDIR}/_ext/710479984/sys_console.o ../../../../v2_03b/framework/system/console/src/sys_console.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/710479984/sys_console_uart.o: ../../../../v2_03b/framework/system/console/src/sys_console_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/710479984" 
	@${RM} ${OBJECTDIR}/_ext/710479984/sys_console_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/710479984/sys_console_uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/710479984/sys_console_uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/710479984/sys_console_uart.o.d" -o ${OBJECTDIR}/_ext/710479984/sys_console_uart.o ../../../../v2_03b/framework/system/console/src/sys_console_uart.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/429005716/sys_debug.o: ../../../../v2_03b/framework/system/debug/src/sys_debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/429005716" 
	@${RM} ${OBJECTDIR}/_ext/429005716/sys_debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/429005716/sys_debug.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/429005716/sys_debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/429005716/sys_debug.o.d" -o ${OBJECTDIR}/_ext/429005716/sys_debug.o ../../../../v2_03b/framework/system/debug/src/sys_debug.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o: ../../../../v2_03b/framework/system/int/src/sys_int_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1670183176" 
	@${RM} ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o ../../../../v2_03b/framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1584847572/sys_random.o: ../../../../v2_03b/framework/system/random/src/sys_random.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1584847572" 
	@${RM} ${OBJECTDIR}/_ext/1584847572/sys_random.o.d 
	@${RM} ${OBJECTDIR}/_ext/1584847572/sys_random.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1584847572/sys_random.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1584847572/sys_random.o.d" -o ${OBJECTDIR}/_ext/1584847572/sys_random.o ../../../../v2_03b/framework/system/random/src/sys_random.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1482654414/sys_tmr.o: ../../../../v2_03b/framework/system/tmr/src/sys_tmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1482654414" 
	@${RM} ${OBJECTDIR}/_ext/1482654414/sys_tmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1482654414/sys_tmr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1482654414/sys_tmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1482654414/sys_tmr.o.d" -o ${OBJECTDIR}/_ext/1482654414/sys_tmr.o ../../../../v2_03b/framework/system/tmr/src/sys_tmr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/157393855/helpers.o: ../../../../v2_03b/framework/tcpip/src/common/helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/157393855" 
	@${RM} ${OBJECTDIR}/_ext/157393855/helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/157393855/helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/157393855/helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/157393855/helpers.o.d" -o ${OBJECTDIR}/_ext/157393855/helpers.o ../../../../v2_03b/framework/tcpip/src/common/helpers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/ipv4.o: ../../../../v2_03b/framework/tcpip/src/ipv4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/ipv4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/ipv4.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/ipv4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/ipv4.o.d" -o ${OBJECTDIR}/_ext/1836803193/ipv4.o ../../../../v2_03b/framework/tcpip/src/ipv4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcp.o: ../../../../v2_03b/framework/tcpip/src/tcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcp.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcp.o ../../../../v2_03b/framework/tcpip/src/tcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/udp.o: ../../../../v2_03b/framework/tcpip/src/udp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/udp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/udp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/udp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/udp.o.d" -o ${OBJECTDIR}/_ext/1836803193/udp.o ../../../../v2_03b/framework/tcpip/src/udp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o: ../../../../v2_03b/framework/tcpip/src/tcpip_heap_alloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o ../../../../v2_03b/framework/tcpip/src/tcpip_heap_alloc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o: ../../../../v2_03b/framework/tcpip/src/tcpip_heap_internal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o ../../../../v2_03b/framework/tcpip/src/tcpip_heap_internal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/arp.o: ../../../../v2_03b/framework/tcpip/src/arp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/arp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/arp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/arp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/arp.o.d" -o ${OBJECTDIR}/_ext/1836803193/arp.o ../../../../v2_03b/framework/tcpip/src/arp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/dhcp.o: ../../../../v2_03b/framework/tcpip/src/dhcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dhcp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dhcp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/dhcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/dhcp.o.d" -o ${OBJECTDIR}/_ext/1836803193/dhcp.o ../../../../v2_03b/framework/tcpip/src/dhcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/dns.o: ../../../../v2_03b/framework/tcpip/src/dns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dns.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/dns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/dns.o.d" -o ${OBJECTDIR}/_ext/1836803193/dns.o ../../../../v2_03b/framework/tcpip/src/dns.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/icmp.o: ../../../../v2_03b/framework/tcpip/src/icmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/icmp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/icmp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/icmp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/icmp.o.d" -o ${OBJECTDIR}/_ext/1836803193/icmp.o ../../../../v2_03b/framework/tcpip/src/icmp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/nbns.o: ../../../../v2_03b/framework/tcpip/src/nbns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/nbns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/nbns.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/nbns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/nbns.o.d" -o ${OBJECTDIR}/_ext/1836803193/nbns.o ../../../../v2_03b/framework/tcpip/src/nbns.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o: ../../../../v2_03b/framework/tcpip/src/zero_conf_helper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o.d" -o ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o ../../../../v2_03b/framework/tcpip/src/zero_conf_helper.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o: ../../../../v2_03b/framework/tcpip/src/zero_conf_link_local.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o.d" -o ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o ../../../../v2_03b/framework/tcpip/src/zero_conf_link_local.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_announce.o: ../../../../v2_03b/framework/tcpip/src/tcpip_announce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_announce.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_announce.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o ../../../../v2_03b/framework/tcpip/src/tcpip_announce.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_commands.o: ../../../../v2_03b/framework/tcpip/src/tcpip_commands.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_commands.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_commands.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_commands.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_commands.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_commands.o ../../../../v2_03b/framework/tcpip/src/tcpip_commands.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/hash_fnv.o: ../../../../v2_03b/framework/tcpip/src/hash_fnv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/hash_fnv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/hash_fnv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/hash_fnv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/hash_fnv.o.d" -o ${OBJECTDIR}/_ext/1836803193/hash_fnv.o ../../../../v2_03b/framework/tcpip/src/hash_fnv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/oahash.o: ../../../../v2_03b/framework/tcpip/src/oahash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/oahash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/oahash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/oahash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/oahash.o.d" -o ${OBJECTDIR}/_ext/1836803193/oahash.o ../../../../v2_03b/framework/tcpip/src/oahash.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o: ../../../../v2_03b/framework/tcpip/src/tcpip_helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o ../../../../v2_03b/framework/tcpip/src/tcpip_helpers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_manager.o: ../../../../v2_03b/framework/tcpip/src/tcpip_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_manager.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o ../../../../v2_03b/framework/tcpip/src/tcpip_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_notify.o: ../../../../v2_03b/framework/tcpip/src/tcpip_notify.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_notify.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_notify.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o ../../../../v2_03b/framework/tcpip/src/tcpip_notify.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_packet.o: ../../../../v2_03b/framework/tcpip/src/tcpip_packet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_packet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_packet.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o ../../../../v2_03b/framework/tcpip/src/tcpip_packet.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Ethernet.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../v2_03b/bin/framework/peripheral/PIC32MX795F512H_peripherals.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Ethernet.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\v2_03b\bin\framework\peripheral\PIC32MX795F512H_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_ICD3=1,--defsym=_min_heap_size=44960,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Ethernet.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../v2_03b/bin/framework/peripheral/PIC32MX795F512H_peripherals.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Ethernet.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\v2_03b\bin\framework\peripheral\PIC32MX795F512H_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=44960,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Ethernet.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
