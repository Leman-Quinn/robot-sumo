#include "Motor.h"

//---------- CONSTRUCTOR ----------//
Motor::Motor(uint8_t rpwm, uint8_t lpwm, bool inverted):
    _rpwm(rpwm),
    _lpwm(lpwm),
    _inverted(inverted){
        
    }

//---------- METHODS ----------//
void Motor::begin(){
    pinMode(_rpwm, OUTPUT);
    pinMode(_lpwm, OUTPUT);
    analogWrite(_rpwm, 0);
    analogWrite(_lpwm, 0);
}

void Motor::forward(int pwm){
    if (!_inverted)
    {
        analogWrite(_rpwm, pwm);
        analogWrite(_lpwm, 0);
    }
    else
    {
        analogWrite(_rpwm, 0);
        analogWrite(_lpwm, pwm);
    }
}

void Motor::backward(int pwm){
    if (!_inverted)
    {
        analogWrite(_rpwm, 0);
        analogWrite(_lpwm, pwm);
    }
    else
    {
        analogWrite(_rpwm, pwm);
        analogWrite(_lpwm, 0);
    }
}

void Motor::brake(){
    analogWrite(_rpwm, 0);
    analogWrite(_lpwm, 0);
}