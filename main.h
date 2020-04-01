/*
 * main.h
 *
 * Created: 1-4-2020 15:57:02
 *  Author: Dustin
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include "dustinsutils.h"				// Standaard utilities zoals bijvoorbeeld een delay, of SET_BIT
#include "dustinslcd.h"					// Library voor de aansturing van het LCD
#include "dustinssegment.h"				// Library voor de aansturing van het 7-segments display
#include "dustinshcsr04.h"				// Library voor de aansturing van de HCSR04 ultrasone sensor

/* Initialization functies for main */
void init(void);

/* Main programma functie */
int main(void);

#endif /* MAIN_H_ */