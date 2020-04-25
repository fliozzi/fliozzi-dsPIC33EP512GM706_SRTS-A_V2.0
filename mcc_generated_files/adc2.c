/**
  ADC2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adc2.c

  @Summary
    This is the generated driver implementation file for the ADC2 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for ADC2.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.167.0
        Device            :  dsPIC33EP512GM706      
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB 	          :  MPLAB X v5.35
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

/**
  Section: Included Files
*/

#include "adc2.h"

/**
  Section: File Specific Functions
*/

// ADC2 Default Interrupt Handler
static void (*ADC2_DefaultInterruptHandler)(void) = NULL;

/**
  Section: Driver Interface
*/

void ADC2_Initialize (void)
{
    // ASAM enabled; ADDMABM disabled; ADSIDL disabled; DONE disabled; SIMSAM Sequential; FORM Absolute decimal result, unsigned, right-justified; SAMP disabled; SSRC TMR3; AD12B 12-bit; ADON enabled; SSRCG disabled; 
    AD2CON1 = 0x8444;
    // CSCNA disabled; VCFG0 AVDD; VCFG1 AVSS; ALTS disabled; BUFM disabled; SMPI Generates interrupt after completion of every sample/conversion operation; CHPS 1 Channel; 
    AD2CON2 = 0x00;
    // SAMC 14; ADRC FOSC/2; ADCS 99; 
    AD2CON3 = 0xE63;
    // CH0SA OA2/AN0; CH0SB OA2/AN0; CH0NB VREFL; CH0NA VREFL; 
    AD2CHS0 = 0x00;
    // CSS26 disabled; CSS25 disabled; CSS24 disabled; CSS31 disabled; CSS30 disabled; CSS19 disabled; CSS18 disabled; CSS29 disabled; CSS17 disabled; CSS28 disabled; CSS16 enabled; CSS27 disabled; 
    AD2CSSH = 0x01;
    // CSS9 enabled; CSS8 enabled; CSS7 disabled; CSS6 disabled; CSS5 disabled; CSS4 disabled; CSS3 disabled; CSS2 disabled; CSS15 disabled; CSS1 disabled; CSS14 disabled; CSS0 disabled; CSS13 disabled; CSS12 enabled; CSS11 enabled; CSS10 disabled; 
    AD2CSSL = 0x1B00;
    // DMABL Allocates 1 word of buffer to each analog input; ADDMAEN disabled; 
    AD2CON4 = 0x00;
    // CH123SA2 disabled; CH123SB2 CH1=OA2/AN0,CH2=AN1,CH3=AN2; CH123NA disabled; CH123NB CH1=VREF-,CH2=VREF-,CH3=VREF-; 
    AD2CHS123 = 0x00;
    
    //Assign Default Callbacks
    ADC2_SetInterruptHandler(&ADC2_CallBack);
   
}

void __attribute__ ((weak)) ADC2_CallBack(void)
{

}

void ADC2_SetInterruptHandler(void* handler)
{
    ADC2_DefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC2_Tasks ( void )
{
    if(IFS1bits.AD2IF)
    {
        if(ADC2_DefaultInterruptHandler) 
        { 
            ADC2_DefaultInterruptHandler(); 
        }

        // clear the ADC interrupt flag
        IFS1bits.AD2IF = false;
    }
}

/**
  End of File
*/

