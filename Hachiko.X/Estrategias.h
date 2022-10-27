/* 
 * File:   Estrategias.h
 * Author: Raphael
 *
 * Created on October 4, 2022, 5:23 PM
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
#ifndef ESTRATEGIAS_H
#define	ESTRATEGIAS_H

void testeSensorSimples(){
    if(!sensorDistancia_esquerdo){
        moverMotor('f','d',10);
        moverMotor('f','e',10);
        UARTSendString("\nE\n",MAX_LENGTH_UART);
        
    }
    if(!sensorDistancia_frontalEsquerdo){
        moverMotor('f','d',10);
        moverMotor('f','e',10);
        UARTSendString("\nFE\n",MAX_LENGTH_UART);
        
    }
    if(!sensorDistancia_frontalDireito){
        moverMotor('f','d',10);
        moverMotor('f','e',10);
        UARTSendString("\nFD\n",MAX_LENGTH_UART);
        
    }
    
    if(!sensorDistancia_direito){
        moverMotor('f','d',10);
        moverMotor('f','e',10);
        UARTSendString("\nD\n",MAX_LENGTH_UART);
        
    }
        
    
    
    if(!sensorDistancia_central){
        moverMotor('f','d',10);
        moverMotor('f','e',10);
        UARTSendString("\nC\n",MAX_LENGTH_UART);
        
    }
    
    
}

void testeDistanciaMotor(){
    
    if(!sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && sensorDistancia_central && sensorDistancia_frontalDireito  && sensorDistancia_direito){ //apenas sensor esquerdo
                    moverMotor('t','e',60);
                    moverMotor('f','d',60);
                    UARTSendString("\nSD_E",MAX_LENGTH_UART);
                }
                else if(sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && !sensorDistancia_central && sensorDistancia_frontalDireito  && sensorDistancia_direito){  //apenas sensor do centro
                    moverMotor('f','e',100);                                              //MUDAR PRA 100 DEPOIS
                    moverMotor('f','d',100);
                    UARTSendString("\nSD_C",MAX_LENGTH_UART);
                }
                else if(sensorDistancia_esquerdo && !sensorDistancia_frontalEsquerdo && sensorDistancia_central && !sensorDistancia_frontalDireito  && sensorDistancia_direito){ //os frontais das pontas
                    moverMotor('f','e',100);            //MUDAR PARA 100
                    moverMotor('f','d',100);
                     UARTSendString("\nSD_FE e SD_FD\n",MAX_LENGTH_UART);
                }
                else if(sensorDistancia_esquerdo && !sensorDistancia_frontalEsquerdo && !sensorDistancia_central && !sensorDistancia_frontalDireito  && sensorDistancia_direito){ //sensor frontais e central
                    moverMotor('f','e',100);                                              //MUDAR PARA 100
                    moverMotor('f','d',100);
                    UARTSendString("\nFE C FD\n",MAX_LENGTH_UART);
                }
                else if(sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && sensorDistancia_central && !sensorDistancia_frontalDireito  && sensorDistancia_direito){  //apenas frontal direito
                    moverMotor('f','e',60);
                    moverMotor('t','d',60);
                    UARTSendString("\nSD_FD\n",MAX_LENGTH_UART);
                }
                else if(sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && !sensorDistancia_central && !sensorDistancia_frontalDireito  && sensorDistancia_direito){ //frontal direito e central
                    moverMotor('f','e',60);
                    moverMotor('t','d',60);
                    UARTSendString("\nSD_FC e SD_FD\n",MAX_LENGTH_UART);
                }
                else if(sensorDistancia_esquerdo && !sensorDistancia_frontalEsquerdo && sensorDistancia_central && sensorDistancia_frontalDireito  && sensorDistancia_direito){  //apenas frontal esquerdo
                    moverMotor('t','e',60);
                    moverMotor('f','d',60);
                    UARTSendString("\nSD_FE\n",MAX_LENGTH_UART);
                }
                else if(sensorDistancia_esquerdo && !sensorDistancia_frontalEsquerdo && !sensorDistancia_central && sensorDistancia_frontalDireito  && sensorDistancia_direito){ //frontal esquerdo e central
                    moverMotor('t','e',60);
                    moverMotor('f','d',60);
                    UARTSendString("\nSD_FE e SD_C\n",MAX_LENGTH_UART);
                }
                else if(sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && sensorDistancia_central && sensorDistancia_frontalDireito  && !sensorDistancia_direito){  //apenas direito
                    moverMotor('f','e',60);
                    moverMotor('t','d',60);
                    UARTSendString("\nSD_D\n",MAX_LENGTH_UART);
                } else {
                    PararMotor();
                    UARTSendString("\nNS\n",MAX_LENGTH_UART);
                    
                    
                }

    
    
    if(moduloStart==0){
        PararMotor();
        UARTSendString("\nFim..\n",MAX_LENGTH_UART);
    }
}


void Arco() {
    
    
    if(millis<500){
        testeDistanciaMotor();
        if(moduloStart==0){
            PararMotor();
        }
        
    } else {
        
                if(sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && sensorDistancia_central && sensorDistancia_frontalDireito  && sensorDistancia_direito){
                    moverMotor('f','d',75); //mudar para 75 porque deu top
                    moverMotor('f','e',90);
                    leituraSensorLinha();
                    if((leitura[5]==1) && (leitura[6]==1)){
                        
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                    __delay_ms(100);
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                    
                    
                        
                    } else if (leitura[5]==1){
                        
                        moverMotor('t','d',50); //mudar para 75 porque deu top
                        moverMotor('t','e',90);
                        __delay_ms(100);
                          moverMotor('t','d',50); //mudar para 75 porque deu top
                        moverMotor('t','e',90);
                    
                        
                        
                    } else if (leitura[6]==1){
                        
                        moverMotor('t','d',90); //mudar para 75 porque deu top
                        moverMotor('t','e',50);
                        __delay_ms(100);
                          moverMotor('t','d',90); //mudar para 75 porque deu top
                        moverMotor('t','e',50);
                        
                        
                    }
                    UARTSendString("\nSN\n",MAX_LENGTH_UART);
                    
                }
                else if( !sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && sensorDistancia_central && sensorDistancia_frontalDireito  && sensorDistancia_direito){ //apenas sensor esquerdo
                    moverMotor('t','e',60);
                    moverMotor('f','d',60);
                    UARTSendString("\nSD_E\n",MAX_LENGTH_UART);
                    
                }
                else if(sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && !sensorDistancia_central && sensorDistancia_frontalDireito  && sensorDistancia_direito){  //apenas sensor do centro
                    moverMotor('f','e',100);                                              //MUDAR PRA 100 DEPOIS
                    moverMotor('f','d',100);
                    UARTSendString("\nSD_C\n",MAX_LENGTH_UART);
                                       
                    
                }
                else if(sensorDistancia_esquerdo && !sensorDistancia_frontalEsquerdo && sensorDistancia_central && !sensorDistancia_frontalDireito  && sensorDistancia_direito){ //os frontais das pontas
                    moverMotor('f','e',100);                                              //lembrar de mudar para 100 (0 apenas teste)
                    moverMotor('f','d',100);
                    UARTSendString("\nSD_FE e SD_FD\n",MAX_LENGTH_UART);
                    
                    
                }
                 else if(sensorDistancia_esquerdo && !sensorDistancia_frontalEsquerdo && !sensorDistancia_central && !sensorDistancia_frontalDireito  && sensorDistancia_direito){ //sensor frontais e central
                    moverMotor('f','e',100);                                              //MUDAR PARA 100
                    moverMotor('f','d',100);
                    UARTSendString("\nFE C FD\n",MAX_LENGTH_UART);
                }
                else if(sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && sensorDistancia_central && !sensorDistancia_frontalDireito  && sensorDistancia_direito){  //apenas frontal direito
                    moverMotor('f','e',60);
                    moverMotor('t','d',60);
                    UARTSendString("\nSD_FD\n",MAX_LENGTH_UART);
                    
                }
                else if(sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && !sensorDistancia_central && !sensorDistancia_frontalDireito  && sensorDistancia_direito){ //frontal direito e central
                    moverMotor('f','e',60);
                    moverMotor('t','d',60);
                    UARTSendString("\nSD_C e SD_FDn",MAX_LENGTH_UART);
                }
                    
                else if(sensorDistancia_esquerdo && !sensorDistancia_frontalEsquerdo && sensorDistancia_central && sensorDistancia_frontalDireito  && sensorDistancia_direito){  //apenas frontal esquerdo
                    moverMotor('t','e',60);
                    moverMotor('f','d',60);
                    UARTSendString("\nSD_FE",MAX_LENGTH_UART);
                    
                    
                }
                else if(sensorDistancia_esquerdo && !sensorDistancia_frontalEsquerdo && !sensorDistancia_central && sensorDistancia_frontalDireito  && sensorDistancia_direito){ //frontal esquerdo e central
                    moverMotor('t','e',60);
                    moverMotor('f','d',60);
                    UARTSendString("\nSD_FE e SD_C",MAX_LENGTH_UART);
                    
                }
                else if(sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && sensorDistancia_central && sensorDistancia_frontalDireito  && !sensorDistancia_direito){  //apenas direito
                    moverMotor('f','e',60);
                    moverMotor('f','d',60);
                    UARTSendString("\nSD_D",MAX_LENGTH_UART);
                                        
                }
                else{
                    
                    moverMotor('f','d',75); //mudar para 75 porque deu top
                    moverMotor('f','e',90);
                    leituraSensorLinha();
                    if((leitura[5]==1) && (leitura[6]==1)){
                        
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                    leituraSensorLinha();
                    __delay_ms(50);
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                    __delay_ms(50);
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                        
                    } else if (leitura[5]==1){
                        
                        moverMotor('t','d',75); //mudar para 75 porque deu top
                        moverMotor('t','e',90);
                        leituraSensorLinha();
                        __delay_ms(50);
                        moverMotor('t','d',75); //mudar para 75 porque deu top
                        moverMotor('t','e',90);
                        __delay_ms(50);
                        moverMotor('t','d',75); //mudar para 75 porque deu top
                        moverMotor('t','e',90);
                        
                        
                    } else if (leitura[6]==1){
                        
                        moverMotor('t','d',90); //mudar para 75 porque deu top
                        moverMotor('t','e',50);
                        leituraSensorLinha();
                        __delay_ms(50);
                        moverMotor('t','d',90); //mudar para 75 porque deu top
                        moverMotor('t','e',50);
                        __delay_ms(50);
                        moverMotor('t','d',90); //mudar para 75 porque deu top
                        moverMotor('t','e',50);
                        
                    }
                    
                    
                    UARTSendString("\nNS",MAX_LENGTH_UART);
                }
                if(comando=="idle"){
                    PararMotor();
                }
                if(moduloStart==0){
                    PararMotor();
                }
                if(millis>2500){
                  resetaMillis();  
                }
        
                }}

    


void toquinho (){
    
    if(millis<500){
        testeDistanciaMotor();
        if(moduloStart==0){
            PararMotor();
        }
    } else {
         if(sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && sensorDistancia_central && sensorDistancia_frontalDireito  && sensorDistancia_direito){
                    moverMotor('f','d',75); //mudar para 75 porque deu top
                    moverMotor('f','e',75);
                    leituraSensorLinha();
                    if((leitura[5]==1) && (leitura[6]==1)){
                        
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                    leituraSensorLinha();
                    __delay_ms(50);
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                    __delay_ms(50);
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                    
                        
                    } else if (leitura[5]==1){
                        
                        moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                    leituraSensorLinha();
                    __delay_ms(50);
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                    __delay_ms(50);
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                        
                    } else if (leitura[6]==1){
                       moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                    leituraSensorLinha();
                    __delay_ms(50);
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                    __delay_ms(50);
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                    }
                }
                else if( !sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && sensorDistancia_central && sensorDistancia_frontalDireito  && sensorDistancia_direito){ //apenas sensor esquerdo
                    moverMotor('t','e',60);
                    moverMotor('f','d',60);
                                        
                }
                else if(sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && !sensorDistancia_central && sensorDistancia_frontalDireito  && sensorDistancia_direito){  //apenas sensor do centro
                    moverMotor('f','e',100);                                              //MUDAR PRA 100 DEPOIS
                    moverMotor('f','d',100);
                    leituraSensorLinha();
                    
                                       
                }
                else if(sensorDistancia_esquerdo && !sensorDistancia_frontalEsquerdo && sensorDistancia_central && !sensorDistancia_frontalDireito  && sensorDistancia_direito){ //os frontais das pontas
                    moverMotor('f','e',100);                                              //lembrar de mudar para 100 (0 apenas teste)
                    moverMotor('f','d',100);
                    leituraSensorLinha();
                                                            
                }
          else if(sensorDistancia_esquerdo && !sensorDistancia_frontalEsquerdo && !sensorDistancia_central && !sensorDistancia_frontalDireito  && sensorDistancia_direito){ //sensor frontais e central
                    moverMotor('f','e',100);                                              //MUDAR PARA 100
                    moverMotor('f','d',100);
                    UARTSendString("\nFE C FD\n",MAX_LENGTH_UART);
                }
         
                else if(sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && sensorDistancia_central && !sensorDistancia_frontalDireito  && sensorDistancia_direito){  //apenas frontal direito
                    moverMotor('f','e',60);
                    moverMotor('t','d',60);
                    
                }
                else if(sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && !sensorDistancia_central && !sensorDistancia_frontalDireito  && sensorDistancia_direito){ //frontal direito e central
                    moverMotor('f','e',60);
                    moverMotor('t','d',60);
                    
                }
                else if(sensorDistancia_esquerdo && !sensorDistancia_frontalEsquerdo && sensorDistancia_central && sensorDistancia_frontalDireito  && sensorDistancia_direito){  //apenas frontal esquerdo
                    moverMotor('t','e',60);
                    moverMotor('f','d',60);
                    
                }
                else if(sensorDistancia_esquerdo && !sensorDistancia_frontalEsquerdo && !sensorDistancia_central && sensorDistancia_frontalDireito  && sensorDistancia_direito){ //frontal esquerdo e central
                    moverMotor('t','e',60);
                    moverMotor('f','d',60);
                    
                }
                else if(sensorDistancia_esquerdo && sensorDistancia_frontalEsquerdo && sensorDistancia_central && sensorDistancia_frontalDireito  && !sensorDistancia_direito){  //apenas direito
                    moverMotor('f','e',60);
                    moverMotor('t','d',60);
                   
                }
                else{
                    
                    moverMotor('f','d',70); //mudar para 75 porque deu top
                    moverMotor('f','e',70);
                    leituraSensorLinha();
                    if((leitura[5]==1) && (leitura[6]==1)){
                        
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                    leituraSensorLinha();
                    __delay_ms(50);
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                    __delay_ms(50);
                    moverMotor('t','d',50); //mudar para 75 porque deu top
                    moverMotor('t','e',90);
                        
                    } else if (leitura[5]==1){
                        
                        moverMotor('t','d',75); //mudar para 75 porque deu top
                        moverMotor('t','e',90);
                        leituraSensorLinha();
                        __delay_ms(50);
                        moverMotor('t','d',75); //mudar para 75 porque deu top
                        moverMotor('t','e',90);
                        __delay_ms(50);
                        moverMotor('t','d',75); //mudar para 75 porque deu top
                        moverMotor('t','e',90);
                        
                        
                    } else if (leitura[6]==1){
                        
                        moverMotor('t','d',90); //mudar para 75 porque deu top
                        moverMotor('t','e',50);
                        leituraSensorLinha();
                        __delay_ms(50);
                        moverMotor('t','d',90); //mudar para 75 porque deu top
                        moverMotor('t','e',50);
                        __delay_ms(50);
                        moverMotor('t','d',90); //mudar para 75 porque deu top
                        moverMotor('t','e',50);
                        
                    }
                }
              if(comando=="idle"){
                    PararMotor();
                }
         if(moduloStart==0){
             PararMotor();
         }
         if(millis>2000){
             resetaMillis();
         }
         
        
            
        
    }
    }
 

/*
void estrela(){
    
    if((leitura[5]==0) && (leitura[6]==0)){
        while((leitura[5]==0) && (leitura[6]==0)){
        testeDistanciaMotor();
        moverMotor('d','f',70);
        moverMotor('d','f',70);
        }}
    else{
        if((leitura[5]==1) && (leitura[6]==0)){
            
        moverMotor('d','f',60);
        moverMotor('e','t',60);
        __delay_ms(50);
        moverMotor('d','f',60);
        moverMotor('e','t',60);
            
        } 
        
        if( (leitura[5]==0) && (leitura[6]==1) ){
            
             moverMotor('d','t',60);
             moverMotor('e','f',60);
             __delay_ms(50);
             moverMotor('d','t',60);
             moverMotor('e','f',60);
             
            
    } 
        
       if((leitura[5]==1) && (leitura[6]==1)){
           while((leitura[5]==1) || (leitura[6]==1)) {
        moverMotor('d','t',60);
        moverMotor('e','t',60);
        __delay_ms(50);
        PararMotor();
        __delay_ms(50);
        moverMotor('d','t',60);
        moverMotor('e','f',60);
           }
                 
    } else {
           testeDistanciaMotor();
    }
    }
    if(moduloStart==0){
        PararMotor();
    }

}
     
 */   


 
#endif //ESTRATEGIAS_H






