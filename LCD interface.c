/************************************************************************                                                                     
*   Filename: Multiple ADC values displayed on LCD                          
*   Date: 23/07/2020                                                                                              
*                                                                       
*   Author: Kirubakaran                                                 
*     Blog: https://crazyembed.wordpress.com                                   
*                                                                       
*************************************************************************
*                                                                       
*   Architecture:  Enhanced Mid-range PIC                               
*   Processor:     16F1934                                              
*   Compiler:      MPLAB XC8  (Free mode)                          
*                                                                       
*************************************************************************
*                                                                      		 	
*   Files required: none                                                		
*                                                                       			
*************************************************************************

*                                                                      
*   Description: Interfacing LCD                           
*                                                                     
*                  
*                                                                       
*************************************************************************/
// PIC16F1934 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config VCAPEN = OFF     // Voltage Regulator Capacitor Enable (All VCAP pin functionality is disabled)
#pragma config PLLEN = ON       // PLL Enable (4x PLL enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include<stdint.h>
#define _XTAL_FREQ 1000000
void display(char a, char b);
void display_string(char *Str);
char A[]="Crazy", B[]="Embedded";

void main()
{
    TRISC=TRISD=LATD=LATC=0;
    display(0x0C,0);                            //cursor off ,display on
    while(1)
    {
       display(0x80,0);                         //cursor points 1st row 1st column
       display_string(A);
       display(0xC0,0);                         //cursor points 1st row 10th column
       display_string(B);
    }
}

void display(char a , char b)
{
    LATC = a;
    LATDbits.LATD0 = b;               //RS pin
    LATDbits.LATD1 = 1;               //enabl pin
    __delay_ms(10);
    LATDbits.LATD1 = 0;
    __delay_ms(10);
}

void display_string(char *Str)
{
   for(int i=0; Str[i]!='\0'; i++)
   display(Str[i],1);
}
