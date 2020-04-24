/* 
 * File:   lcd.h
 * Author: Fernando
 *
 * Created on 30 de mayo de 2017, 13:32
 */

#ifndef LCD_H
#define	LCD_H

#include <xc.h>
#include <stdint.h>

/* CTRL_PORT defines the port where the control lines are connected.
 * These are just samples, change to match your application.
 */
#define RW_PIN   _LATB5   		/* LAT for RW  */
//#define TRIS_RW  TRISFbits.TRISF1   	/* TRIS for RW */
//#define PORT_RW  PORTFbits.RF1      	/* PORT for RW */

#define RS_PIN   _LATF1   		/* LAT for RS  */
//#define TRIS_RS  TRISBbits.TRISB10    	/* TRIS for RS */
//#define PORT_RS  PORTBbits.RB10     	/* PORT for RS */

#define E_PIN    _LATC9  		/* LAT for E   */
//#define TRIS_E   TRISCbits.TRISC9    	/* TRIS for E  */
//#define PORT_E   PORTCbits.RC9      	/* PORT for E  */

#define DATA_PIN_7     _LATA10
#define DATA_PIN_6     _LATB12
#define DATA_PIN_5     _LATB11
#define DATA_PIN_4     _LATB10

//#define READ_PIN_7		PORTAbits.RA10
//#define READ_PIN_6		PORTBbits.RB13
//#define READ_PIN_5		PORTBbits.RB12
//#define READ_PIN_4		PORTbbits.RB11

//#define TRIS_DATA_PIN_7       TRISAbits.TRISA10
//#define TRIS_DATA_PIN_6       TRISBbits.TRISB13
//#define TRIS_DATA_PIN_5       TRISBbits.TRISB12
//#define TRIS_DATA_PIN_4       TRISBbits.TRISB11

/* Display ON/OFF Control defines */
#define DON         0b00001111  /* Display on      */
#define DOFF        0b00001011  /* Display off     */
#define CURSOR_ON   0b00001111  /* Cursor on       */
#define CURSOR_OFF  0b00001101  /* Cursor off      */
#define BLINK_ON    0b00001111  /* Cursor Blink    */
#define BLINK_OFF   0b00001110  /* Cursor No Blink */

// These are the line addresses for most 4x20 LCDs. 
#define LCD_LINE_1_ADDRESS 0x00 
#define LCD_LINE_2_ADDRESS 0x40 
#define LCD_LINE_3_ADDRESS 0x14 
#define LCD_LINE_4_ADDRESS 0x54 

/* Cursor or Display Shift defines */
#define SHIFT_CUR_LEFT    0b00000100  /* Cursor shifts to the left   */
#define SHIFT_CUR_RIGHT   0b00000101  /* Cursor shifts to the right  */
#define SHIFT_DISP_LEFT   0b00000110  /* Display shifts to the left  */
#define SHIFT_DISP_RIGHT  0b00000111  /* Display shifts to the right */

/* Function Set defines */
#define FOUR_BIT   0b00101100  /* 4-bit Interface               */
#define EIGHT_BIT  0b00111100  /* 8-bit Interface               */
#define LINE_5X7   0b00110000  /* 5x7 characters, single line   */
#define LINE_5X10  0b00110100  /* 5x10 characters               */
#define LINES_5X7  0b00111000  /* 5x7 characters, multiple line */

uint8_t const logo[] = {
    //pARTE DE ARRIBA DE LA PIRAMIDE
    0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x1F, //4 BYTES
    0x00, 0x00, 0x10, 0x18, 0x00, 0x00, 0x1F, 0x1F,
    0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, //Parte de abajo de la piramide
    0x07, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
    0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, //6 bytes
    0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x1F, 0x1F,
    0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x1F, 0x1F,
    0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x1E, 0x1F
};

uint8_t const varios[] = {
    0x04, 0x0e, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x00, //flecha arriba x01 
    0x04, 0x04, 0x04, 0x04, 0x1f, 0x0e, 0x04, 0x00, //flecha abajo  x02
    0x0e, 0x02, 0x0e, 0x02, 0x0e, 0x00, 0x00, 0x00, //3 cubico (al cubo) x03
    0x0c, 0x12, 0x04, 0x08, 0x1e, 0x00, 0x00, 0x00, //2 cuadrado(al cuadrado) x04
    0x0d, 0x12, 0x00, 0x11, 0x19, 0x15, 0x13, 0x00, //ñ x05
    0x0e, 0x0a, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, //º x06 x07:Logo mettec

    0x00, 0x1f, 0x0a, 0x04, 0x04, 0x04, 0x04, 0x00, //antena RF
    0x1f, 0x00, 0x15, 0x1b, 0x1b, 0x1b, 0x1b, 0x00
}; //inverso de antena para logo RF 

uint8_t const mettec[] = "METTEC";
uint8_t const srtsa[] = "SRTS-A v2.0";
uint8_t const wwwmettec[] = "www.mettec.com.ar";

void send_nibble(uint8_t nibble);
void send_command_byte(uint8_t byte);
void send_data_byte(uint8_t byte);
void send_data_byte_fast(uint8_t byte);
void LCD_Initialize(void);
void LCD_Clear(void);
void LCD_SendString(uint8_t *buffer);
void LCD_GotoXY(uint8_t x, uint8_t y);

void lcd_create_char(uint8_t charnum, const uint8_t *chardata);
void LCD_SendLogo(void);

#endif	/* LCD_H */
