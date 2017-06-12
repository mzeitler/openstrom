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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/openstorm.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/openstorm.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../../../v2_03b/framework/crypto/src/ecc.c ../../../../v2_03b/framework/crypto/src/arc4.c ../../../../v2_03b/framework/crypto/src/pwdbased.c ../../../../v2_03b/framework/crypto/src/tfm.c ../../../../v2_03b/framework/crypto/src/asn.c ../../../../v2_03b/framework/crypto/src/des3.c ../../../../v2_03b/framework/crypto/src/rsa.c ../../../../v2_03b/framework/crypto/src/aes.c ../../../../v2_03b/framework/crypto/src/md5.c ../../../../v2_03b/framework/crypto/src/sha.c ../../../../v2_03b/framework/crypto/src/sha256.c ../../../../v2_03b/framework/crypto/src/sha512.c ../../../../v2_03b/framework/crypto/src/hmac.c ../../../../v2_03b/framework/crypto/src/hash.c ../../../../v2_03b/framework/crypto/src/compress.c ../../../../v2_03b/framework/crypto/src/random.c ../../../../v2_03b/framework/crypto/src/crypto.c ../../../../v2_03b/framework/crypto/src/asm.c ../../../../v2_03b/framework/crypto/src/coding.c ../../../../v2_03b/framework/crypto/src/error.c ../../../../v2_03b/framework/crypto/src/integer.c ../../../../v2_03b/framework/crypto/src/logging.c ../../../../v2_03b/framework/crypto/src/memory.c ../../../../v2_03b/framework/crypto/src/misc.c ../../../../v2_03b/framework/crypto/src/port.c ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac.c ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac_lib.c ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_ethphy.c ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_extphy_smsc8740.c ../../../../v2_03b/framework/driver/miim/src/dynamic/drv_miim.c ../../../../v2_03b/framework/driver/tmr/src/dynamic/drv_tmr.c ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart.c ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_read_write.c ../../../../v2_03b/framework/net/pres/src/net_pres.c ../../../../v2_03b/framework/system/int/src/sys_int_pic32.c ../../../../v2_03b/framework/system/random/src/sys_random.c ../../../../v2_03b/framework/system/tmr/src/sys_tmr.c ../../../../v2_03b/framework/tcpip/src/ipv4.c ../../../../v2_03b/framework/tcpip/src/tcp.c ../../../../v2_03b/framework/tcpip/src/udp.c ../../../../v2_03b/framework/tcpip/src/tcpip_heap_alloc.c ../../../../v2_03b/framework/tcpip/src/tcpip_heap_internal.c ../../../../v2_03b/framework/tcpip/src/arp.c ../../../../v2_03b/framework/tcpip/src/dhcp.c ../../../../v2_03b/framework/tcpip/src/dns.c ../../../../v2_03b/framework/tcpip/src/icmp.c ../../../../v2_03b/framework/tcpip/src/nbns.c ../../../../v2_03b/framework/tcpip/src/sntp.c ../../../../v2_03b/framework/tcpip/src/zero_conf_helper.c ../../../../v2_03b/framework/tcpip/src/zero_conf_link_local.c ../../../../v2_03b/framework/tcpip/src/tcpip_announce.c ../../../../v2_03b/framework/tcpip/src/common/helpers.c ../../../../v2_03b/framework/tcpip/src/hash_fnv.c ../../../../v2_03b/framework/tcpip/src/oahash.c ../../../../v2_03b/framework/tcpip/src/tcpip_helpers.c ../../../../v2_03b/framework/tcpip/src/tcpip_helper_c32.S ../../../../v2_03b/framework/tcpip/src/tcpip_manager.c ../../../../v2_03b/framework/tcpip/src/tcpip_notify.c ../../../../v2_03b/framework/tcpip/src/tcpip_packet.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/crl.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/internal.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/io.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/keys.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/ocsp.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/sniffer.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/ssl.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/tls.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/asm.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/blake2b.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/camellia.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/chacha.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/chacha20_poly1305.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/curve25519.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/dh.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/dsa.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ecc_fp.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ed25519.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/fe_low_mem.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/fe_operations.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ge_low_mem.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ge_operations.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/hc128.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/md2.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/md4.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/pkcs7.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/poly1305.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/rabbit.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ripemd.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/misc.c ../src/app.c ../src/system_config/default/framework/net/pres/net_pres_enc_glue.c ../src/system_config/default/framework/net/pres/net_pres_cert_store.c ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/main.c ../src/system_config/default/system_tasks.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/595346758/ecc.o ${OBJECTDIR}/_ext/595346758/arc4.o ${OBJECTDIR}/_ext/595346758/pwdbased.o ${OBJECTDIR}/_ext/595346758/tfm.o ${OBJECTDIR}/_ext/595346758/asn.o ${OBJECTDIR}/_ext/595346758/des3.o ${OBJECTDIR}/_ext/595346758/rsa.o ${OBJECTDIR}/_ext/595346758/aes.o ${OBJECTDIR}/_ext/595346758/md5.o ${OBJECTDIR}/_ext/595346758/sha.o ${OBJECTDIR}/_ext/595346758/sha256.o ${OBJECTDIR}/_ext/595346758/sha512.o ${OBJECTDIR}/_ext/595346758/hmac.o ${OBJECTDIR}/_ext/595346758/hash.o ${OBJECTDIR}/_ext/595346758/compress.o ${OBJECTDIR}/_ext/595346758/random.o ${OBJECTDIR}/_ext/595346758/crypto.o ${OBJECTDIR}/_ext/595346758/asm.o ${OBJECTDIR}/_ext/595346758/coding.o ${OBJECTDIR}/_ext/595346758/error.o ${OBJECTDIR}/_ext/595346758/integer.o ${OBJECTDIR}/_ext/595346758/logging.o ${OBJECTDIR}/_ext/595346758/memory.o ${OBJECTDIR}/_ext/595346758/misc.o ${OBJECTDIR}/_ext/595346758/port.o ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o ${OBJECTDIR}/_ext/573518448/drv_ethphy.o ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o ${OBJECTDIR}/_ext/1568515672/drv_miim.o ${OBJECTDIR}/_ext/528688037/drv_tmr.o ${OBJECTDIR}/_ext/427015431/drv_usart.o ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o ${OBJECTDIR}/_ext/2146114523/net_pres.o ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o ${OBJECTDIR}/_ext/1584847572/sys_random.o ${OBJECTDIR}/_ext/1482654414/sys_tmr.o ${OBJECTDIR}/_ext/1836803193/ipv4.o ${OBJECTDIR}/_ext/1836803193/tcp.o ${OBJECTDIR}/_ext/1836803193/udp.o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o ${OBJECTDIR}/_ext/1836803193/arp.o ${OBJECTDIR}/_ext/1836803193/dhcp.o ${OBJECTDIR}/_ext/1836803193/dns.o ${OBJECTDIR}/_ext/1836803193/icmp.o ${OBJECTDIR}/_ext/1836803193/nbns.o ${OBJECTDIR}/_ext/1836803193/sntp.o ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o ${OBJECTDIR}/_ext/157393855/helpers.o ${OBJECTDIR}/_ext/1836803193/hash_fnv.o ${OBJECTDIR}/_ext/1836803193/oahash.o ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o ${OBJECTDIR}/_ext/359630028/crl.o ${OBJECTDIR}/_ext/359630028/internal.o ${OBJECTDIR}/_ext/359630028/io.o ${OBJECTDIR}/_ext/359630028/keys.o ${OBJECTDIR}/_ext/359630028/ocsp.o ${OBJECTDIR}/_ext/359630028/sniffer.o ${OBJECTDIR}/_ext/359630028/ssl.o ${OBJECTDIR}/_ext/359630028/tls.o ${OBJECTDIR}/_ext/1437400831/asm.o ${OBJECTDIR}/_ext/1437400831/blake2b.o ${OBJECTDIR}/_ext/1437400831/camellia.o ${OBJECTDIR}/_ext/1437400831/chacha.o ${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o ${OBJECTDIR}/_ext/1437400831/curve25519.o ${OBJECTDIR}/_ext/1437400831/dh.o ${OBJECTDIR}/_ext/1437400831/dsa.o ${OBJECTDIR}/_ext/1437400831/ecc_fp.o ${OBJECTDIR}/_ext/1437400831/ed25519.o ${OBJECTDIR}/_ext/1437400831/fe_low_mem.o ${OBJECTDIR}/_ext/1437400831/fe_operations.o ${OBJECTDIR}/_ext/1437400831/ge_low_mem.o ${OBJECTDIR}/_ext/1437400831/ge_operations.o ${OBJECTDIR}/_ext/1437400831/hc128.o ${OBJECTDIR}/_ext/1437400831/md2.o ${OBJECTDIR}/_ext/1437400831/md4.o ${OBJECTDIR}/_ext/1437400831/pkcs7.o ${OBJECTDIR}/_ext/1437400831/poly1305.o ${OBJECTDIR}/_ext/1437400831/rabbit.o ${OBJECTDIR}/_ext/1437400831/ripemd.o ${OBJECTDIR}/_ext/1437400831/misc.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o ${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/595346758/ecc.o.d ${OBJECTDIR}/_ext/595346758/arc4.o.d ${OBJECTDIR}/_ext/595346758/pwdbased.o.d ${OBJECTDIR}/_ext/595346758/tfm.o.d ${OBJECTDIR}/_ext/595346758/asn.o.d ${OBJECTDIR}/_ext/595346758/des3.o.d ${OBJECTDIR}/_ext/595346758/rsa.o.d ${OBJECTDIR}/_ext/595346758/aes.o.d ${OBJECTDIR}/_ext/595346758/md5.o.d ${OBJECTDIR}/_ext/595346758/sha.o.d ${OBJECTDIR}/_ext/595346758/sha256.o.d ${OBJECTDIR}/_ext/595346758/sha512.o.d ${OBJECTDIR}/_ext/595346758/hmac.o.d ${OBJECTDIR}/_ext/595346758/hash.o.d ${OBJECTDIR}/_ext/595346758/compress.o.d ${OBJECTDIR}/_ext/595346758/random.o.d ${OBJECTDIR}/_ext/595346758/crypto.o.d ${OBJECTDIR}/_ext/595346758/asm.o.d ${OBJECTDIR}/_ext/595346758/coding.o.d ${OBJECTDIR}/_ext/595346758/error.o.d ${OBJECTDIR}/_ext/595346758/integer.o.d ${OBJECTDIR}/_ext/595346758/logging.o.d ${OBJECTDIR}/_ext/595346758/memory.o.d ${OBJECTDIR}/_ext/595346758/misc.o.d ${OBJECTDIR}/_ext/595346758/port.o.d ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o.d ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o.d ${OBJECTDIR}/_ext/573518448/drv_ethphy.o.d ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o.d ${OBJECTDIR}/_ext/1568515672/drv_miim.o.d ${OBJECTDIR}/_ext/528688037/drv_tmr.o.d ${OBJECTDIR}/_ext/427015431/drv_usart.o.d ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o.d ${OBJECTDIR}/_ext/2146114523/net_pres.o.d ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o.d ${OBJECTDIR}/_ext/1584847572/sys_random.o.d ${OBJECTDIR}/_ext/1482654414/sys_tmr.o.d ${OBJECTDIR}/_ext/1836803193/ipv4.o.d ${OBJECTDIR}/_ext/1836803193/tcp.o.d ${OBJECTDIR}/_ext/1836803193/udp.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o.d ${OBJECTDIR}/_ext/1836803193/arp.o.d ${OBJECTDIR}/_ext/1836803193/dhcp.o.d ${OBJECTDIR}/_ext/1836803193/dns.o.d ${OBJECTDIR}/_ext/1836803193/icmp.o.d ${OBJECTDIR}/_ext/1836803193/nbns.o.d ${OBJECTDIR}/_ext/1836803193/sntp.o.d ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o.d ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o.d ${OBJECTDIR}/_ext/157393855/helpers.o.d ${OBJECTDIR}/_ext/1836803193/hash_fnv.o.d ${OBJECTDIR}/_ext/1836803193/oahash.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o.d ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o.d ${OBJECTDIR}/_ext/359630028/crl.o.d ${OBJECTDIR}/_ext/359630028/internal.o.d ${OBJECTDIR}/_ext/359630028/io.o.d ${OBJECTDIR}/_ext/359630028/keys.o.d ${OBJECTDIR}/_ext/359630028/ocsp.o.d ${OBJECTDIR}/_ext/359630028/sniffer.o.d ${OBJECTDIR}/_ext/359630028/ssl.o.d ${OBJECTDIR}/_ext/359630028/tls.o.d ${OBJECTDIR}/_ext/1437400831/asm.o.d ${OBJECTDIR}/_ext/1437400831/blake2b.o.d ${OBJECTDIR}/_ext/1437400831/camellia.o.d ${OBJECTDIR}/_ext/1437400831/chacha.o.d ${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o.d ${OBJECTDIR}/_ext/1437400831/curve25519.o.d ${OBJECTDIR}/_ext/1437400831/dh.o.d ${OBJECTDIR}/_ext/1437400831/dsa.o.d ${OBJECTDIR}/_ext/1437400831/ecc_fp.o.d ${OBJECTDIR}/_ext/1437400831/ed25519.o.d ${OBJECTDIR}/_ext/1437400831/fe_low_mem.o.d ${OBJECTDIR}/_ext/1437400831/fe_operations.o.d ${OBJECTDIR}/_ext/1437400831/ge_low_mem.o.d ${OBJECTDIR}/_ext/1437400831/ge_operations.o.d ${OBJECTDIR}/_ext/1437400831/hc128.o.d ${OBJECTDIR}/_ext/1437400831/md2.o.d ${OBJECTDIR}/_ext/1437400831/md4.o.d ${OBJECTDIR}/_ext/1437400831/pkcs7.o.d ${OBJECTDIR}/_ext/1437400831/poly1305.o.d ${OBJECTDIR}/_ext/1437400831/rabbit.o.d ${OBJECTDIR}/_ext/1437400831/ripemd.o.d ${OBJECTDIR}/_ext/1437400831/misc.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o.d ${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o.d ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d ${OBJECTDIR}/_ext/1688732426/system_init.o.d ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/595346758/ecc.o ${OBJECTDIR}/_ext/595346758/arc4.o ${OBJECTDIR}/_ext/595346758/pwdbased.o ${OBJECTDIR}/_ext/595346758/tfm.o ${OBJECTDIR}/_ext/595346758/asn.o ${OBJECTDIR}/_ext/595346758/des3.o ${OBJECTDIR}/_ext/595346758/rsa.o ${OBJECTDIR}/_ext/595346758/aes.o ${OBJECTDIR}/_ext/595346758/md5.o ${OBJECTDIR}/_ext/595346758/sha.o ${OBJECTDIR}/_ext/595346758/sha256.o ${OBJECTDIR}/_ext/595346758/sha512.o ${OBJECTDIR}/_ext/595346758/hmac.o ${OBJECTDIR}/_ext/595346758/hash.o ${OBJECTDIR}/_ext/595346758/compress.o ${OBJECTDIR}/_ext/595346758/random.o ${OBJECTDIR}/_ext/595346758/crypto.o ${OBJECTDIR}/_ext/595346758/asm.o ${OBJECTDIR}/_ext/595346758/coding.o ${OBJECTDIR}/_ext/595346758/error.o ${OBJECTDIR}/_ext/595346758/integer.o ${OBJECTDIR}/_ext/595346758/logging.o ${OBJECTDIR}/_ext/595346758/memory.o ${OBJECTDIR}/_ext/595346758/misc.o ${OBJECTDIR}/_ext/595346758/port.o ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o ${OBJECTDIR}/_ext/573518448/drv_ethphy.o ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o ${OBJECTDIR}/_ext/1568515672/drv_miim.o ${OBJECTDIR}/_ext/528688037/drv_tmr.o ${OBJECTDIR}/_ext/427015431/drv_usart.o ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o ${OBJECTDIR}/_ext/2146114523/net_pres.o ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o ${OBJECTDIR}/_ext/1584847572/sys_random.o ${OBJECTDIR}/_ext/1482654414/sys_tmr.o ${OBJECTDIR}/_ext/1836803193/ipv4.o ${OBJECTDIR}/_ext/1836803193/tcp.o ${OBJECTDIR}/_ext/1836803193/udp.o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o ${OBJECTDIR}/_ext/1836803193/arp.o ${OBJECTDIR}/_ext/1836803193/dhcp.o ${OBJECTDIR}/_ext/1836803193/dns.o ${OBJECTDIR}/_ext/1836803193/icmp.o ${OBJECTDIR}/_ext/1836803193/nbns.o ${OBJECTDIR}/_ext/1836803193/sntp.o ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o ${OBJECTDIR}/_ext/157393855/helpers.o ${OBJECTDIR}/_ext/1836803193/hash_fnv.o ${OBJECTDIR}/_ext/1836803193/oahash.o ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o ${OBJECTDIR}/_ext/359630028/crl.o ${OBJECTDIR}/_ext/359630028/internal.o ${OBJECTDIR}/_ext/359630028/io.o ${OBJECTDIR}/_ext/359630028/keys.o ${OBJECTDIR}/_ext/359630028/ocsp.o ${OBJECTDIR}/_ext/359630028/sniffer.o ${OBJECTDIR}/_ext/359630028/ssl.o ${OBJECTDIR}/_ext/359630028/tls.o ${OBJECTDIR}/_ext/1437400831/asm.o ${OBJECTDIR}/_ext/1437400831/blake2b.o ${OBJECTDIR}/_ext/1437400831/camellia.o ${OBJECTDIR}/_ext/1437400831/chacha.o ${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o ${OBJECTDIR}/_ext/1437400831/curve25519.o ${OBJECTDIR}/_ext/1437400831/dh.o ${OBJECTDIR}/_ext/1437400831/dsa.o ${OBJECTDIR}/_ext/1437400831/ecc_fp.o ${OBJECTDIR}/_ext/1437400831/ed25519.o ${OBJECTDIR}/_ext/1437400831/fe_low_mem.o ${OBJECTDIR}/_ext/1437400831/fe_operations.o ${OBJECTDIR}/_ext/1437400831/ge_low_mem.o ${OBJECTDIR}/_ext/1437400831/ge_operations.o ${OBJECTDIR}/_ext/1437400831/hc128.o ${OBJECTDIR}/_ext/1437400831/md2.o ${OBJECTDIR}/_ext/1437400831/md4.o ${OBJECTDIR}/_ext/1437400831/pkcs7.o ${OBJECTDIR}/_ext/1437400831/poly1305.o ${OBJECTDIR}/_ext/1437400831/rabbit.o ${OBJECTDIR}/_ext/1437400831/ripemd.o ${OBJECTDIR}/_ext/1437400831/misc.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o ${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o

# Source Files
SOURCEFILES=../../../../v2_03b/framework/crypto/src/ecc.c ../../../../v2_03b/framework/crypto/src/arc4.c ../../../../v2_03b/framework/crypto/src/pwdbased.c ../../../../v2_03b/framework/crypto/src/tfm.c ../../../../v2_03b/framework/crypto/src/asn.c ../../../../v2_03b/framework/crypto/src/des3.c ../../../../v2_03b/framework/crypto/src/rsa.c ../../../../v2_03b/framework/crypto/src/aes.c ../../../../v2_03b/framework/crypto/src/md5.c ../../../../v2_03b/framework/crypto/src/sha.c ../../../../v2_03b/framework/crypto/src/sha256.c ../../../../v2_03b/framework/crypto/src/sha512.c ../../../../v2_03b/framework/crypto/src/hmac.c ../../../../v2_03b/framework/crypto/src/hash.c ../../../../v2_03b/framework/crypto/src/compress.c ../../../../v2_03b/framework/crypto/src/random.c ../../../../v2_03b/framework/crypto/src/crypto.c ../../../../v2_03b/framework/crypto/src/asm.c ../../../../v2_03b/framework/crypto/src/coding.c ../../../../v2_03b/framework/crypto/src/error.c ../../../../v2_03b/framework/crypto/src/integer.c ../../../../v2_03b/framework/crypto/src/logging.c ../../../../v2_03b/framework/crypto/src/memory.c ../../../../v2_03b/framework/crypto/src/misc.c ../../../../v2_03b/framework/crypto/src/port.c ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac.c ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac_lib.c ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_ethphy.c ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_extphy_smsc8740.c ../../../../v2_03b/framework/driver/miim/src/dynamic/drv_miim.c ../../../../v2_03b/framework/driver/tmr/src/dynamic/drv_tmr.c ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart.c ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_read_write.c ../../../../v2_03b/framework/net/pres/src/net_pres.c ../../../../v2_03b/framework/system/int/src/sys_int_pic32.c ../../../../v2_03b/framework/system/random/src/sys_random.c ../../../../v2_03b/framework/system/tmr/src/sys_tmr.c ../../../../v2_03b/framework/tcpip/src/ipv4.c ../../../../v2_03b/framework/tcpip/src/tcp.c ../../../../v2_03b/framework/tcpip/src/udp.c ../../../../v2_03b/framework/tcpip/src/tcpip_heap_alloc.c ../../../../v2_03b/framework/tcpip/src/tcpip_heap_internal.c ../../../../v2_03b/framework/tcpip/src/arp.c ../../../../v2_03b/framework/tcpip/src/dhcp.c ../../../../v2_03b/framework/tcpip/src/dns.c ../../../../v2_03b/framework/tcpip/src/icmp.c ../../../../v2_03b/framework/tcpip/src/nbns.c ../../../../v2_03b/framework/tcpip/src/sntp.c ../../../../v2_03b/framework/tcpip/src/zero_conf_helper.c ../../../../v2_03b/framework/tcpip/src/zero_conf_link_local.c ../../../../v2_03b/framework/tcpip/src/tcpip_announce.c ../../../../v2_03b/framework/tcpip/src/common/helpers.c ../../../../v2_03b/framework/tcpip/src/hash_fnv.c ../../../../v2_03b/framework/tcpip/src/oahash.c ../../../../v2_03b/framework/tcpip/src/tcpip_helpers.c ../../../../v2_03b/framework/tcpip/src/tcpip_helper_c32.S ../../../../v2_03b/framework/tcpip/src/tcpip_manager.c ../../../../v2_03b/framework/tcpip/src/tcpip_notify.c ../../../../v2_03b/framework/tcpip/src/tcpip_packet.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/crl.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/internal.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/io.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/keys.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/ocsp.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/sniffer.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/ssl.c ../../../../v2_03b/third_party/tcpip/wolfssl/src/tls.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/asm.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/blake2b.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/camellia.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/chacha.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/chacha20_poly1305.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/curve25519.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/dh.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/dsa.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ecc_fp.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ed25519.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/fe_low_mem.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/fe_operations.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ge_low_mem.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ge_operations.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/hc128.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/md2.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/md4.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/pkcs7.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/poly1305.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/rabbit.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ripemd.c ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/misc.c ../src/app.c ../src/system_config/default/framework/net/pres/net_pres_enc_glue.c ../src/system_config/default/framework/net/pres/net_pres_cert_store.c ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/main.c ../src/system_config/default/system_tasks.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/openstorm.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.d" "${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.d"  -o ${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o ../../../../v2_03b/framework/tcpip/src/tcpip_helper_c32.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1836803193/tcpip_helper_c32.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
	
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
${OBJECTDIR}/_ext/595346758/ecc.o: ../../../../v2_03b/framework/crypto/src/ecc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/ecc.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/ecc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/ecc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/ecc.o.d" -o ${OBJECTDIR}/_ext/595346758/ecc.o ../../../../v2_03b/framework/crypto/src/ecc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/arc4.o: ../../../../v2_03b/framework/crypto/src/arc4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/arc4.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/arc4.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/arc4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/arc4.o.d" -o ${OBJECTDIR}/_ext/595346758/arc4.o ../../../../v2_03b/framework/crypto/src/arc4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/pwdbased.o: ../../../../v2_03b/framework/crypto/src/pwdbased.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/pwdbased.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/pwdbased.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/pwdbased.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/pwdbased.o.d" -o ${OBJECTDIR}/_ext/595346758/pwdbased.o ../../../../v2_03b/framework/crypto/src/pwdbased.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/tfm.o: ../../../../v2_03b/framework/crypto/src/tfm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/tfm.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/tfm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/tfm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/tfm.o.d" -o ${OBJECTDIR}/_ext/595346758/tfm.o ../../../../v2_03b/framework/crypto/src/tfm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/asn.o: ../../../../v2_03b/framework/crypto/src/asn.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/asn.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/asn.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/asn.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/asn.o.d" -o ${OBJECTDIR}/_ext/595346758/asn.o ../../../../v2_03b/framework/crypto/src/asn.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/des3.o: ../../../../v2_03b/framework/crypto/src/des3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/des3.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/des3.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/des3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/des3.o.d" -o ${OBJECTDIR}/_ext/595346758/des3.o ../../../../v2_03b/framework/crypto/src/des3.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/rsa.o: ../../../../v2_03b/framework/crypto/src/rsa.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/rsa.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/rsa.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/rsa.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/rsa.o.d" -o ${OBJECTDIR}/_ext/595346758/rsa.o ../../../../v2_03b/framework/crypto/src/rsa.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/aes.o: ../../../../v2_03b/framework/crypto/src/aes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/aes.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/aes.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/aes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/aes.o.d" -o ${OBJECTDIR}/_ext/595346758/aes.o ../../../../v2_03b/framework/crypto/src/aes.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/md5.o: ../../../../v2_03b/framework/crypto/src/md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/md5.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/md5.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/md5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/md5.o.d" -o ${OBJECTDIR}/_ext/595346758/md5.o ../../../../v2_03b/framework/crypto/src/md5.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/sha.o: ../../../../v2_03b/framework/crypto/src/sha.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/sha.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/sha.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/sha.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/sha.o.d" -o ${OBJECTDIR}/_ext/595346758/sha.o ../../../../v2_03b/framework/crypto/src/sha.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/sha256.o: ../../../../v2_03b/framework/crypto/src/sha256.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/sha256.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/sha256.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/sha256.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/sha256.o.d" -o ${OBJECTDIR}/_ext/595346758/sha256.o ../../../../v2_03b/framework/crypto/src/sha256.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/sha512.o: ../../../../v2_03b/framework/crypto/src/sha512.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/sha512.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/sha512.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/sha512.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/sha512.o.d" -o ${OBJECTDIR}/_ext/595346758/sha512.o ../../../../v2_03b/framework/crypto/src/sha512.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/hmac.o: ../../../../v2_03b/framework/crypto/src/hmac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/hmac.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/hmac.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/hmac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/hmac.o.d" -o ${OBJECTDIR}/_ext/595346758/hmac.o ../../../../v2_03b/framework/crypto/src/hmac.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/hash.o: ../../../../v2_03b/framework/crypto/src/hash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/hash.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/hash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/hash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/hash.o.d" -o ${OBJECTDIR}/_ext/595346758/hash.o ../../../../v2_03b/framework/crypto/src/hash.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/compress.o: ../../../../v2_03b/framework/crypto/src/compress.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/compress.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/compress.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/compress.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/compress.o.d" -o ${OBJECTDIR}/_ext/595346758/compress.o ../../../../v2_03b/framework/crypto/src/compress.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/random.o: ../../../../v2_03b/framework/crypto/src/random.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/random.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/random.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/random.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/random.o.d" -o ${OBJECTDIR}/_ext/595346758/random.o ../../../../v2_03b/framework/crypto/src/random.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/crypto.o: ../../../../v2_03b/framework/crypto/src/crypto.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/crypto.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/crypto.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/crypto.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/crypto.o.d" -o ${OBJECTDIR}/_ext/595346758/crypto.o ../../../../v2_03b/framework/crypto/src/crypto.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/asm.o: ../../../../v2_03b/framework/crypto/src/asm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/asm.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/asm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/asm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/asm.o.d" -o ${OBJECTDIR}/_ext/595346758/asm.o ../../../../v2_03b/framework/crypto/src/asm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/coding.o: ../../../../v2_03b/framework/crypto/src/coding.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/coding.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/coding.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/coding.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/coding.o.d" -o ${OBJECTDIR}/_ext/595346758/coding.o ../../../../v2_03b/framework/crypto/src/coding.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/error.o: ../../../../v2_03b/framework/crypto/src/error.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/error.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/error.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/error.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/error.o.d" -o ${OBJECTDIR}/_ext/595346758/error.o ../../../../v2_03b/framework/crypto/src/error.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/integer.o: ../../../../v2_03b/framework/crypto/src/integer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/integer.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/integer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/integer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/integer.o.d" -o ${OBJECTDIR}/_ext/595346758/integer.o ../../../../v2_03b/framework/crypto/src/integer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/logging.o: ../../../../v2_03b/framework/crypto/src/logging.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/logging.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/logging.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/logging.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/logging.o.d" -o ${OBJECTDIR}/_ext/595346758/logging.o ../../../../v2_03b/framework/crypto/src/logging.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/memory.o: ../../../../v2_03b/framework/crypto/src/memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/memory.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/memory.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/memory.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/memory.o.d" -o ${OBJECTDIR}/_ext/595346758/memory.o ../../../../v2_03b/framework/crypto/src/memory.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/misc.o: ../../../../v2_03b/framework/crypto/src/misc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/misc.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/misc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/misc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/misc.o.d" -o ${OBJECTDIR}/_ext/595346758/misc.o ../../../../v2_03b/framework/crypto/src/misc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/port.o: ../../../../v2_03b/framework/crypto/src/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/port.o.d" -o ${OBJECTDIR}/_ext/595346758/port.o ../../../../v2_03b/framework/crypto/src/port.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1749672254/drv_ethmac.o: ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1749672254" 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1749672254/drv_ethmac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1749672254/drv_ethmac.o.d" -o ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o: ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1749672254" 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o.d" -o ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/573518448/drv_ethphy.o: ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_ethphy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/573518448" 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_ethphy.o.d 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_ethphy.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/573518448/drv_ethphy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/573518448/drv_ethphy.o.d" -o ${OBJECTDIR}/_ext/573518448/drv_ethphy.o ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_ethphy.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o: ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_extphy_smsc8740.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/573518448" 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o.d 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o.d" -o ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_extphy_smsc8740.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1568515672/drv_miim.o: ../../../../v2_03b/framework/driver/miim/src/dynamic/drv_miim.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1568515672" 
	@${RM} ${OBJECTDIR}/_ext/1568515672/drv_miim.o.d 
	@${RM} ${OBJECTDIR}/_ext/1568515672/drv_miim.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1568515672/drv_miim.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1568515672/drv_miim.o.d" -o ${OBJECTDIR}/_ext/1568515672/drv_miim.o ../../../../v2_03b/framework/driver/miim/src/dynamic/drv_miim.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/528688037/drv_tmr.o: ../../../../v2_03b/framework/driver/tmr/src/dynamic/drv_tmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/528688037" 
	@${RM} ${OBJECTDIR}/_ext/528688037/drv_tmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/528688037/drv_tmr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/528688037/drv_tmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/528688037/drv_tmr.o.d" -o ${OBJECTDIR}/_ext/528688037/drv_tmr.o ../../../../v2_03b/framework/driver/tmr/src/dynamic/drv_tmr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/427015431/drv_usart.o: ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427015431" 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/427015431/drv_usart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/427015431/drv_usart.o.d" -o ${OBJECTDIR}/_ext/427015431/drv_usart.o ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o: ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_read_write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427015431" 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o.d 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o.d" -o ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_read_write.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2146114523/net_pres.o: ../../../../v2_03b/framework/net/pres/src/net_pres.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2146114523" 
	@${RM} ${OBJECTDIR}/_ext/2146114523/net_pres.o.d 
	@${RM} ${OBJECTDIR}/_ext/2146114523/net_pres.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2146114523/net_pres.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/2146114523/net_pres.o.d" -o ${OBJECTDIR}/_ext/2146114523/net_pres.o ../../../../v2_03b/framework/net/pres/src/net_pres.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o: ../../../../v2_03b/framework/system/int/src/sys_int_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1670183176" 
	@${RM} ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o ../../../../v2_03b/framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1584847572/sys_random.o: ../../../../v2_03b/framework/system/random/src/sys_random.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1584847572" 
	@${RM} ${OBJECTDIR}/_ext/1584847572/sys_random.o.d 
	@${RM} ${OBJECTDIR}/_ext/1584847572/sys_random.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1584847572/sys_random.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1584847572/sys_random.o.d" -o ${OBJECTDIR}/_ext/1584847572/sys_random.o ../../../../v2_03b/framework/system/random/src/sys_random.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1482654414/sys_tmr.o: ../../../../v2_03b/framework/system/tmr/src/sys_tmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1482654414" 
	@${RM} ${OBJECTDIR}/_ext/1482654414/sys_tmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1482654414/sys_tmr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1482654414/sys_tmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1482654414/sys_tmr.o.d" -o ${OBJECTDIR}/_ext/1482654414/sys_tmr.o ../../../../v2_03b/framework/system/tmr/src/sys_tmr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/ipv4.o: ../../../../v2_03b/framework/tcpip/src/ipv4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/ipv4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/ipv4.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/ipv4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/ipv4.o.d" -o ${OBJECTDIR}/_ext/1836803193/ipv4.o ../../../../v2_03b/framework/tcpip/src/ipv4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcp.o: ../../../../v2_03b/framework/tcpip/src/tcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcp.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcp.o ../../../../v2_03b/framework/tcpip/src/tcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/udp.o: ../../../../v2_03b/framework/tcpip/src/udp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/udp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/udp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/udp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/udp.o.d" -o ${OBJECTDIR}/_ext/1836803193/udp.o ../../../../v2_03b/framework/tcpip/src/udp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o: ../../../../v2_03b/framework/tcpip/src/tcpip_heap_alloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o ../../../../v2_03b/framework/tcpip/src/tcpip_heap_alloc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o: ../../../../v2_03b/framework/tcpip/src/tcpip_heap_internal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o ../../../../v2_03b/framework/tcpip/src/tcpip_heap_internal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/arp.o: ../../../../v2_03b/framework/tcpip/src/arp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/arp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/arp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/arp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/arp.o.d" -o ${OBJECTDIR}/_ext/1836803193/arp.o ../../../../v2_03b/framework/tcpip/src/arp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/dhcp.o: ../../../../v2_03b/framework/tcpip/src/dhcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dhcp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dhcp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/dhcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/dhcp.o.d" -o ${OBJECTDIR}/_ext/1836803193/dhcp.o ../../../../v2_03b/framework/tcpip/src/dhcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/dns.o: ../../../../v2_03b/framework/tcpip/src/dns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dns.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/dns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/dns.o.d" -o ${OBJECTDIR}/_ext/1836803193/dns.o ../../../../v2_03b/framework/tcpip/src/dns.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/icmp.o: ../../../../v2_03b/framework/tcpip/src/icmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/icmp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/icmp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/icmp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/icmp.o.d" -o ${OBJECTDIR}/_ext/1836803193/icmp.o ../../../../v2_03b/framework/tcpip/src/icmp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/nbns.o: ../../../../v2_03b/framework/tcpip/src/nbns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/nbns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/nbns.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/nbns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/nbns.o.d" -o ${OBJECTDIR}/_ext/1836803193/nbns.o ../../../../v2_03b/framework/tcpip/src/nbns.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/sntp.o: ../../../../v2_03b/framework/tcpip/src/sntp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/sntp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/sntp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/sntp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/sntp.o.d" -o ${OBJECTDIR}/_ext/1836803193/sntp.o ../../../../v2_03b/framework/tcpip/src/sntp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o: ../../../../v2_03b/framework/tcpip/src/zero_conf_helper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o.d" -o ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o ../../../../v2_03b/framework/tcpip/src/zero_conf_helper.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o: ../../../../v2_03b/framework/tcpip/src/zero_conf_link_local.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o.d" -o ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o ../../../../v2_03b/framework/tcpip/src/zero_conf_link_local.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_announce.o: ../../../../v2_03b/framework/tcpip/src/tcpip_announce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_announce.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_announce.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o ../../../../v2_03b/framework/tcpip/src/tcpip_announce.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/157393855/helpers.o: ../../../../v2_03b/framework/tcpip/src/common/helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/157393855" 
	@${RM} ${OBJECTDIR}/_ext/157393855/helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/157393855/helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/157393855/helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/157393855/helpers.o.d" -o ${OBJECTDIR}/_ext/157393855/helpers.o ../../../../v2_03b/framework/tcpip/src/common/helpers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/hash_fnv.o: ../../../../v2_03b/framework/tcpip/src/hash_fnv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/hash_fnv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/hash_fnv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/hash_fnv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/hash_fnv.o.d" -o ${OBJECTDIR}/_ext/1836803193/hash_fnv.o ../../../../v2_03b/framework/tcpip/src/hash_fnv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/oahash.o: ../../../../v2_03b/framework/tcpip/src/oahash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/oahash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/oahash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/oahash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/oahash.o.d" -o ${OBJECTDIR}/_ext/1836803193/oahash.o ../../../../v2_03b/framework/tcpip/src/oahash.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o: ../../../../v2_03b/framework/tcpip/src/tcpip_helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o ../../../../v2_03b/framework/tcpip/src/tcpip_helpers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_manager.o: ../../../../v2_03b/framework/tcpip/src/tcpip_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_manager.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o ../../../../v2_03b/framework/tcpip/src/tcpip_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_notify.o: ../../../../v2_03b/framework/tcpip/src/tcpip_notify.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_notify.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_notify.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o ../../../../v2_03b/framework/tcpip/src/tcpip_notify.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_packet.o: ../../../../v2_03b/framework/tcpip/src/tcpip_packet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_packet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_packet.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o ../../../../v2_03b/framework/tcpip/src/tcpip_packet.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/crl.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/crl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/crl.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/crl.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/crl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/crl.o.d" -o ${OBJECTDIR}/_ext/359630028/crl.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/crl.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/internal.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/internal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/internal.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/internal.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/internal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/internal.o.d" -o ${OBJECTDIR}/_ext/359630028/internal.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/internal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/io.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/io.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/io.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/io.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/io.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/io.o.d" -o ${OBJECTDIR}/_ext/359630028/io.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/io.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/keys.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/keys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/keys.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/keys.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/keys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/keys.o.d" -o ${OBJECTDIR}/_ext/359630028/keys.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/keys.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/ocsp.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/ocsp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/ocsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/ocsp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/ocsp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/ocsp.o.d" -o ${OBJECTDIR}/_ext/359630028/ocsp.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/ocsp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/sniffer.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/sniffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/sniffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/sniffer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/sniffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/sniffer.o.d" -o ${OBJECTDIR}/_ext/359630028/sniffer.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/sniffer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/ssl.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/ssl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/ssl.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/ssl.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/ssl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/ssl.o.d" -o ${OBJECTDIR}/_ext/359630028/ssl.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/ssl.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/tls.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/tls.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/tls.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/tls.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/tls.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/tls.o.d" -o ${OBJECTDIR}/_ext/359630028/tls.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/tls.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/asm.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/asm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/asm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/asm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/asm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/asm.o.d" -o ${OBJECTDIR}/_ext/1437400831/asm.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/asm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/blake2b.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/blake2b.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/blake2b.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/blake2b.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/blake2b.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/blake2b.o.d" -o ${OBJECTDIR}/_ext/1437400831/blake2b.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/blake2b.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/camellia.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/camellia.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/camellia.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/camellia.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/camellia.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/camellia.o.d" -o ${OBJECTDIR}/_ext/1437400831/camellia.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/camellia.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/chacha.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/chacha.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/chacha.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/chacha.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/chacha.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/chacha.o.d" -o ${OBJECTDIR}/_ext/1437400831/chacha.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/chacha.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/chacha20_poly1305.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o.d" -o ${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/chacha20_poly1305.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/curve25519.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/curve25519.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/curve25519.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/curve25519.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/curve25519.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/curve25519.o.d" -o ${OBJECTDIR}/_ext/1437400831/curve25519.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/curve25519.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/dh.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/dh.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/dh.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/dh.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/dh.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/dh.o.d" -o ${OBJECTDIR}/_ext/1437400831/dh.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/dh.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/dsa.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/dsa.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/dsa.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/dsa.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/dsa.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/dsa.o.d" -o ${OBJECTDIR}/_ext/1437400831/dsa.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/dsa.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/ecc_fp.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ecc_fp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ecc_fp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ecc_fp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/ecc_fp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/ecc_fp.o.d" -o ${OBJECTDIR}/_ext/1437400831/ecc_fp.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ecc_fp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/ed25519.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ed25519.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ed25519.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ed25519.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/ed25519.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/ed25519.o.d" -o ${OBJECTDIR}/_ext/1437400831/ed25519.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ed25519.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/fe_low_mem.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/fe_low_mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/fe_low_mem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/fe_low_mem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/fe_low_mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/fe_low_mem.o.d" -o ${OBJECTDIR}/_ext/1437400831/fe_low_mem.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/fe_low_mem.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/fe_operations.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/fe_operations.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/fe_operations.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/fe_operations.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/fe_operations.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/fe_operations.o.d" -o ${OBJECTDIR}/_ext/1437400831/fe_operations.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/fe_operations.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/ge_low_mem.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ge_low_mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ge_low_mem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ge_low_mem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/ge_low_mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/ge_low_mem.o.d" -o ${OBJECTDIR}/_ext/1437400831/ge_low_mem.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ge_low_mem.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/ge_operations.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ge_operations.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ge_operations.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ge_operations.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/ge_operations.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/ge_operations.o.d" -o ${OBJECTDIR}/_ext/1437400831/ge_operations.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ge_operations.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/hc128.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/hc128.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/hc128.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/hc128.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/hc128.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/hc128.o.d" -o ${OBJECTDIR}/_ext/1437400831/hc128.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/hc128.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/md2.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/md2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/md2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/md2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/md2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/md2.o.d" -o ${OBJECTDIR}/_ext/1437400831/md2.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/md2.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/md4.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/md4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/md4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/md4.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/md4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/md4.o.d" -o ${OBJECTDIR}/_ext/1437400831/md4.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/md4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/pkcs7.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/pkcs7.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/pkcs7.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/pkcs7.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/pkcs7.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/pkcs7.o.d" -o ${OBJECTDIR}/_ext/1437400831/pkcs7.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/pkcs7.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/poly1305.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/poly1305.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/poly1305.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/poly1305.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/poly1305.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/poly1305.o.d" -o ${OBJECTDIR}/_ext/1437400831/poly1305.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/poly1305.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/rabbit.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/rabbit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/rabbit.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/rabbit.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/rabbit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/rabbit.o.d" -o ${OBJECTDIR}/_ext/1437400831/rabbit.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/rabbit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/ripemd.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ripemd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ripemd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ripemd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/ripemd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/ripemd.o.d" -o ${OBJECTDIR}/_ext/1437400831/ripemd.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ripemd.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/misc.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/misc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/misc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/misc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/misc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/misc.o.d" -o ${OBJECTDIR}/_ext/1437400831/misc.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/misc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o: ../src/system_config/default/framework/net/pres/net_pres_enc_glue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1278673032" 
	@${RM} ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o.d" -o ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o ../src/system_config/default/framework/net/pres/net_pres_enc_glue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o: ../src/system_config/default/framework/net/pres/net_pres_cert_store.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1278673032" 
	@${RM} ${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o.d 
	@${RM} ${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o.d" -o ${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o ../src/system_config/default/framework/net/pres/net_pres_cert_store.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/595346758/ecc.o: ../../../../v2_03b/framework/crypto/src/ecc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/ecc.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/ecc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/ecc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/ecc.o.d" -o ${OBJECTDIR}/_ext/595346758/ecc.o ../../../../v2_03b/framework/crypto/src/ecc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/arc4.o: ../../../../v2_03b/framework/crypto/src/arc4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/arc4.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/arc4.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/arc4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/arc4.o.d" -o ${OBJECTDIR}/_ext/595346758/arc4.o ../../../../v2_03b/framework/crypto/src/arc4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/pwdbased.o: ../../../../v2_03b/framework/crypto/src/pwdbased.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/pwdbased.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/pwdbased.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/pwdbased.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/pwdbased.o.d" -o ${OBJECTDIR}/_ext/595346758/pwdbased.o ../../../../v2_03b/framework/crypto/src/pwdbased.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/tfm.o: ../../../../v2_03b/framework/crypto/src/tfm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/tfm.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/tfm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/tfm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/tfm.o.d" -o ${OBJECTDIR}/_ext/595346758/tfm.o ../../../../v2_03b/framework/crypto/src/tfm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/asn.o: ../../../../v2_03b/framework/crypto/src/asn.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/asn.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/asn.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/asn.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/asn.o.d" -o ${OBJECTDIR}/_ext/595346758/asn.o ../../../../v2_03b/framework/crypto/src/asn.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/des3.o: ../../../../v2_03b/framework/crypto/src/des3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/des3.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/des3.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/des3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/des3.o.d" -o ${OBJECTDIR}/_ext/595346758/des3.o ../../../../v2_03b/framework/crypto/src/des3.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/rsa.o: ../../../../v2_03b/framework/crypto/src/rsa.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/rsa.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/rsa.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/rsa.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/rsa.o.d" -o ${OBJECTDIR}/_ext/595346758/rsa.o ../../../../v2_03b/framework/crypto/src/rsa.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/aes.o: ../../../../v2_03b/framework/crypto/src/aes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/aes.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/aes.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/aes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/aes.o.d" -o ${OBJECTDIR}/_ext/595346758/aes.o ../../../../v2_03b/framework/crypto/src/aes.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/md5.o: ../../../../v2_03b/framework/crypto/src/md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/md5.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/md5.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/md5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/md5.o.d" -o ${OBJECTDIR}/_ext/595346758/md5.o ../../../../v2_03b/framework/crypto/src/md5.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/sha.o: ../../../../v2_03b/framework/crypto/src/sha.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/sha.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/sha.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/sha.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/sha.o.d" -o ${OBJECTDIR}/_ext/595346758/sha.o ../../../../v2_03b/framework/crypto/src/sha.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/sha256.o: ../../../../v2_03b/framework/crypto/src/sha256.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/sha256.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/sha256.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/sha256.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/sha256.o.d" -o ${OBJECTDIR}/_ext/595346758/sha256.o ../../../../v2_03b/framework/crypto/src/sha256.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/sha512.o: ../../../../v2_03b/framework/crypto/src/sha512.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/sha512.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/sha512.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/sha512.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/sha512.o.d" -o ${OBJECTDIR}/_ext/595346758/sha512.o ../../../../v2_03b/framework/crypto/src/sha512.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/hmac.o: ../../../../v2_03b/framework/crypto/src/hmac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/hmac.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/hmac.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/hmac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/hmac.o.d" -o ${OBJECTDIR}/_ext/595346758/hmac.o ../../../../v2_03b/framework/crypto/src/hmac.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/hash.o: ../../../../v2_03b/framework/crypto/src/hash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/hash.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/hash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/hash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/hash.o.d" -o ${OBJECTDIR}/_ext/595346758/hash.o ../../../../v2_03b/framework/crypto/src/hash.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/compress.o: ../../../../v2_03b/framework/crypto/src/compress.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/compress.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/compress.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/compress.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/compress.o.d" -o ${OBJECTDIR}/_ext/595346758/compress.o ../../../../v2_03b/framework/crypto/src/compress.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/random.o: ../../../../v2_03b/framework/crypto/src/random.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/random.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/random.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/random.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/random.o.d" -o ${OBJECTDIR}/_ext/595346758/random.o ../../../../v2_03b/framework/crypto/src/random.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/crypto.o: ../../../../v2_03b/framework/crypto/src/crypto.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/crypto.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/crypto.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/crypto.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/crypto.o.d" -o ${OBJECTDIR}/_ext/595346758/crypto.o ../../../../v2_03b/framework/crypto/src/crypto.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/asm.o: ../../../../v2_03b/framework/crypto/src/asm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/asm.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/asm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/asm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/asm.o.d" -o ${OBJECTDIR}/_ext/595346758/asm.o ../../../../v2_03b/framework/crypto/src/asm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/coding.o: ../../../../v2_03b/framework/crypto/src/coding.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/coding.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/coding.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/coding.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/coding.o.d" -o ${OBJECTDIR}/_ext/595346758/coding.o ../../../../v2_03b/framework/crypto/src/coding.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/error.o: ../../../../v2_03b/framework/crypto/src/error.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/error.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/error.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/error.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/error.o.d" -o ${OBJECTDIR}/_ext/595346758/error.o ../../../../v2_03b/framework/crypto/src/error.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/integer.o: ../../../../v2_03b/framework/crypto/src/integer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/integer.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/integer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/integer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/integer.o.d" -o ${OBJECTDIR}/_ext/595346758/integer.o ../../../../v2_03b/framework/crypto/src/integer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/logging.o: ../../../../v2_03b/framework/crypto/src/logging.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/logging.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/logging.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/logging.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/logging.o.d" -o ${OBJECTDIR}/_ext/595346758/logging.o ../../../../v2_03b/framework/crypto/src/logging.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/memory.o: ../../../../v2_03b/framework/crypto/src/memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/memory.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/memory.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/memory.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/memory.o.d" -o ${OBJECTDIR}/_ext/595346758/memory.o ../../../../v2_03b/framework/crypto/src/memory.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/misc.o: ../../../../v2_03b/framework/crypto/src/misc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/misc.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/misc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/misc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/misc.o.d" -o ${OBJECTDIR}/_ext/595346758/misc.o ../../../../v2_03b/framework/crypto/src/misc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/595346758/port.o: ../../../../v2_03b/framework/crypto/src/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/595346758" 
	@${RM} ${OBJECTDIR}/_ext/595346758/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/595346758/port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/595346758/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/595346758/port.o.d" -o ${OBJECTDIR}/_ext/595346758/port.o ../../../../v2_03b/framework/crypto/src/port.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1749672254/drv_ethmac.o: ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1749672254" 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1749672254/drv_ethmac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1749672254/drv_ethmac.o.d" -o ${OBJECTDIR}/_ext/1749672254/drv_ethmac.o ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o: ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1749672254" 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o.d" -o ${OBJECTDIR}/_ext/1749672254/drv_ethmac_lib.o ../../../../v2_03b/framework/driver/ethmac/src/dynamic/drv_ethmac_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/573518448/drv_ethphy.o: ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_ethphy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/573518448" 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_ethphy.o.d 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_ethphy.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/573518448/drv_ethphy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/573518448/drv_ethphy.o.d" -o ${OBJECTDIR}/_ext/573518448/drv_ethphy.o ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_ethphy.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o: ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_extphy_smsc8740.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/573518448" 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o.d 
	@${RM} ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o.d" -o ${OBJECTDIR}/_ext/573518448/drv_extphy_smsc8740.o ../../../../v2_03b/framework/driver/ethphy/src/dynamic/drv_extphy_smsc8740.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1568515672/drv_miim.o: ../../../../v2_03b/framework/driver/miim/src/dynamic/drv_miim.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1568515672" 
	@${RM} ${OBJECTDIR}/_ext/1568515672/drv_miim.o.d 
	@${RM} ${OBJECTDIR}/_ext/1568515672/drv_miim.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1568515672/drv_miim.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1568515672/drv_miim.o.d" -o ${OBJECTDIR}/_ext/1568515672/drv_miim.o ../../../../v2_03b/framework/driver/miim/src/dynamic/drv_miim.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/528688037/drv_tmr.o: ../../../../v2_03b/framework/driver/tmr/src/dynamic/drv_tmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/528688037" 
	@${RM} ${OBJECTDIR}/_ext/528688037/drv_tmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/528688037/drv_tmr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/528688037/drv_tmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/528688037/drv_tmr.o.d" -o ${OBJECTDIR}/_ext/528688037/drv_tmr.o ../../../../v2_03b/framework/driver/tmr/src/dynamic/drv_tmr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/427015431/drv_usart.o: ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427015431" 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/427015431/drv_usart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/427015431/drv_usart.o.d" -o ${OBJECTDIR}/_ext/427015431/drv_usart.o ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o: ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_read_write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427015431" 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o.d 
	@${RM} ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o.d" -o ${OBJECTDIR}/_ext/427015431/drv_usart_read_write.o ../../../../v2_03b/framework/driver/usart/src/dynamic/drv_usart_read_write.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2146114523/net_pres.o: ../../../../v2_03b/framework/net/pres/src/net_pres.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2146114523" 
	@${RM} ${OBJECTDIR}/_ext/2146114523/net_pres.o.d 
	@${RM} ${OBJECTDIR}/_ext/2146114523/net_pres.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2146114523/net_pres.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/2146114523/net_pres.o.d" -o ${OBJECTDIR}/_ext/2146114523/net_pres.o ../../../../v2_03b/framework/net/pres/src/net_pres.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o: ../../../../v2_03b/framework/system/int/src/sys_int_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1670183176" 
	@${RM} ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1670183176/sys_int_pic32.o ../../../../v2_03b/framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1584847572/sys_random.o: ../../../../v2_03b/framework/system/random/src/sys_random.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1584847572" 
	@${RM} ${OBJECTDIR}/_ext/1584847572/sys_random.o.d 
	@${RM} ${OBJECTDIR}/_ext/1584847572/sys_random.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1584847572/sys_random.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1584847572/sys_random.o.d" -o ${OBJECTDIR}/_ext/1584847572/sys_random.o ../../../../v2_03b/framework/system/random/src/sys_random.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1482654414/sys_tmr.o: ../../../../v2_03b/framework/system/tmr/src/sys_tmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1482654414" 
	@${RM} ${OBJECTDIR}/_ext/1482654414/sys_tmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1482654414/sys_tmr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1482654414/sys_tmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1482654414/sys_tmr.o.d" -o ${OBJECTDIR}/_ext/1482654414/sys_tmr.o ../../../../v2_03b/framework/system/tmr/src/sys_tmr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/ipv4.o: ../../../../v2_03b/framework/tcpip/src/ipv4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/ipv4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/ipv4.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/ipv4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/ipv4.o.d" -o ${OBJECTDIR}/_ext/1836803193/ipv4.o ../../../../v2_03b/framework/tcpip/src/ipv4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcp.o: ../../../../v2_03b/framework/tcpip/src/tcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcp.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcp.o ../../../../v2_03b/framework/tcpip/src/tcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/udp.o: ../../../../v2_03b/framework/tcpip/src/udp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/udp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/udp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/udp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/udp.o.d" -o ${OBJECTDIR}/_ext/1836803193/udp.o ../../../../v2_03b/framework/tcpip/src/udp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o: ../../../../v2_03b/framework/tcpip/src/tcpip_heap_alloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_alloc.o ../../../../v2_03b/framework/tcpip/src/tcpip_heap_alloc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o: ../../../../v2_03b/framework/tcpip/src/tcpip_heap_internal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_heap_internal.o ../../../../v2_03b/framework/tcpip/src/tcpip_heap_internal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/arp.o: ../../../../v2_03b/framework/tcpip/src/arp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/arp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/arp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/arp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/arp.o.d" -o ${OBJECTDIR}/_ext/1836803193/arp.o ../../../../v2_03b/framework/tcpip/src/arp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/dhcp.o: ../../../../v2_03b/framework/tcpip/src/dhcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dhcp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dhcp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/dhcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/dhcp.o.d" -o ${OBJECTDIR}/_ext/1836803193/dhcp.o ../../../../v2_03b/framework/tcpip/src/dhcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/dns.o: ../../../../v2_03b/framework/tcpip/src/dns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/dns.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/dns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/dns.o.d" -o ${OBJECTDIR}/_ext/1836803193/dns.o ../../../../v2_03b/framework/tcpip/src/dns.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/icmp.o: ../../../../v2_03b/framework/tcpip/src/icmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/icmp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/icmp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/icmp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/icmp.o.d" -o ${OBJECTDIR}/_ext/1836803193/icmp.o ../../../../v2_03b/framework/tcpip/src/icmp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/nbns.o: ../../../../v2_03b/framework/tcpip/src/nbns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/nbns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/nbns.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/nbns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/nbns.o.d" -o ${OBJECTDIR}/_ext/1836803193/nbns.o ../../../../v2_03b/framework/tcpip/src/nbns.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/sntp.o: ../../../../v2_03b/framework/tcpip/src/sntp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/sntp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/sntp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/sntp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/sntp.o.d" -o ${OBJECTDIR}/_ext/1836803193/sntp.o ../../../../v2_03b/framework/tcpip/src/sntp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o: ../../../../v2_03b/framework/tcpip/src/zero_conf_helper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o.d" -o ${OBJECTDIR}/_ext/1836803193/zero_conf_helper.o ../../../../v2_03b/framework/tcpip/src/zero_conf_helper.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o: ../../../../v2_03b/framework/tcpip/src/zero_conf_link_local.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o.d" -o ${OBJECTDIR}/_ext/1836803193/zero_conf_link_local.o ../../../../v2_03b/framework/tcpip/src/zero_conf_link_local.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_announce.o: ../../../../v2_03b/framework/tcpip/src/tcpip_announce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_announce.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_announce.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_announce.o ../../../../v2_03b/framework/tcpip/src/tcpip_announce.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/157393855/helpers.o: ../../../../v2_03b/framework/tcpip/src/common/helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/157393855" 
	@${RM} ${OBJECTDIR}/_ext/157393855/helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/157393855/helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/157393855/helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/157393855/helpers.o.d" -o ${OBJECTDIR}/_ext/157393855/helpers.o ../../../../v2_03b/framework/tcpip/src/common/helpers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/hash_fnv.o: ../../../../v2_03b/framework/tcpip/src/hash_fnv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/hash_fnv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/hash_fnv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/hash_fnv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/hash_fnv.o.d" -o ${OBJECTDIR}/_ext/1836803193/hash_fnv.o ../../../../v2_03b/framework/tcpip/src/hash_fnv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/oahash.o: ../../../../v2_03b/framework/tcpip/src/oahash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/oahash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/oahash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/oahash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/oahash.o.d" -o ${OBJECTDIR}/_ext/1836803193/oahash.o ../../../../v2_03b/framework/tcpip/src/oahash.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o: ../../../../v2_03b/framework/tcpip/src/tcpip_helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_helpers.o ../../../../v2_03b/framework/tcpip/src/tcpip_helpers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_manager.o: ../../../../v2_03b/framework/tcpip/src/tcpip_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_manager.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_manager.o ../../../../v2_03b/framework/tcpip/src/tcpip_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_notify.o: ../../../../v2_03b/framework/tcpip/src/tcpip_notify.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_notify.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_notify.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_notify.o ../../../../v2_03b/framework/tcpip/src/tcpip_notify.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1836803193/tcpip_packet.o: ../../../../v2_03b/framework/tcpip/src/tcpip_packet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1836803193" 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o.d 
	@${RM} ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1836803193/tcpip_packet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1836803193/tcpip_packet.o.d" -o ${OBJECTDIR}/_ext/1836803193/tcpip_packet.o ../../../../v2_03b/framework/tcpip/src/tcpip_packet.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/crl.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/crl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/crl.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/crl.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/crl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/crl.o.d" -o ${OBJECTDIR}/_ext/359630028/crl.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/crl.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/internal.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/internal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/internal.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/internal.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/internal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/internal.o.d" -o ${OBJECTDIR}/_ext/359630028/internal.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/internal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/io.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/io.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/io.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/io.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/io.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/io.o.d" -o ${OBJECTDIR}/_ext/359630028/io.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/io.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/keys.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/keys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/keys.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/keys.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/keys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/keys.o.d" -o ${OBJECTDIR}/_ext/359630028/keys.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/keys.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/ocsp.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/ocsp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/ocsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/ocsp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/ocsp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/ocsp.o.d" -o ${OBJECTDIR}/_ext/359630028/ocsp.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/ocsp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/sniffer.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/sniffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/sniffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/sniffer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/sniffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/sniffer.o.d" -o ${OBJECTDIR}/_ext/359630028/sniffer.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/sniffer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/ssl.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/ssl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/ssl.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/ssl.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/ssl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/ssl.o.d" -o ${OBJECTDIR}/_ext/359630028/ssl.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/ssl.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/359630028/tls.o: ../../../../v2_03b/third_party/tcpip/wolfssl/src/tls.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/359630028" 
	@${RM} ${OBJECTDIR}/_ext/359630028/tls.o.d 
	@${RM} ${OBJECTDIR}/_ext/359630028/tls.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/359630028/tls.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/359630028/tls.o.d" -o ${OBJECTDIR}/_ext/359630028/tls.o ../../../../v2_03b/third_party/tcpip/wolfssl/src/tls.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/asm.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/asm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/asm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/asm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/asm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/asm.o.d" -o ${OBJECTDIR}/_ext/1437400831/asm.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/asm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/blake2b.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/blake2b.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/blake2b.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/blake2b.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/blake2b.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/blake2b.o.d" -o ${OBJECTDIR}/_ext/1437400831/blake2b.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/blake2b.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/camellia.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/camellia.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/camellia.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/camellia.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/camellia.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/camellia.o.d" -o ${OBJECTDIR}/_ext/1437400831/camellia.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/camellia.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/chacha.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/chacha.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/chacha.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/chacha.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/chacha.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/chacha.o.d" -o ${OBJECTDIR}/_ext/1437400831/chacha.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/chacha.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/chacha20_poly1305.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o.d" -o ${OBJECTDIR}/_ext/1437400831/chacha20_poly1305.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/chacha20_poly1305.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/curve25519.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/curve25519.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/curve25519.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/curve25519.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/curve25519.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/curve25519.o.d" -o ${OBJECTDIR}/_ext/1437400831/curve25519.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/curve25519.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/dh.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/dh.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/dh.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/dh.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/dh.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/dh.o.d" -o ${OBJECTDIR}/_ext/1437400831/dh.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/dh.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/dsa.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/dsa.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/dsa.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/dsa.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/dsa.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/dsa.o.d" -o ${OBJECTDIR}/_ext/1437400831/dsa.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/dsa.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/ecc_fp.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ecc_fp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ecc_fp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ecc_fp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/ecc_fp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/ecc_fp.o.d" -o ${OBJECTDIR}/_ext/1437400831/ecc_fp.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ecc_fp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/ed25519.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ed25519.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ed25519.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ed25519.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/ed25519.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/ed25519.o.d" -o ${OBJECTDIR}/_ext/1437400831/ed25519.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ed25519.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/fe_low_mem.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/fe_low_mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/fe_low_mem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/fe_low_mem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/fe_low_mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/fe_low_mem.o.d" -o ${OBJECTDIR}/_ext/1437400831/fe_low_mem.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/fe_low_mem.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/fe_operations.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/fe_operations.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/fe_operations.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/fe_operations.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/fe_operations.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/fe_operations.o.d" -o ${OBJECTDIR}/_ext/1437400831/fe_operations.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/fe_operations.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/ge_low_mem.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ge_low_mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ge_low_mem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ge_low_mem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/ge_low_mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/ge_low_mem.o.d" -o ${OBJECTDIR}/_ext/1437400831/ge_low_mem.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ge_low_mem.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/ge_operations.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ge_operations.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ge_operations.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ge_operations.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/ge_operations.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/ge_operations.o.d" -o ${OBJECTDIR}/_ext/1437400831/ge_operations.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ge_operations.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/hc128.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/hc128.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/hc128.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/hc128.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/hc128.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/hc128.o.d" -o ${OBJECTDIR}/_ext/1437400831/hc128.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/hc128.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/md2.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/md2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/md2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/md2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/md2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/md2.o.d" -o ${OBJECTDIR}/_ext/1437400831/md2.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/md2.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/md4.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/md4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/md4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/md4.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/md4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/md4.o.d" -o ${OBJECTDIR}/_ext/1437400831/md4.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/md4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/pkcs7.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/pkcs7.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/pkcs7.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/pkcs7.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/pkcs7.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/pkcs7.o.d" -o ${OBJECTDIR}/_ext/1437400831/pkcs7.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/pkcs7.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/poly1305.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/poly1305.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/poly1305.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/poly1305.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/poly1305.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/poly1305.o.d" -o ${OBJECTDIR}/_ext/1437400831/poly1305.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/poly1305.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/rabbit.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/rabbit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/rabbit.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/rabbit.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/rabbit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/rabbit.o.d" -o ${OBJECTDIR}/_ext/1437400831/rabbit.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/rabbit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/ripemd.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ripemd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ripemd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/ripemd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/ripemd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/ripemd.o.d" -o ${OBJECTDIR}/_ext/1437400831/ripemd.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/ripemd.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1437400831/misc.o: ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/misc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1437400831" 
	@${RM} ${OBJECTDIR}/_ext/1437400831/misc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437400831/misc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437400831/misc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1437400831/misc.o.d" -o ${OBJECTDIR}/_ext/1437400831/misc.o ../../../../v2_03b/third_party/tcpip/wolfssl/wolfcrypt/src/misc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o: ../src/system_config/default/framework/net/pres/net_pres_enc_glue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1278673032" 
	@${RM} ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o.d" -o ${OBJECTDIR}/_ext/1278673032/net_pres_enc_glue.o ../src/system_config/default/framework/net/pres/net_pres_enc_glue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o: ../src/system_config/default/framework/net/pres/net_pres_cert_store.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1278673032" 
	@${RM} ${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o.d 
	@${RM} ${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o.d" -o ${OBJECTDIR}/_ext/1278673032/net_pres_cert_store.o ../src/system_config/default/framework/net/pres/net_pres_cert_store.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -DHAVE_CONFIG_H -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../v2_03b/framework" -I"../src/system_config/default/framework" -I"../../../../v2_03b/third_party/tcpip/wolfssl" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/openstorm.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../v2_03b/bin/framework/peripheral/PIC32MX795F512H_peripherals.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/openstorm.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\v2_03b\bin\framework\peripheral\PIC32MX795F512H_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=54960,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/openstorm.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../v2_03b/bin/framework/peripheral/PIC32MX795F512H_peripherals.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/openstorm.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\v2_03b\bin\framework\peripheral\PIC32MX795F512H_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=54960,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/openstorm.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
