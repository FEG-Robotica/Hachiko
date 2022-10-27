/* 
 * File:   configMotor.h
 * Author: Raphael
 *
 * Created on May 21, 2022, 5:17 PM
 */
#ifndef CONFIGMOTOR_H
#define	CONFIGMOTOR_H

void moverMotor(char sentido, char lado, unsigned int porcVelo){
    motorDireito = 1;
    motorEsquerdo = 1;
    if(sentido=='f'){ 
          if (lado == 'd') { //mudei pro lado direito, qualquer coisa volta pro esquerdo
        setDutyPWM0(porcVelo); //PWMA
        setDutyPWM6(0); //PWMD
    }
    if (lado == 'e') {
        setDutyPWM2(porcVelo); //PWMB
        setDutyPWM4(0); //PWMC
    }
        
    } else {
          if (lado == 'd') {
        setDutyPWM0(0); //PWMA
        setDutyPWM6(porcVelo); //PWMD
    }
    if (lado == 'e') {
        setDutyPWM2(0); //PWMB
        setDutyPWM4(porcVelo); //PWMC
    }
        
    }
}

void PararMotor(){
    
    setDutyPWM0(0);
    setDutyPWM2(0);
    setDutyPWM4(0);
    setDutyPWM6(0);
    
}
#endif //CONFIG_MOTOR.H
