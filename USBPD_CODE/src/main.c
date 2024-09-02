/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "../stm32-bsp-usbpd-tcpp0203-main/usbpd_tcpp0203_conf_template.h"
#include "../stm32-bsp-usbpd-tcpp0203-main/usbpd_tcpp0203_errno.h"
//#include "../stm32-bsp-usbpd-tcpp0203-main/usbpd_tcpp0203_bus.h"
#include "../stm32-bsp-usbpd-tcpp0203-main/usbpd_tcpp0203_usbpd_pwr.h"
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    printf("SYS_Initialize done\r\n");
    //BSP_USBPD_PWR_Init(3);
    BSP_USBPD_PWR_Deinit(4);
    

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

