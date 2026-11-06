#include "Driver.h"

//---------- CONSTRUCTOR ----------//
Driver::Driver(uint8_t rpwm_a, uint8_t lpwm_a,
               uint8_t rpwm_b, uint8_t lpwm_b,
               bool inverted_a, bool inverted_b):
               _leftMotor(rpwm_a, lpwm_a, inverted_a),
               _rightMotor(rpwm_b, lpwm_b, inverted_b)
               {
               }

//---------- METHODS ----------//
void Driver::begin(){
    _leftMotor.begin();
    _rightMotor.begin();
}

void Driver::forward(int pwm){
    _leftMotor.forward(pwm);
    _rightMotor.forward(pwm);
}

void Driver::forwardRight(int pwm){
    _leftMotor.forward(pwm);
    _rightMotor.forward(0);
}

void Driver::forwardLeft(int pwm){
    _leftMotor.forward(0);
    _rightMotor.forward(pwm);
}

void Driver::backward(int pwm){
    _leftMotor.backward(pwm);
    _rightMotor.backward(pwm);
}


void Driver::backwardRight(int pwm){
    _leftMotor.backward(pwm);
    _rightMotor.backward(0);
}

void Driver::backwardLeft(int pwm){
    _leftMotor.backward(0);
    _rightMotor.backward(pwm);
}

void Driver::rotateRight(int pwm){
    _leftMotor.forward(pwm);
    _rightMotor.backward(pwm);
}

void Driver::rotateLeft(int pwm){
    _leftMotor.backward(pwm);
    _rightMotor.forward(pwm);
}

void Driver::brake(){
    _leftMotor.brake();
    _rightMotor.brake();
}
