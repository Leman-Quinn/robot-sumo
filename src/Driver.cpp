#include "Driver.h"

//---------- CONSTRUCTOR ----------//
Driver::Driver(uint8_t pol1, uint8_t pol2, uint8_t pwma, uint8_t pol3, uint8_t pol4, uint8_t pwmb):
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

void Driver::forward(int perc){

}

// WITH PERCENTAGE CONVERSION
void Driver::forward(int perc){
    _leftMotor.forward();
    _rightMotor.forward();
    int conversion = (perc/100)*255;
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
    _leftMotor.brake();
    _rightMotor.brake();
}
