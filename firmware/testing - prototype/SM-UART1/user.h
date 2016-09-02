
#include "system.h"
#include "commands.h"
#include "ESP8266.h"
#include "ESP8266Http.h"

/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

#define	GetPeripheralClock()		(SYS_FREQ/(1 << OSCCONbits.PBDIV))
#define	GetInstructionClock()		(SYS_FREQ)

#define UART_CMD_MODULE_ID              UART2
#define DESIRED_CMD_BAUDRATE            (9600)

#define UART_WIFI_MODULE_ID             UART4
#define DESIRED_WIFI_BAUDRATE           (115200)

/******************************************************************************/
/* User Function Prototypes                                                    /
/******************************************************************************/

void InitApp(void);         /* I/O and Peripheral Initialization */

void WriteString(const char *string);
void DefaultErrorToOutput(const char *string);
void PutCharacter(const char character);


