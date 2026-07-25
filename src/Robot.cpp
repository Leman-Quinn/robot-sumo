#include "Robot.h"

#include <Arduino.h>

 //---------- CONSTRUCTOR ----------//
Robot::Robot(){

}

//---------- METHODS ----------//
void Robot::begin(){
    _leftUltrasonic.begin();
    _frontLeftUltrasonic.begin();
    _frontRightUltrasonic.begin();
    _rightUltrasonic.begin();
    _driver.begin();
}

void Robot::updateUltrasonic(){
    // all in one or two different arrays??

}