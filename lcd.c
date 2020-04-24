/* 
 * File:   lcd.c
 * Author: Fernando
 *
 * Created on 30 de mayo de 2017, 13:33
 */

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */

#include <xc.h>

#include <stdint.h>        /* Includes uint16_t definition */
#include <stdbool.h>       /* Includes true/false definition */
#include <stdio.h>
#include <stdlib.h>

#include <libpic30.h>      // For delay functions

#include "lcd.h"

void send_nibble(uint8_t nibble) {
    // Note: data is latched on falling edge of pin E
    DATA_PIN_7 = ~((nibble >> 3) & 0x01);
    DATA_PIN_6 = ~((nibble >> 2) & 0x01);
    DATA_PIN_5 = ~((nibble >> 1) & 0x01);
    DATA_PIN_4 = ~(nibble & 0x01);

    E_PIN = ~(0);
    __delay_us(800);
    E_PIN = ~(1);
    __delay_us(800); // Enough time even for slowest command
}

void send_nibble_fast(uint8_t nibble) {
    // Note: data is latched on falling edge of pin E
    DATA_PIN_7 = ~((nibble >> 3) & 0x01);
    DATA_PIN_6 = ~((nibble >> 2) & 0x01);
    DATA_PIN_5 = ~((nibble >> 1) & 0x01);
    DATA_PIN_4 = ~(nibble & 0x01);

    __delay_us(30);
    E_PIN = ~(0);
    __delay_us(30);
    E_PIN = ~(1);
    __delay_us(30);
}

// Send a command byte (i.e. with pin RS low)

void send_command_byte(uint8_t byte) {
    RS_PIN = ~(0);
    send_nibble(byte >> 4);
    send_nibble(byte & 0xF);
}

void send_command_byte_fast(uint8_t byte) {
    RS_PIN = ~(0);
    send_nibble_fast(byte >> 4);
    send_nibble_fast(byte & 0xF);
}

// Send a data byte (i.e. with pin RS high)

void send_data_byte(uint8_t byte) {
    RS_PIN = ~(1);
    send_nibble(byte >> 4);
    send_nibble(byte & 0xF);
}

void send_data_byte_fast(uint8_t byte) {
    RS_PIN = ~(1);
    send_nibble_fast(byte >> 4);
    send_nibble_fast(byte & 0xF);
}

void LCD_Initialize(void) {
    // Let's just write to the LCD and never read!
    // We'll wait 2ms after every command since we can't
    // check the busy flag.
    RW_PIN = ~(0);
    RS_PIN = ~(0);
    E_PIN = ~(1);

    // Initialization
    __delay_ms(16); // must be more than 15ms
    send_nibble(0b0011);
    __delay_ms(5); // must be more than 4.1ms
    send_nibble(0b0011);
    __delay_us(150); // must be more than 100us
    send_nibble(0b0011);
    __delay_ms(5); // must be more than 4.1ms
    send_nibble(0b0010); // select 4-bit mode

    // Display settings
    send_command_byte(0b00101000); // DL = 0: 4 bits, N = 1: 2 lines, F = 0: 5 × 8 dots
    send_command_byte(0b00001000); // Display: display off, cursor off, blink off
    send_command_byte(0b00000001); // Clear display
    send_command_byte(0b00000110); // Set entry mode: ID=1, S=0
    send_command_byte(0b00001100); // Display: display on, cursor off, blink off

    lcd_create_char(0, &logo[0]);
}

void LCD_Clear(void) {
    send_command_byte(0b00000001); // Clear display
}

void LCD_SendString(uint8_t *buffer) {
    while (*buffer) // Write data to LCD up to null
    {
        send_data_byte_fast(*buffer); // Write character to LCD
        buffer++; // Increment buffer
    }
}

void LCD_GotoXY(uint8_t x, uint8_t y) {
    uint8_t address;

    switch (y) {
        case 1:
            address = LCD_LINE_1_ADDRESS;
            break;

        case 2:
            address = LCD_LINE_2_ADDRESS;
            break;

        case 3:
            address = LCD_LINE_3_ADDRESS;
            break;

        case 4:
            address = LCD_LINE_4_ADDRESS;
            break;

        default:
            address = LCD_LINE_1_ADDRESS;
            break;

    }

    address += x - 1;
    send_command_byte_fast(0x80 | address);
}

void lcd_create_char(uint8_t charnum, const uint8_t *chardata) {
    uint8_t i;
    charnum &= 0x07;
    send_command_byte(0x40 | charnum);
    for (i = 0; i < 64; i++) {
        send_data_byte_fast(chardata[i]);
    }
}

void LCD_SendLogo(void) {
    uint8_t x = 15;
    uint8_t y = 1;
    send_command_byte_fast(0b00010100);
    LCD_Clear();
    LCD_GotoXY(x + 2, y);
    send_data_byte_fast(0);
    send_data_byte_fast(1);
    LCD_GotoXY(x, y + 1);
    send_data_byte_fast(2);
    send_data_byte_fast(3);
    send_data_byte_fast(4);
    send_data_byte_fast(5);
    send_data_byte_fast(6);
    send_data_byte_fast(7);
    for (uint8_t i = 1; i < 15; i++) {
        send_command_byte_fast(0b00011000);
        __delay_ms(50);
    }
    LCD_GotoXY(25, 1);
    LCD_SendString(&mettec);
    LCD_GotoXY(23, 2);
    LCD_SendString(&srtsa);

    send_command_byte_fast(0b00010100);
    LCD_GotoXY(15, 4);
    for (uint8_t i = 0; i < 6; i++) {
        send_data_byte_fast(wwwmettec[i]);
        __delay_ms(50);
    }
    LCD_GotoXY(21, 3);
    for (uint8_t i = 6; i < 17; i++) {
        send_data_byte_fast(wwwmettec[i]);
        __delay_ms(50);
    }
    __delay_ms(1000);
}
