/*
 * dustinssegment.c
 *
 * Created: 28-3-2020 18:46:51
 *  Author: Dustin
 */ 

#include "dustinssegment.h"

/****************************************************************************************/
/* Lijst van getallen die gevormd worden door specifieke segmenten aan of uit te zetten */
/****************************************************************************************/
uint8_t numbers[] =
{
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F,		//0
	SEG_F|SEG_E,								//1
	SEG_A|SEG_B|SEG_G|SEG_E|SEG_D,				//2
	SEG_A|SEG_B|SEG_G|SEG_C|SEG_D,			    //3
	SEG_F|SEG_B|SEG_G|SEG_C,					//4
	SEG_A|SEG_F|SEG_G|SEG_C|SEG_D,				//5
	SEG_A|SEG_F|SEG_G|SEG_C|SEG_D|SEG_E,		//6
	SEG_A|SEG_B|SEG_C,							//7
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G,	//8
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_F|SEG_G,		//9
	SEG_A|SEG_B|SEG_C|SEG_E|SEG_F|SEG_G,		//A
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G,	//B
	SEG_A|SEG_D|SEG_E|SEG_F,					//C
	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F,		//D
	SEG_A|SEG_D|SEG_E|SEG_F|SEG_G,				//E
	SEG_A|SEG_E|SEG_F|SEG_G,					//F
	SEG_DP										//DP
};

/************************************************************************/
/* Weergeven van een getal op het 7-segments-display                    */
/* uint8_t *port: Pointer naar de betreffende port op het AVR bord		*/
/* uint8_t number: Getal wat weergegeven moet worden op het 7-segments	*/
/************************************************************************/
void dustinssegment_DisplayNumber(volatile uint8_t *port, uint8_t number) {
	if (number>-1 && number<(sizeof(numbers)/sizeof(uint8_t)))	// Als een getal van (inclusief) 0 tot de array grootte ligt, kan deze weergegeven worden
		*port = numbers[number];								// Weergeven van een (hex) getal op het 7-segments display wat aangesloten zit op poort [*port]
}
