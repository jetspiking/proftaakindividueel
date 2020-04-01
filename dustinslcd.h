/*
 * dustinslcd.h
 *
 * Created: 27-3-2020 17:44:50
 *  Author: Dustin
 */ 


#ifndef DUSTINSLCD_H_
#define DUSTINSLCD_H_

//#define F_CPU 8E6
#define ENABLE PINC3				// Enable pin waar het LCD op aangesloten zit
#define RESET PINC2					// Reset pin waar het LCD op aangesloten zit
#define LCD_DIRECTION  DDRC			// Data Direction Register waar het LCD van gebruik moet maken
#define LCD_PORT	   PORTC		// IO poort waar het LCD op zit aangesloten

#include <avr/io.h>					// Nodig om de IO-poorten te kunnen benaderen
#include "dustinsutils.h"			// Nodig om SET_BIT en UNSET_BIT aan te kunnen roepen

/* Functie om een command door te sturen naar het LCD */
void dustinslcd_Command(unsigned char);

/* Functie om een enkele char weer te geven op het LCD */
void dustinslcd_Char(unsigned char);

/* Functie om via de 4-bits modus data door te sturen naar het LCD via een hoge en lage nibble */
void dustinslcd_SplitSend(unsigned char);

/* Functie om een String weer te geven op het LCD */
void dustinslcd_String(char*);

/* Functie om het LCD te legen */
void dustinslcd_Clear(void);

/* Functie om de cursor naar positie 0 te zetten */
void dustinslcd_CursorHome(void);

/* Functie om het LCD te initialiseren */
void dustinslcd_Init(void);

/* Functie om de cursor naar de volgende regel te zetten op het LCD */
void dustinslcd_NextLine(void);

/* Functie om de cursor positie te zetten naar een bepaalde locatie */
void dustinslcd_SetCursorPos(int);

/* Functie om het LCD-scherm uit te schakelen */
void dustinslcd_Off(void);

/* Functie om de cursor op het LCD te laten knipperen */
void dustinslcd_BlinkingCursor(void);

/* Functie om de cursor te laten stoppen met knipperen op het LCD */
void dustinslcd_SteadyCursor(void);

/* Functie om _alle_ tekst en tekens op het LCD met 1 naar links te verschuiven */
void dustinslcd_ShiftLeft(void);

/* Functie om _alle_ tekst en tekens op het LCD met 1 naar rechts te verschuiven */
void dustinslcd_ShiftRight(void);

/* Functie om de cursor met 1 naar links te verschuiven */
void dustinslcd_ShiftCursorLeft(void);

/* Functie om de cursor met 1 naar rechts te verschuiven */
void dustinslcd_ShiftCursorRight(void);

#endif /* DUSTINSLCD_H_ */