/* 
 * File:   declarations.h
 * Author: Fernando
 *
 * Created on May 9, 2017, 11:25 AM
 */

#ifndef DECLARATIONS_H
#define	DECLARATIONS_H

uint8_t hr = 0, min = 0, sec = 0;
volatile uint32_t count = 0;

volatile int32_t QEIpos = 0;
volatile uint8_t QEIposF = 0;
uint8_t buffer[50] = "";

#endif	/* DECLARATIONS_H */
