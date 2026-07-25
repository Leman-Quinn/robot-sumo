#include "config.h"
#include "Driver.h"

//---------- CONSTRUCTOR ----------//
Driver::Driver(uint8_t pol1, uint8_t pol2, uint8_t pol3, uint8_t pol4) : _leftMotor(pol1, pol2), _rightMotor(pol3, pol4){
    
}

//---------- GENERAL METHODS ----------//
void Driver::Forward(){
    _leftMotor.Forward();
    _rightMotor.Forward();
}

void Driver::Backward(){
    _leftMotor.Backward();
    _rightMotor.Backward();
}

void Driver::TurnRight(){
    _leftMotor.Forward();
    _rightMotor.Backward();
}

void Driver::TurnLeft(){
    _leftMotor.Backward();
    _rightMotor.Forward();
}

void Driver::Brake(){
    _leftMotor.Stop();
    _rightMotor.Stop();
}