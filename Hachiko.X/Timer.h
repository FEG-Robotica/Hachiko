/* 
 * File:   Timer.h
 * Author: Raphael
 *
 * Created on May 21, 2022, 5:01 PM
 */
#ifndef TIMER_H
#define	TIMER_H
unsigned long millis = 0;

void initTimer0(int tempoInicial){ //TempoTotal = (256 - tempoInicial)*prescaler*CicloMaquina
                                   //CicloMaquina = 4/Fcristal
    //99 para 1 ms
    T0CON = 0b11010100;
    TMR0L = tempoInicial;
}

void desligaTimer0(){
    TMR0ON = 0;
}

void ligaTimer0(){
    TMR0ON = 1;
}

void resetaMillis(){
    millis = 0;
}

#endif	/* TIMER_H */