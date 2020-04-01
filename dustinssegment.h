/*
 * dustinssegment.h
 *
 * Created: 28-3-2020 18:47:03
 *  Author: Dustin
 */ 


#ifndef DUSTINSSEGMENT_H_
#define DUSTINSSEGMENT_H_

#include <avr/io.h>

#define SEG_A 0x01		// A = 0b00000001
#define SEG_B 0x02		// B = 0b00000010
#define SEG_C 0x04		// C = 0b00000100
#define SEG_D 0x08		// D = 0b00001000
#define SEG_E 0x10		// E = 0b00010000
#define SEG_F 0x20		// F = 0b00100000
#define SEG_G 0x40		// G = 0b01000000
#define SEG_ERROR 0x79	// Error
#define SEG_DP 0x80		// DP =0b10000000

/* Lijst van getallen die gevormd worden door specifieke segmenten aan of uit te zetten */
extern uint8_t numbers[];

/* Weergeven van een getal op het 7-segments display door het meegeven van de poort (waar deze op aangesloten is) en het getal wat getoond moet worden */
void dustinssegment_DisplayNumber(volatile uint8_t *port, uint8_t number);

#endif /* DUSTINSSEGMENT_H_ */