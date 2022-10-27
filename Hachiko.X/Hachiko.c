/* 
 * File:   Hachiko.c
 * Author: Raphael
 *
 * Created on May 21, 2022, 5:51 PM
 */


#include <xc.h>
#include <pic18f4431.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bluetooth.h"
#include "defines.h"
#include "pwm.h"
#include "config.h"
#include "Timer.h"
#include "configMotor.h"
#include "ADC.h"
#include "Testes.h"
#include "configSensorLinha.h"
#include "Estrategias.h"

char recebidoChar;

void __interrupt() ISR(void) {

    if (PIR1bits.RCIF) {

        if (RCSTAbits.FERR || RCSTAbits.OERR) {
            RCSTAbits.OERR = 1;
            RCSTAbits.CREN = 0;
            RCSTAbits.CREN = 1;
        }

        recebidoChar = UARTReadChar();

        if (RCREG == '1') {
            ligaTimer0();
            UARTSendString("Timer0 on", MAX_LENGTH_UART);
        }

        if (RCREG == 'a') {
            setComando("testeMotores");
            UARTSendString(comando, MAX_LENGTH_UART);
        }

        if (RCREG == 'b') {
            setComando("testeSensoresDistancia");
            UARTSendString(comando, MAX_LENGTH_UART);
        }

        if (RCREG == 'c') {
            setComando("testeSensoresLinha");
            UARTSendString(comando, MAX_LENGTH_UART);
        }

        if (RCREG == 'd') {
            setComando("moverPraFrente");
            UARTSendString(comando, MAX_LENGTH_UART);
        }
        
        if (RCREG == 'e') {
            setComando("testeSensorDigital");
            UARTSendString(comando, MAX_LENGTH_UART);
            
        }
        if (RCREG == 'f') {
            setComando("testeModuloStart");
            UARTSendString(comando, MAX_LENGTH_UART);
            
        }
        if (RCREG == 'g') {
            setComando("testeDistanciaMotor");
            UARTSendString(comando, MAX_LENGTH_UART);
         }
        
        if (RCREG == 'A') {
            setComando("arco");
            UARTSendString(comando, MAX_LENGTH_UART);
            
        }
        
        if (RCREG == 'B') {
            setComando("toquinho");
            UARTSendString(comando, MAX_LENGTH_UART);
            
        }
        /*if (RCREG == 'C') {
            setComando("estrela");
            UARTSendString(comando, MAX_LENGTH_UART);
            
        }*/
       
        

        if (RCREG == 'p') {
            setComando("idle");
            UARTSendString("IDLE", MAX_LENGTH_UART);
            setDutyPWM0(0);
            setDutyPWM2(0);
            setDutyPWM4(0);
            setDutyPWM6(0);

             UARTSendString(comando, MAX_LENGTH_UART);
        }
        PIR1bits.RCIF = 0;
    }

    if (TMR0IF) {
        TMR0L = 99; //99 0b01100011;
        millis++;
        TMR0IF = 0;
    }
}

void main(void) {

    /*seta todas as portas do PORTA como an
     * e as portas RE0, RE1 e RE2 como an
     */
        
    
    
    __delay_ms(20);

    setIO();//configuração I/O

    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.TMR0IE = 1;

    configBits();
    configUSART();
    configPWM();
    configAD();
    ligaTimer0();

    initTimer0(99);

    comando = "\0";

    
    
    while(moduloStart==0){
        UARTSendString("Esperando...",MAX_LENGTH_UART);
        __delay_ms(500);
    }
              

    while (1) {
         testeDistanciaMotor();
        
      /*  if (myStrncmp(comando, "idle")) { //compara primeiro o "idle" para interrupção
            UARTSendChar(UARTReadChar());
        } 

        if (myStrncmp(comando, "testeMotores")) {
            //testeMotores();
            testeMotores();
        }

        
        if (myStrncmp(comando, "testeSensoresDistancia")) {
            testeSensoresDistancia();
            __delay_ms(1000);
        }
        
        if (myStrncmp(comando, "testeSensoresLinha")) {
                     
            testeSensorDeLinha();
            __delay_ms(500);
        }
        
        if (myStrncmp(comando, "testeSensorDigital")) {
            leituraSensorLinha();
            testeSensorDigital();
            __delay_ms(1000);
        }
        if (myStrncmp(comando, "testeModuloStart")) {
            PrintModuloStart();
            __delay_ms(500);
        }
        
        if (myStrncmp(comando, "testeDistanciaMotor")) {
           testeDistanciaMotor();
             UARTSendString("\nTeste distância...o\n",MAX_LENGTH_UART);
            
        }
        
        if (myStrncmp(comando, "arco")) {
            Arco();
             UARTSendString("\nTeste arco\n",MAX_LENGTH_UART);
         }
        if (myStrncmp(comando, "toquinho")) {
            toquinho();
             UARTSendString("\nTeste toquinho...\n",MAX_LENGTH_UART);
         }
       /* if (myStrncmp(comando, "estrela")) {
            estrela();
            UARTSendString("\nTeste estrela...\n",MAX_LENGTH_UART);
        }
                   
           

        if (myStrncmp(comando, "moverPraFrente")) {
            moverPraFrente();
        }*/
        
        
        while(moduloStart==0){
            PararMotor();
            UARTSendString("\nFim!\n",MAX_LENGTH_UART);
            __delay_ms(500);
            
        }

    }
   
    
}
