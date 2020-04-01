/*
 * dustinshcsr04.h
 *
 * Created: 31-3-2020 15:22:10
 *  Author: Dustin
 */ 


#ifndef DUSTINSHCSR04_H_
#define DUSTINSHCSR04_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "dustinsutils.h"
#include "dustinslcd.h"
#include "dustinssegment.h"
#include <string.h>
#include <stdlib.h>

#define TRIGGER_PIN PINA0		// Gebruikte Trigger-pin
#define ECHO_PIN PIND4			// Gebruikte Echo-pin  
#define HCSR04_PORT PORTA		// Port die gebruikt wordt door de HCSR04
#define HCSR04_REGISTER DDRA	// Register wat door de HCSR04 gebruikt moet worden, voor PORTA DDRA, voor PORTB DDRB, etc
#define SOUND_VELOCITY 343		// Geluidssnelheid bij kamertemperatuur in m/s 

/* Functie om de HCSR04 ultrasone sensor te initialiseren */
void dustinshcsr04_Init(void);

/* Functie om de afstand te berekenen in meters */
void dustinshcsr04_CalculateDistance(void);

/* Functie om pulsen uit te zenden en de gemeten afstand te tonen op het LCD-display */
void dustinshcsr04_Run(void); 

#endif /* DUSTINSHCSR04_H_ */