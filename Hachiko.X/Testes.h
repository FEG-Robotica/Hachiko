/* 
 * File:   Testes.h
 * Author: Raphael
 *
 * Created on June 13, 2022, 9:36 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "pwm.h"
#include "config.h"
#include "Timer.h"
#include "configMotor.h"
#include "ADC.h"
#include "bluetooth.h"
#include "configSensorLinha.h"
#ifndef TESTES_H
#define	TESTES_H

void testeMotores(){ //TESTAR NA BANCADA
    
    int i;
    motorDireito = 1;
    motorEsquerdo = 1;
    
    //PWM A
    
    UARTSendString("PWMA testando\n",MAX_LENGTH_UART);
    for(i = 0; i <= 100; i++){
        setDutyPWM0(i);
        __delay_ms(20);
        if(myStrncmp(comando, "idle")) break;
    }
    setDutyPWM0(0);
    UARTSendString("PWMA teste fim\n",MAX_LENGTH_UART);
    
    
    //PWM D
    UARTSendString("PWMD testando\n",MAX_LENGTH_UART);
    for(i = 0; i <= 100; i++){
        setDutyPWM6(i);
        __delay_ms(20);
        if(myStrncmp(comando, "idle")) break;
    }
    setDutyPWM6(0);
    UARTSendString("PWMD teste fim\n",MAX_LENGTH_UART);
    
    //PWM B
    UARTSendString("PWMB testando\n",MAX_LENGTH_UART);
    for(i = 0; i <= 100; i++){
        setDutyPWM2(i);
        __delay_ms(20);
        if(myStrncmp(comando, "idle")) break;
    }
    setDutyPWM2(0);
    UARTSendString("PWMB teste fim\n",MAX_LENGTH_UART);
    
    //PWM C
    UARTSendString("PWMC teste\n",MAX_LENGTH_UART);
    for(i = 0; i <= 100; i++){
        setDutyPWM4(i);
        __delay_ms(20);
        if(myStrncmp(comando, "idle")) break;
    }
    setDutyPWM4(0);
    UARTSendString("PWMC teste fim\n",MAX_LENGTH_UART);
    
    
    //PWM A e PWM B
    UARTSendString("PWMA e B teste\n",MAX_LENGTH_UART);
    for(i = 0; i <= 100; i++){
        setDutyPWM0(i);
        setDutyPWM2(i);
        __delay_ms(20);
        if(myStrncmp(comando, "idle")) break;
    }
    setDutyPWM0(0);
    setDutyPWM2(0);
    UARTSendString("PWMA e B fim\n",MAX_LENGTH_UART);
    
    //PWM A e PWM C
    UARTSendString("PWMA e C teste\n",MAX_LENGTH_UART);
    for(i = 0; i <= 100; i++){
        setDutyPWM0(i);
        setDutyPWM4(i);
        __delay_ms(20);
        if(myStrncmp(comando, "idle")) break;
    }
    setDutyPWM0(0);
    setDutyPWM4(0);
    UARTSendString("PWMA e C fim\n",MAX_LENGTH_UART);
    
    //PWM D e PWM B
    UARTSendString("PWMD e B teste\n",MAX_LENGTH_UART);
    for(i = 0; i <= 100; i++){
        setDutyPWM6(i);
        setDutyPWM2(i);
        __delay_ms(20);
        if(myStrncmp(comando, "idle")) break;
    }
    setDutyPWM6(0);
    setDutyPWM2(0);
    
    UARTSendString("PWMD e B fim\n",MAX_LENGTH_UART);
    
    //PWM D e PWM C
    UARTSendString("PWMD e C teste\n",MAX_LENGTH_UART);
    for(i = 0; i <= 100; i++){
        setDutyPWM6(i);
        setDutyPWM4(i);
        __delay_ms(20);
        if(myStrncmp(comando, "idle")) break;
    }
    setDutyPWM6(0);
    setDutyPWM4(0);
    UARTSendString("PWMD e C fim\n",MAX_LENGTH_UART);
    UARTSendString("PWM finalizado\n",MAX_LENGTH_UART);
    
    if(moduloStart==0){
    setDutyPWM0(0); //PWMA
    setDutyPWM6(0);//PWMD
    setDutyPWM2(0);//PWMB
    setDutyPWM4(0);//PWMC  
    } 
    
}

void testeSensoresDistancia(){
    
    if(sensorDistancia_direito){ //sensor de distância é ativo baixo
        UARTSendString("\n S_D=false\n",MAX_LENGTH_UART);
    } else {
        UARTSendString("\n S_D=true\n",MAX_LENGTH_UART);
    }
    
    if(sensorDistancia_frontalDireito){ //SENSOR PEPPERL
        UARTSendString("\n S_FD=false\n",MAX_LENGTH_UART);
       } else {
        UARTSendString("\n S_FD=true\n",MAX_LENGTH_UART);
       }
    
    if(sensorDistancia_central){ //CENTRAL É BANNER
        UARTSendString("\n S_CE=false\n",MAX_LENGTH_UART);
    } else {
        UARTSendString("\n S_CE=true\n",MAX_LENGTH_UART);
    }
    if(sensorDistancia_frontalEsquerdo ){
        UARTSendString("\n S_FE=false\n",MAX_LENGTH_UART);
       } else {
        UARTSendString("\n S_FE=true\n",MAX_LENGTH_UART);
       }
    if(sensorDistancia_esquerdo){
        UARTSendString("\n S_E=false\n",MAX_LENGTH_UART);
       } else {
        UARTSendString("\n S_E=true\n",MAX_LENGTH_UART);
       }
    
    UARTSendString("-----------------------\n",MAX_LENGTH_UART);
       
}

void testeADbit(){
            for (int i = 5; i < 7; i++) {
                char string[2] = {'\0'};
                
                string[0] = i + '0';
                
                UARTSendString(string,MAX_LENGTH_UART);
                UARTSendString("\n", MAX_LENGTH_UART);
                UARTSendString(valorConvUARTbit(getAD_ANbit(i)), MAX_LENGTH_UART);
                UARTSendString("\n", MAX_LENGTH_UART);
                UARTSendString("----------",MAX_LENGTH_UART);
                UARTSendString("\n",MAX_LENGTH_UART);
            }
    __delay_ms(2000);
}

void testeSensorDeLinha(){
    
    UARTSendString("AN5: ",MAX_LENGTH_UART);
    UARTSendString(valorConvUARTbit( getAD_ANbit(5)), MAX_LENGTH_UART);
    UARTSendString("\n",MAX_LENGTH_UART);
    
    UARTSendString("AN6: ",MAX_LENGTH_UART);
    UARTSendString(valorConvUARTbit(getAD_ANbit(6)), MAX_LENGTH_UART);
    UARTSendString("\n",MAX_LENGTH_UART);
     
    
    UARTSendString("----------",MAX_LENGTH_UART);
    UARTSendString("\n",MAX_LENGTH_UART);
    
    __delay_ms(500);
}

void moverPraFrente(){
    
    motorDireito = 1;
    motorEsquerdo = 1;
    
    setDutyPWM0(100); //PWMA
    setDutyPWM6(0);//PWMD
    
    setDutyPWM2(100);//PWMB
    setDutyPWM4(0);//PWMC
    
    UARTSendString("\nPWMA e B\n ",MAX_LENGTH_UART);
    UARTSendString("\n---------\n",MAX_LENGTH_UART);
    
    
    if(myStrncmp(comando, "idle")){
    setDutyPWM0(0); //PWMA
    setDutyPWM6(0);//PWMD
    
    setDutyPWM2(0);//PWMB
    setDutyPWM4(0);//PWMC
    }
    
    if(moduloStart==0){
        
        setDutyPWM0(0); //PWMA
    setDutyPWM6(0);//PWMD
    
    setDutyPWM2(0);//PWMB
    setDutyPWM4(0);//PWMC
        
    }
}
    
    void PrintModuloStart(){
        int valorModuloStart = moduloStart;
        
        UARTSendString("\nValor:\n",MAX_LENGTH_UART);
        UARTSendString(valorConvUART(valorModuloStart),MAX_LENGTH_UART);
        UARTSendString("\n-----------\n",MAX_LENGTH_UART);
        
        
             
    
    }
    
    void testeLadoMotor(){
        
        motorDireito = 1;
        motorEsquerdo = 1;
        
        setDutyPWM2(0); //PWMB
        setDutyPWM4(50); //PWMC
       
        
    }


#endif	/* TESTES_H */