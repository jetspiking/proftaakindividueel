/*
 * dustinslcd.c
 *
 * Created: 27-3-2020 17:44:36
 *  Author: Dustin
 */ 

#include "dustinslcd.h"		

#define LCD_WIDTH_PIXELS 16							// Aantal tekens breed wat het LCD telt
#define LCD_LINES 2									// Aantal regels wat het LCD telt

/************************************************************************/
/* Versturen van een Command naar het LCD                               */
/************************************************************************/
void dustinslcd_Command(unsigned char commands)
{
	LCD_PORT &= UNSET_BIT(RESET);					// Register select
	dustinslcd_SplitSend(commands);					// Commando doorsturen in twee delen wegens de 4-bit modus
}

/************************************************************************/
/* Weergeven van een Char op het LCD                                    */
/************************************************************************/
void dustinslcd_Char(unsigned char string)
{
	LCD_PORT |= SET_BIT(RESET);						// RESET=1 selecteren data register
	dustinslcd_SplitSend(string);					// Commando doorsturen in twee delen wegens de 4-bit modus
}

/************************************************************************/
/* Versturen van een hoge en lage nibble naar het LCD wegens 4-bit mode */
/************************************************************************/
void dustinslcd_SplitSend(unsigned char string) {
	LCD_PORT = (LCD_PORT & 0x0F) | (string & 0xF0);	// Stuur de hoge nibble
	LCD_PORT |= SET_BIT(ENABLE);					// Hoge puls naar enable pin
	_delay_us(1);									// Korte delay na het zetten van de enable-pin
	LCD_PORT &= UNSET_BIT(ENABLE);					// Lage puls naar enable pin
	_delay_us(200);									// Korte delay na het onzetten van de enable-pin
	LCD_PORT = (LCD_PORT & 0x0F) | (string << 4);	// Stuur de lage nibble
	LCD_PORT |= SET_BIT(ENABLE);					// Hoge puls naar enable pin
	_delay_us(1);									// Korte delay na het zetten van de enable-pin
	LCD_PORT &= UNSET_BIT(ENABLE);					// Lage puls naar enable pin
	_delay_ms(2);									// Korte delay na het onzetten van de enable-pin
}

/************************************************************************/
/* Tonen van een complete String op het LCD                             */
/************************************************************************/
void dustinslcd_String (char *str)
{
	int j;
	for(j=0;str[j]!=0;j++)							// Printen van een String kan eenvoudig door het aanroepen van de Char functie
		dustinslcd_Char(str[j]);
}

/************************************************************************/
/* Legen van het LCD                                                    */
/************************************************************************/
void dustinslcd_Clear(void)
{
	dustinslcd_Command (0x01);						// Leeg display
	_delay_ms(2);
}

/************************************************************************/
/* Cursor naar de startpositie op het LCD (regel 0 char 0)              */
/************************************************************************/
void dustinslcd_CursorHome(void) {
	dustinslcd_Command(0x80);						// Cursor terug naar start positie
}

/************************************************************************/
/* Ìnitialisatiemethode voor het LCD scherm                             */
/************************************************************************/
void dustinslcd_Init(void) {
	LCD_DIRECTION = 0xFF;							// LCD = output directie
	_delay_ms(20);
	dustinslcd_Command(0x02);						// 4-bit initialisatie
	dustinslcd_Command(0x28);                       // 2 line, 5*7 matrix in 4-bit mode geselecteerd
	dustinslcd_Command(0x0c);                       // Scherm aan cursor uit.
	dustinslcd_Command(0x06);                       // Cursor 1 naar rechts
	dustinslcd_Command(0x01);                       // Leeg display
	_delay_ms(2);
}

/************************************************************************/
/* Naar de volgende regel op het LCD scherm                             */
/************************************************************************/
void dustinslcd_NextLine(void) {
	dustinslcd_Command(0xC0);						// Naar volgende regel
}

/************************************************************************/
/* Instellen van de cursor positie op het LCD                           */
/************************************************************************/
void dustinslcd_SetCursorPos(int position) {
	dustinslcd_Command(position < LCD_WIDTH_PIXELS ? 0x80+position : position<(LCD_LINES*LCD_WIDTH_PIXELS) ? 0xC0+(position-LCD_WIDTH_PIXELS) : 0xC0); // Cursor naar betreffende positie zetten
}

/************************************************************************/
/* Uitschakelen van het LCD                                             */
/************************************************************************/
void dustinslcd_Off(void) {
	dustinslcd_Command(0x08);						// LCD uitzetten
}

/************************************************************************/
/* Instellen van een knipperende cursor op het LCD                      */
/************************************************************************/
void dustinslcd_BlinkingCursor(void) {
	dustinslcd_Command(0x0F);						// Knipperende cursor
}

/************************************************************************/
/* Instellen van een vaste cursor op het LCD                            */
/************************************************************************/
void dustinslcd_SteadyCursor(void) {
	dustinslcd_Command(0x0E);						// LCD "static" cursor
}

/************************************************************************/
/* Alle tekst op het LCD één karakter naar links verschuiven            */
/************************************************************************/
void dustinslcd_ShiftLeft(void) {
	dustinslcd_Command(0x18);						// LCD naar links shiften
}

/************************************************************************/
/* Alle tekst op het LCD één karakter naar rechts verschuiven           */
/************************************************************************/
void dustinslcd_ShiftRight(void) {
	dustinslcd_Command(0x1C);						// LCD naar rechts shiften
}

/************************************************************************/
/* De cursor één karakter naar links verschuiven                        */
/************************************************************************/
void dustinslcd_ShiftCursorLeft(void) {
	dustinslcd_Command(0x10);						// Cursor naar links shiften
}

/************************************************************************/
/* De cursor één karakter naar rechts verschuiven                       */
/************************************************************************/
void dustinslcd_ShiftCursorRight(void) {
	dustinslcd_Command(0x14);						// Cursor naar rechts shiften
}