/* 
 * File:   pwm.h
 * Author: Raphael
 *
 * Created on May 21, 2022, 4:59 PM
 */

#define VELOCIDADE_MAXIMA 6
#ifndef PWM_H
#define	PWM_H

void configPWM() {

    PTCON0 = 0b00000000; // 4 primeiros bits definem pre scale 1:1; 3~2 bits definem pos scale 1:1; 0~1 definem free running mode
    PTCON1 = 0b10000000; // habilita a base de tempo do pwm
    PWMCON0 = 0b01011111;
    PWMCON1 = 0b00000001;
    DTCON = 0b00010000;
    OVDCOND = 0b11111111; //saída pwm controlada pelo valor de duty cicle e base de tempo pwm
    OVDCONS = 0b00000000;
    PTPERL = 0b10010110; //PTPERMAX=4*150
    PTPERH = 0b00000000;

}

void setDutyPWM0(unsigned int porcVelo) { //PWMA
    unsigned int velo = porcVelo*VELOCIDADE_MAXIMA;
    PDC0L = velo & 0b11111111;
    PDC0H = (velo >> 8) & 0b11111111;
}

void setDutyPWM2(unsigned int porcVelo) { //PWMB
    unsigned int velo = porcVelo*VELOCIDADE_MAXIMA;
    PDC1L = velo & 0b11111111;
    PDC1H = (velo >> 8) & 0b11111111;
}

void setDutyPWM4(unsigned int porcVelo) { //PWMC
    unsigned int velo = porcVelo*VELOCIDADE_MAXIMA;
    PDC2L = velo & 0b11111111;
    PDC2H = (velo >> 8) & 0b11111111;
}

void setDutyPWM6(unsigned int porcVelo) { //PWMD
    unsigned int velo = porcVelo*VELOCIDADE_MAXIMA;
    PDC3L = velo & 0b11111111;
    PDC3H = (velo >> 8) & 0b11111111;
}

#endif //PWM_H