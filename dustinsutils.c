/*
 * dustinsutils.c
 *
 * Created: 27-3-2020 17:38:15
 *  Author: Dustin
 */ 

#include "dustinsutils.h"

/************************************************************************/
/* Functie voor een delay van een aantal ms                             */
/************************************************************************/
void dustinsutils_delay_ms(int ms) {
	for (int i = 0; i < ms; i++)		
		_delay_ms(1);					// Maximale delay van "_delay_ms" functie is 32 ms
}

/************************************************************************/
/* Functie voor een delay van een aantal us                             */
/************************************************************************/
void dustinsutils_delay_us(int us) {
	for (int i = 0; i < us; i++) 
		_delay_us(1);					// Maximale delay van "_delay_us" functie is 96 us
}