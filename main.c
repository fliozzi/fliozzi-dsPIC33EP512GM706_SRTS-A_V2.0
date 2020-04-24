/**
  MAIN MANAGER Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    main manager.c

  @Summary
    This is the generated driver implementation file for the MAIN MANAGER driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for MAIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.75
        Device            :  dsPIC33EP512GM706
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.35
        MPLAB 	          :  MPLAB X v5.05
 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
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
 */

/**
  Section: Included Files
 */
#define FCY 70000000UL

#include "mcc_generated_files/mcc.h"

#include <stdio.h>
#include <libpic30.h>      // For delay functions

#include "lcd.c"
#include "qei1.h"

#include "common.h"
#include "declarations.h"

/*
                         Main application
 */
int main(void) {
    // initialize the device
    SYSTEM_Initialize();
    QEI1_Initialize();
    // When using interrupts, you need to set the Global Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    // INTERRUPT_GlobalEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalDisable();

    ENABLE_12V0_SetLow();
    ENABLE_5V0_SetHigh();
    ENABLE_3V3XB_SetLow(); // Inverted logic for EN/DIS (ENABLE for ADC Conversion)
    ENABLE_BAT_MEAS_SetLow();
    ENABLE_5V0RB_SetHigh();

    LCD_Initialize();
    LCD_SendLogo();
    LCD_Clear();

    while (1) {
        I2C_RTCC_HoursGet(&hr);
        I2C_RTCC_MinutesGet(&min);
        I2C_RTCC_SecondsGet(&sec);

        send_command_byte(0b00001100); // Display: display on, cursor off, blink off
        sprintf(buffer, "%04u", ADC1BUF0);
        LCD_GotoXY(1, 1);
        LCD_SendString(buffer);
        sprintf(buffer, "%04u", ADC1BUF1);
        LCD_GotoXY(1, 2);
        LCD_SendString(buffer);
        sprintf(buffer, "%04u", ADC1BUF2);
        LCD_GotoXY(1, 3);
        LCD_SendString(buffer);
        sprintf(buffer, "%04u", ADC1BUF3);
        LCD_GotoXY(1, 4);
        LCD_SendString(buffer);

        sprintf(buffer, "%04u", ADC2BUF0);
        LCD_GotoXY(6, 1);
        LCD_SendString(buffer);
        sprintf(buffer, "%04u", ADC2BUF1);
        LCD_GotoXY(6, 2);
        LCD_SendString(buffer);
        sprintf(buffer, "%04u", ADC2BUF2);
        LCD_GotoXY(6, 3);
        LCD_SendString(buffer);
        sprintf(buffer, "%04u", ADC2BUF3);
        LCD_GotoXY(6, 4);
        LCD_SendString(buffer);

        sprintf(buffer, "%010lu", count);
        LCD_GotoXY(11, 1);
        LCD_SendString(buffer);

        sprintf(buffer, "");
        LCD_GotoXY(11, 3);
        LCD_SendString(buffer);

        QEIpos = QEI1_PosCounter32BitSgnGetX1();
        QEIposF = (QEIpos >= 0) ? (QEIpos % 4 + 1) : -((-4 - QEIpos % 4)) + 1;
        sprintf(buffer, "%010ld", QEIpos);
        LCD_GotoXY(11, 2);
        LCD_SendString(buffer);

        LCD_GotoXY(10, QEIposF);
        send_command_byte(0b00001111); // Display: display on, cursor on, blink off

        sprintf(buffer, "%02u:%02u:%02u", hr, min, sec);
        LCD_GotoXY(11, 3);
        LCD_SendString(buffer);

        __delay_ms(200);
    }
}

void TMR8_CallBack(void) {
    count++;
}

void ENC_CLICK_CallBack(void) {
    debugLED_Toggle();
}
/**
 End of File
 */
