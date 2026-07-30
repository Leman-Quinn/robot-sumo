#include "Robot.h"

 //---------- CONSTRUCTOR ----------//
Robot::Robot(uint8_t leftTrigger, uint8_t leftEcho,
            uint8_t frontLeftTrigger, uint8_t frontLeftEcho,
            uint8_t frontRightTrigger, uint8_t frontRightEcho,
            uint8_t rightTrigger, uint8_t rightEcho,
            uint8_t pol1, uint8_t pol2, uint8_t pol3, uint8_t pol4):
            _leftUltrasonic(leftTrigger, leftEcho),
            _frontLeftUltrasonic(frontLeftTrigger, frontLeftEcho),
            _frontRightUltrasonic(frontRightTrigger, frontRightEcho),
            _rightUltrasonic(rightTrigger, rightEcho),
            _driver(pol1, pol2, pol3, pol4){

            }

//---------- METHODS ----------//
void Robot::begin(){
    _leftUltrasonic.begin();
    _frontLeftUltrasonic.begin();
    _frontRightUltrasonic.begin();
    _rightUltrasonic.begin();
    _driver.begin();
}

void Robot::updateUltrasonicSensors(){
    _ultrasonicDistances[LEFT] = _leftUltrasonic.readDistance();
    _ultrasonicDistances[FRONT_LEFT] = _frontLeftUltrasonic.readDistance();
    _ultrasonicDistances[FRONT_RIGHT] = _frontRightUltrasonic.readDistance();
    _ultrasonicDistances[RIGHT] = _rightUltrasonic.readDistance();
}

float Robot::getUltrasonic(UltrasonicPositions position){
    return _ultrasonicDistances[position];
}