#include "Driver.h"

//---------- CONSTRUCTOR ----------//
Driver::Driver(uint8_t pol1, uint8_t pol2, uint8_t pol3, uint8_t pol4):
_leftMotor(pol1, pol2), _rightMotor(pol3, pol4){
    
}

//---------- METHODS ----------//
void Driver::begin(){
    _leftMotor.begin();
    _rightMotor.begin();
}

void Driver::forward(){
    _leftMotor.forward();
    _rightMotor.forward();
}

void Driver::backward(){
    _leftMotor.backward();
    _rightMotor.backward();
}

void Driver::rotateRight(){
    _leftMotor.forward();
    _rightMotor.backward();
}

void Driver::rotateLeft(){
    _leftMotor.backward();
    _rightMotor.forward();
}

void Driver::brake(){
    _leftMotor.stop();
    _rightMotor.stop();
}