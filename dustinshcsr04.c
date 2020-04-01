/*
 * dustinshcsr04.c
 *
 * Created: 31-3-2020 15:21:45
 *  Author: Dustin
 */ 

#include "dustinshcsr04.h"

char STRING[10];							// Globale variabele zodat deze eventueel opgevraagd zou kunnen worden in een latere iteratie
long COUNT;									// Globale variabele is hier noodzakelijk, omdat deze niet specifiek gereset wordt in de run functie
double DISTANCE;							// Globale variabele zodat deze eventueel opgevraagd zou kunnen worden in een latere iteratie
int TIMER_OVERFLOW_COUNTER=0;				// Globale variabele is hier noodzakelijk, omdat deze in de ISR verhoogd moet worden

/****************************************************************************************************/
/* Interrupt Service Routine die aangeroepen wordt zodra in Timer1 (TCNT1) een overflow ontstaan is */
/****************************************************************************************************/
ISR(TIMER1_OVF_vect)
{
	TIMER_OVERFLOW_COUNTER++;				// Timer Overflow Counter met één ophogen, omdat TCNT1 overflowed is
}

/************************************************************************/
/* Initialisatie van de HCSR04 ultrasone sensor                         */
/************************************************************************/
void dustinshcsr04_Init(void) 
{	
	HCSR04_REGISTER = SET_BIT(TRIGGER_PIN);	// De trigger-pin als output configureren
	PORTD |= SET_BIT(ECHO_PIN);				// De echo-pin naar een hoog signaal zetten
	TIMSK = SET_BIT(TOIE1);				    // Inschakelen van Timer1 Overflow Interrupts
	TCCR1A = 0;								// Zet alle bits naar 0 omdat er geen speciale modus aan hoeven te staan
}

/************************************************************************/
/* Berekenen van de afstand via de klokfrequentie en de COUNT waarde    */
/************************************************************************/
void dustinshcsr04_CalculateDistance(void) {
	DISTANCE = ((SOUND_VELOCITY*(double)COUNT)/2)*(1./F_CPU); // Afstand = ( (geluidssnelheid * timer) / 2 ) * [trillingstijd processor]		De deling door 2 wordt uitgevoerd omdat er sprake is van een echo
}

/******************************************************************************************************************/
/* Uitzenden en ontvangen van pulsen op de HCSR04 ultrasone sensor en de gemeten afstand weer te geven op het LCD */
/******************************************************************************************************************/
void dustinshcsr04_Run(void) 
{
	// Er moet een 10us trigger pulse gegeven worden op de trig-pin van de HC-SR04. 
	HCSR04_PORT |= SET_BIT(TRIGGER_PIN);	// Pin hoog
	_delay_us(10);							// Voor 10us
	HCSR04_PORT &= UNSET_BIT(TRIGGER_PIN);	// Pin laag
	
	TCNT1 = 0;								// Timer counter op 0 zetten (TCNT1 is het 16-bit timer/counter 1 register)  	Zie Atmega128 datasheet pagina 137.
	TCCR1B = SET_BIT(ICES1)|SET_BIT(CS10);	// Input Capture op Rising Edge, Geen prescaling								Zie Atmega128 datasheet pagina 135.
	TIFR = SET_BIT(ICF1);					// Legen van ICP flag (Input Capture flag)										Zie Atmega128 datasheet pagina 108.
	TIFR = SET_BIT(TOV1);					// Legen van Timer Overflow flag												Zie Atmega128 datasheet pagina 108.
	
	while ((TIFR & SET_BIT(ICF1)) == 0);	// Wachten op Rising Edge
	TCNT1 = 0;								// Legen van Timer Counter														Zie Atmega128 datasheet pagina 137.
	TCCR1B = SET_BIT(CS10);					// Input Capture op Falling Edge, Geen prescaling								Zie Atmega128 datasheet pagina 135.	
	TIFR = SET_BIT(ICF1);					// Legen van ICP flag (Input Capture flag)										Zie Atmega128 datasheet pagina 108.
	TIFR = SET_BIT(TOV1);					// Legen van Timer Overflow flag												Zie Atmega128 datasheet pagina 108.
	TIMER_OVERFLOW_COUNTER = 0;				// Legen van Timer Overflow Count												

	while ((TIFR & SET_BIT(ICF1)) == 0);	// Wachten op Falling Edge
	
	COUNT = ICR1 + (pow(2,16) * TIMER_OVERFLOW_COUNTER); // 16-bits register. Dus aantal malen Overflow maal 2^16
	
	dustinshcsr04_CalculateDistance();		// Bepalen van de afstand aan de hand van de hiervoor opgestelde methode

	dtostrf(DISTANCE*100, 2, 2, STRING);	// Afstand omzetten naar String. Maal 100 omdat ik cm's wil tonen
	strcat(STRING, "cm");					// Concat getal met cm 
	dustinslcd_CursorHome();				// Cursor naar Home
	dustinslcd_String("Afstand=");			// Tonen van "Afstand=" op LCD
	dustinslcd_String(STRING);				// Tonen van de afstand op het LCD 
	dustinssegment_DisplayNumber(&PORTB, (int)(DISTANCE*10)); // Tonen van de afstand in decimeters op één 7-segments display. Altijd naar beneden afronden door middel van een harde (int) cast, zodat er tot een hogere afstand weergegeven kan worden
}