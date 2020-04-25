/**
  @Generated PIC24 / dsPIC33 / PIC32MM MCUs Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    clock.c

  @Summary:
    This is the clock.c file generated using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.167.0
        Device            :  dsPIC33EP512GM706
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB             :  MPLAB X v5.35
*/

/*
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
*/

#include <stdint.h>
#include "xc.h"
#include "clock.h"

void CLOCK_Initialize(void)
{
    // FRCDIV FRC/1; PLLPRE 2; DOZE 1:8; PLLPOST 1:2; DOZEN disabled; ROI disabled; 
    CLKDIV = 0x3000;
    // TUN Center frequency; 
    OSCTUN = 0x00;
    // ROON disabled; ROSEL FOSC; RODIV 0; ROSSLP disabled; 
    REFOCON = 0x00;
    // PLLDIV 68; 
    PLLFBD = 0x44;
    // AD1MD disabled; PWMMD disabled; T3MD disabled; T4MD disabled; T1MD disabled; U2MD disabled; T2MD disabled; U1MD disabled; QEI1MD disabled; SPI2MD disabled; SPI1MD disabled; C2MD disabled; C1MD disabled; DCIMD disabled; T5MD disabled; I2C1MD disabled; 
    PMD1 = 0xFFFF;
    // OC5MD disabled; OC6MD disabled; OC7MD disabled; OC8MD disabled; OC1MD disabled; IC2MD disabled; OC2MD disabled; IC1MD disabled; OC3MD disabled; OC4MD disabled; IC6MD disabled; IC7MD disabled; IC5MD disabled; IC8MD disabled; IC4MD disabled; IC3MD disabled; 
    PMD2 = 0xFFFF;
    // ADC2MD disabled; PMPMD disabled; U3MD disabled; QEI2MD disabled; RTCCMD disabled; CMPMD disabled; T9MD disabled; T8MD disabled; CRCMD disabled; T7MD disabled; I2C2MD disabled; T6MD disabled; 
    PMD3 = 0xF7AB;
    // U4MD disabled; CTMUMD disabled; REFOMD disabled; 
    PMD4 = 0x2C;
    // PWM2MD enabled; PWM1MD enabled; PWM4MD enabled; SPI3MD enabled; PWM3MD enabled; PWM6MD enabled; PWM5MD enabled; 
    PMD6 = 0x00;
    // PTGMD enabled; DMA0MD enabled; 
    PMD7 = 0x00;
    // CF no clock failure; NOSC PRIPLL; LPOSCEN disabled; CLKLOCK unlocked; OSWEN Switch is Complete; IOLOCK not-active; 
    __builtin_write_OSCCONH((uint8_t) (0x03));
    __builtin_write_OSCCONL((uint8_t) (0x01));
    // Wait for Clock switch to occur
    while (OSCCONbits.OSWEN != 0);
    while (OSCCONbits.LOCK != 1);
}

