/* 
 * File:   defines.h
 * Author: Raphael
 *
 * Created on May 21, 2022, 5:47 PM
 */

#define _XTAL_FREQ 20000000
#define MAX_LENGTH_UART 16

#define motorDireito                         PORTBbits.RB6
#define motorEsquerdo                        PORTBbits.RB7 
#define sensorDistancia_direito              PORTAbits.RA4    //RA0
#define sensorDistancia_frontalDireito       PORTAbits.RA1   //RA
#define sensorDistancia_central              PORTCbits.RC2   //RC2   
#define sensorDistancia_frontalEsquerdo      PORTAbits.RA2   //RA2
#define sensorDistancia_esquerdo             PORTAbits.RA3   //RA3
#define sensorLinha_frontalDireito           PORTAbits.AN5 //A5

//#define sensorLinha_traseiroDireito          PORTCbits.RC5  
//#define sensorLinha_traseiroEsquerdo         PORTEbits.RE1
#define sensorLinha_frontalEsquerdo          PORTEbits.RE0 //AN6
#define led0                                 PORTDbits.RD0 //LED AZUL
#define led1                                 PORTDbits.RD1 // LED VERDE

#define moduloStart                          PORTCbits.RC4