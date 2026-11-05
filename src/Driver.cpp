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

/*
void Driver::forwardRight(int pwm){
    _leftMotor.forward();
    _rightMotor.forward();
}

void Driver::forwardLeft(int pwm_perc){
    _leftMotor.forward();
    _rightMotor.forward();

    int pwm_raw = (pwm_perc*255)/100; // pwm for the left motor

    analogWrite(_pwma, pwm_raw); // left motor
    analogWrite(_pwmb, 255); // the right motor has to have 255 pwm
}
*/
void Driver::backward(int pwm){
    _leftMotor.backward(pwm);
    _rightMotor.backward(pwm);
}
/*
void Driver::backwardRight(int pwm_perc){
    _leftMotor.backward();
    _rightMotor.backward();

    int pwm_raw = (pwm_perc*255)/100; // pwm for the right motor

    analogWrite(_pwma, 255); // the left motor has to have 255 pwm
    analogWrite(_pwmb, pwm_raw); // right motor
}

void Driver::backwardLeft(int pwm_perc){
    _leftMotor.backward();
    _rightMotor.backward();

    int pwm_raw = (pwm_perc*255)/100; // pwm for the left motor

    analogWrite(_pwma, pwm_raw); // left motor
    analogWrite(_pwmb, 255); // the right motor has to have 255 pwm
}
*/
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
