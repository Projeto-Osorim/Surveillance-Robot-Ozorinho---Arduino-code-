#ifndef GERENCIA_H
#define GERENCIA_H

#include "../domain/motor.h"

class Gerencia{
    private:
        Motor motorDireito;
        Motor motorEsquerdo;
        
        int pwmFrente = 200;
        int pwmTras = 200;
        int pwmEsquerda = 200;
        int pwmDireita = 200;

        void andarFrente(){
            this->motorDireito.setPwm(this->pwmFrente);
            this->motorEsquerdo.setPwm(this->pwmFrente);

            this->motorDireito.rodarHorario();
            this->motorEsquerdo.rodarAntiHorario();
        }

        void andarTras(){
            this->motorDireito.setPwm(this->pwmTras);
            this->motorEsquerdo.setPwm(this->pwmTras);

            this->motorDireito.rodarAntiHorario();
            this->motorEsquerdo.rodarHorario();
        }

        void virarEsquerda(){
            this->motorDireito.setPwm(this->pwmEsquerda);
            this->motorEsquerdo.setPwm(this->pwmEsquerda);

            this->motorEsquerdo.rodarAntiHorario();
            this->motorDireito.rodarAntiHorario();
        }

        void virarDireita(){
            this->motorDireito.setPwm(this->pwmDireita);
            this->motorEsquerdo.setPwm(this->pwmDireita);

            this->motorDireito.rodarHorario();
            this->motorEsquerdo.rodarHorario();

        }

        void parar(){
            this->motorDireito.parar();
            this->motorEsquerdo.parar();
        }

    public:
        Gerencia(Motor mD, Motor mE) : motorDireito(mD), motorEsquerdo(mE) {}

        void movimentacao(char direcao, int constMovimentacao){
            if(constMovimentacao==-1){ //MOVEMENTACAO POR CLICK
                switch (direcao) {
                    case 'W':
                        //SEGUIR EM FRENTE
                        this->andarFrente(); 
                        break;
                    case 'A':
                        //ESQUERDA 
                        this->virarEsquerda(); 
                        break;
                    case 'S':
                        //SEGUIR PARA TRAS
                        this->andarTras(); 
                        break;
                    case 'D':
                        //DIREITA 
                        this->virarDireita(); 
                        break;
                    default:
                        //PARAR
                        this->parar(); 
                        break;
                }
            }else{ //MOVIMENTACAO CONSTANTE
                switch (direcao) {
                    case 'W':
                        //SEGUIR EM FRENTE
                        this->andarFrente(); 
                        break;
                    case 'A':
                        //ESQUERDA 
                        this->virarEsquerda(); 
                        break;
                    case 'S':
                        //SEGUIR PARA TRAS
                        this->andarTras(); 
                        break;
                    case 'D':
                        //DIREITA 
                        this->virarDireita(); 
                        break;
                    case 'P':
                        //PARAR
                        this->parar(); 
                        break;
                }
            }
        }
};

#endif
