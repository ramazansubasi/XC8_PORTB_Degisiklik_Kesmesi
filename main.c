/* 
 * File:   main.c
 * Author: Ramazan Subasi (Subram)
 *
 * Created on 30 Mayis 2014 Cuma, 15:46
 */




#include <xc.h>
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CCPMX = RB0      // CCP1 Pin Selection bit (CCP1 function on RB0)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode disabled)

#define _XTAL_FREQ 4000000

void interrupt port_degisiklik (void){
    GIE=0;
    if (RBIF==1) {
        RB0=(RB4==0) ? 0 : 1;
        RB1=(RB5==0) ? 0 : 1;
        RB2=(RB6==0) ? 0 : 1;
        RB3=(RB7==0) ? 0 : 1;
    }
    RBIF=0;
    GIE=1;
}

void main(void) {
    ANSEL=0x00;     // Analog iptal, digital I/O
    TRISB=0xF0;     // Portb ilk 4 bit cikis, son 4 bit giris
    PORTB=0x0F;     // Portb temizlendi
    RBIE=1;         // Port degisiklik kesmesi aktif
    RBIF=0;         // Kesme bayragi sifirlaniyor
    GIE=1;          // Tum kesmeler aktif
    while(1);       // Sonsuz dongu
}

