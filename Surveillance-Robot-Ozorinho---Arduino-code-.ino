#include <ros.h>
#include <std_msgs/String.h>
#include "src/domain/motor.h"
#include "src/gerencia/gerencia.h"

#define pwm1 9 // Motor Direito
#define ingA1 4 // Motor Direito
#define ingB1 3 // Motor Direito

#define pwm2 8 // Motor Esquerdo
#define ingA2 6 // Motor Esquerdo
#define ingB2 5 // Motor Esquerdo

Motor motorDireito(pwm1, ingA1, ingB1); 
Motor motorEsquerdo(pwm2, ingA2, ingB2);

Gerencia gerencia(motorDireito,motorEsquerdo);

void mensagemRecebida(const std_msgs::String &msg);

int constanciaMov = 1;

ros::NodeHandle nh;
ros::Subscriber <std_msgs::String> sub("/serial_arduino", &mensagemRecebida);

void setup() {
  Serial.begin(57600);
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  nh.spinOnce();
}

void mensagemRecebida(const std_msgs::String &msg) {
  char comando = msg.data[0];

  if(comando=='T'){constanciaMov*=-1;} //ALTERA A CONSTANCIA DO MOVIMENTO DO OZORIN {-1=POR CLICK}/{1=CONSTANTE}

  gerencia.movimentacao(comando, constanciaMov);
}


