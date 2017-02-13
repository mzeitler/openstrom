# eth_pic32
An ethernet MAC and PHY layer for PIC32.
This demo project runs over PIC32 Ethernet Starter Kit and has been tested with an Ubuntu laptop through an Ethernet switch.

The demo application just sends a frame with a fixed message. You can use a sniffing tool like Wireshark. 
ATTENTION: set MAC address of your PC as destination MAC address and check the sent frame with a tool like Wireshark.

For an example of use please have a look at minUDP or minIP projects.

Known issues:
 - Ethernet layer remains stacked until an Ethernet cable is connected. It is necessary to add a timeout in order to exit the related infinite loop in eth.c file.
