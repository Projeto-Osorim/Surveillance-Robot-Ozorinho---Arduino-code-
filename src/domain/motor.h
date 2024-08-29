#ifndef MOTOR_H
#define MOTOR_H

class Motor{
  private:
    int pinoPwm;
    int pinoIngA;
    int pinoIngB;

    int pwm;

  public:
    Motor(int pinoPwm, int pinoIngA, int pinoIngB){
      this->pinoPwm = pinoPwm;
      this->pinoIngA = pinoIngA;
      this->pinoIngB = pinoIngB;

      pinMode(this->pinoPwm, OUTPUT);
      pinMode(this->pinoIngA, OUTPUT);
      pinMode(this->pinoIngB, OUTPUT);
    }

    void setPwm(int novoPwm) {
      this->pwm = novoPwm;
    }

    void rodarHorario(){
      analogWrite(this->pinoPwm,this->pwm);
      digitalWrite(this->pinoIngA, HIGH);
      digitalWrite(this->pinoIngB, LOW);
    }
    
    void rodarAntiHorario(){
      analogWrite(this->pinoPwm,this->pwm);
      digitalWrite(this->pinoIngA, LOW);
      digitalWrite(this->pinoIngB, HIGH);
    }

    void parar(){
      digitalWrite(this->pinoIngA, LOW);
      digitalWrite(this->pinoIngB, LOW);
    }
};

#endif 