/*
 * GccApplication1.c
 *
 * Created: 27-3-2020 17:06:58
 * Author : Dustin
 */ 

#include "main.h"

/************************************************************************/
/* Alle initialisatie functies van het programma komen hier te staan    */
/************************************************************************/
void init(void) {
	dustinslcd_Init();					// Initialisatie van LCD uitvoeren
	dustinshcsr04_Init();				// Initialisatie van ultrasone HCSR04-sensor uitvoeren	
	DDRB = 0xFF;						// DDRB op output mode, deze wordt gebruikt door het 7-segments display
	sei();								// Inschakelen van interrupts
}

/************************************************************************/
/* Main programma                                                       */
/************************************************************************/
int main(void)
{	
	init();								// Initialisatie functies
	
	dustinslcd_String("Dustins demo");	// Weergeven van tekst "Dustins demo" op LCD regel 1
	dustinslcd_NextLine();				// Naar regel 2
	dustinslcd_String("Individueel");	// Weergeven van tekst "Individueel" op LCD regel 2
	dustinslcd_CursorHome();			// Cursor terug naar "home" positie (pos 0)
	dustinsutils_delay_ms(1000);		// "Splash screen" duurt 1s"
	dustinslcd_Clear();					// Legen van LCD
		
	while(1) {
		dustinshcsr04_Run();			// Uitvoeren van een afstandsmeting
		dustinsutils_delay_ms(500);		// Korte delay van 500ms 
		dustinslcd_Clear();
	}
}
