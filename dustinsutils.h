/*
 * dustinsutils.h
 *
 * Created: 27-3-2020 17:38:28
 *  Author: Dustin
 */ 


#ifndef DUSTINSUTILS_H_
#define DUSTINSUTILS_H_

#define F_CPU 8E6									// Klokfrequentie Atmega128 8MHz
#define UNSET_BIT(x) (~(1<<x))						// Definiëren van een functie om een bepaalde bit niet te zetten
#define SET_BIT(x) (1<<x)							// Definiëren van een functie om een bepaalde bit te zetten

#include <avr/io.h>									// Toevoegen van de avr/io library zodat IO-poorten aangeroepen kunnen worden
#include <util/delay.h>								// Toevoegen van de util/delay library zodat er een delay aangeroepen kan worden
#include <avr/interrupt.h>							// Toevoegen van de avr/interrupt library zodat interrupts aangeroepen kunnen worden
#include <stdio.h>									// Toevoegen van de stdio library zodat de "sprintf" functie aangeroepen kan worden
#include <stdlib.h>									// Toevoegen van de stdlib library zodat functies zoals "malloc" en "free" aangeroepen kunnen worden

/* Enum type voor het creëren van een boolean waarde */
typedef enum { FALSE, TRUE } dustinsutils_Boolean;	// C heeft standaard geen boolean, door een typedef enum hiervoor te declareren kan deze wel gebruikt worden

/* Functie voor een delay van een aantal ms */
void dustinsutils_delay_ms(int);					// Delay functie ms (millis)

/* Functie voor een delay van een aantal us */
void dustinsutils_delay_us(int);					// Delay functie us (nanos)

#endif /* DUSTINSUTILS_H_ */