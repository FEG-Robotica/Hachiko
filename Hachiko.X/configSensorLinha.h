/* 
 * File:   configSensorLinha.h
 * Author: FEG Robótica
 *
 * Created on 1 de Setembro de 2022, 19:07
 */

#ifndef CONFIGSENSORLINHA_H
#define	CONFIGSENSORLINHA_H

double leitura[7];//vetor com os valores de leitura digital dos sensores
void leituraSensorLinha(){
int i;   
    for(i=5;i<7;i++){
        if(getAD_ANbit(i)<600){
        leitura[i]=1;//leituras que identificam a cor branco    
        } else {
            leitura[i]=0;//leituras que identificam o preto
        }
    }
}

void testeSensorDigital(){
    //AN5
    
    
    if(leitura[5]==1){
        UARTSendString("\nFD:branca\n",MAX_LENGTH_UART);
    } else {
    UARTSendString("\nFD:preto\n",MAX_LENGTH_UART);
    }
    
    //AN6
    if(leitura[6]==1){
        UARTSendString("\nFE:branca\n",MAX_LENGTH_UART);
    } else {
    UARTSendString("\nFE:preto\n",MAX_LENGTH_UART);
    }
    
    UARTSendString("\n----------------\n",MAX_LENGTH_UART);
    
}
#endif	/* CONFIGSENSORLINHA_H */

