#include "Driver.h"

//---------- CONSTRUCTOR ----------//
Driver::Driver(uint8_t rpwm_a, uint8_t lpwm_a,
               uint8_t rpwm_b, uint8_t lpwm_b):
               _leftMotor(rpwm_a, lpwm_a), _rightMotor(rpwm_b, lpwm_b)
               {
                this->_rpwm_a = rpwm_a;
                this->_lpwm_a = lpwm_a;
                this->_rpwm_b = rpwm_b;
                this->_lpwm_b = lpwm_b;
               }

//---------- METHODS ----------//
void Driver::begin(){
    _leftMotor.begin();
    _rightMotor.begin();
}

void Driver::forward(int pwm_perc){
    _leftMotor.forward();
    _rightMotor.forward();

    int pwm_raw = (pwm_perc*255)/100;
    
    analogWrite(_pwma, pwm_raw);
    analogWrite(_pwmb, pwm_raw);
}

void Driver::forwardRight(int pwm_perc){
    _leftMotor.forward();
    _rightMotor.forward();

    int pwm_raw = (pwm_perc*255)/100; // pwm for the right motor

    analogWrite(_pwma, 255); // the left motor has to have 255 pwm
    analogWrite(_pwmb, pwm_raw); // right motor
}

void Driver::forwardLeft(int pwm_perc){
    _leftMotor.forward();
    _rightMotor.forward();

    int pwm_raw = (pwm_perc*255)/100; // pwm for the left motor

    analogWrite(_pwma, pwm_raw); // left motor
    analogWrite(_pwmb, 255); // the right motor has to have 255 pwm
}

void Driver::backward(int pwm_perc){
    _leftMotor.backward();
    _rightMotor.backward();

    int pwm_raw = (pwm_perc*255)/100;

    analogWrite(_pwma, pwm_raw);
    analogWrite(_pwmb, pwm_raw);
}

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

void Driver::rotateRight(){
    _leftMotor.forward();
    _rightMotor.backward();

    analogWrite(_pwma, 255); // motor left
    analogWrite(_pwmb, 255); // motor right (it needs 255 pwm to go backwards)
}

void Driver::rotateLeft(){
    _leftMotor.backward();
    _rightMotor.forward();

    analogWrite(_pwma, 255); // motor left (it needs 255 pwm to go backwards)
    analogWrite(_pwmb, 255); // motor right
}

void Driver::brake(){
    _leftMotor.brake();
    _rightMotor.brake();
}
