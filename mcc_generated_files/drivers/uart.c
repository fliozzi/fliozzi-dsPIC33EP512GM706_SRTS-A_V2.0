/**
\file
\brief This file contains the function names of the operations that can be carried out by the UART Foundation Services .
<br>
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
**/

/**
  Section: Included Files
 */

#include "uart.h"   


const uart_functions_t uart[] = {   
    {UART1_Read, UART1_Write, UART1_IsTxReady, UART1_IsRxReady, UART1_SetTxInterruptHandler, UART1_SetRxInterruptHandler, UART1_IsTxDone, UART1_Initialize },
    {UART2_Read, UART2_Write, UART2_IsTxReady, UART2_IsRxReady, UART2_SetTxInterruptHandler, UART2_SetRxInterruptHandler, UART2_IsTxDone, UART2_Initialize },
    {UART3_Read, UART3_Write, UART3_IsTxReady, UART3_IsRxReady, UART3_SetTxInterruptHandler, UART3_SetRxInterruptHandler, UART3_IsTxDone, UART3_Initialize },
    {UART4_Read, UART4_Write, UART4_IsTxReady, UART4_IsRxReady, UART4_SetTxInterruptHandler, UART4_SetRxInterruptHandler, UART4_IsTxDone, UART4_Initialize }
};

/**
 End of File
 */