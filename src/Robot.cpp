#include "Robot.h"

//---------- CONSTRUCTOR ----------//
Robot::Robot(
    uint8_t leftTrigger, uint8_t leftEcho,
    uint8_t frontLeftTrigger, uint8_t frontLeftEcho,
    uint8_t frontRightTrigger, uint8_t frontRightEcho,
    uint8_t rightTrigger, uint8_t rightEcho,
    uint8_t pol1, uint8_t pol2, uint8_t pol3, uint8_t pol4
    ):
    _leftUltrasonic(leftTrigger, leftEcho),
    _frontLeftUltrasonic(frontLeftTrigger, frontLeftEcho),
    _frontRightUltrasonic(frontRightTrigger, frontRightEcho),
    _rightUltrasonic(rightTrigger, rightEcho),
    _driver(pol1, pol2, pol3, pol4){

    }
//---------------------------------//

//---------- INTERFACES ----------//
float Robot::getUltrasonicDistance(UltrasonicPosition position){
    return _ultrasonicDistances[static_cast<int>(position)];
}

Robot::EnemyPosition Robot::getEnemyPosition(){
    return _enemyPosition;
}

void Robot::setEnemyPosition(Robot::EnemyPosition enemyPosition){
    _enemyPosition = enemyPosition;
}

Robot::State Robot::getState(){
    return _state;
}

void Robot::setState(Robot::State state){
    _state = state;
}

Robot::Action Robot::getAction(){
    return _action;    
}

void Robot::setAction(Action action){
    _action = action;
}
//--------------------------------//

//---------- METHODS ----------//
void Robot::begin(){
    _leftUltrasonic.begin();
    _frontLeftUltrasonic.begin();
    _frontRightUltrasonic.begin();
    _rightUltrasonic.begin();
    _driver.begin();
}

void Robot::sense(){
    updateUltrasonicSensors();
}

void Robot::think(){
    // first it checks the sensor readings and pinpoints the enemy location
    float left = getUltrasonicDistance(UltrasonicPosition::LEFT);
    float frontleft = getUltrasonicDistance(UltrasonicPosition::FRONT_LEFT);
    float frontright = getUltrasonicDistance(UltrasonicPosition::FRONT_RIGHT);
    float right = getUltrasonicDistance(UltrasonicPosition::RIGHT);

    // then it decides where the enemy must be based on the sensor feed
    if ((left < frontleft) && (left < frontright) && (left < right))
    {
        setEnemyPosition(EnemyPosition::LEFT);
    }
    else if ((right < frontleft) && (right < frontright) && (right < left))
    {
        setEnemyPosition(EnemyPosition::RIGHT);
    }
    else if ((frontleft < left) && (frontright < right))
    {
        setEnemyPosition(EnemyPosition::FRONT);
    }
    else
    {
        setEnemyPosition(EnemyPosition::NONE);
    }

    // lastly it changes the state and action based off of the enemy location
    switch (_enemyPosition)
    {
    case EnemyPosition::NONE:
        _state = State::SEARCH;
        _action = Action::ROTATE_RIGHT;
        break;
    case EnemyPosition::LEFT:
        _state = State::SEARCH;
        _action = Action::ROTATE_LEFT;
        break;
    case EnemyPosition::RIGHT:
        _state = State::SEARCH;
        _action = Action::ROTATE_RIGHT;
        break;
    case EnemyPosition::FRONT:
        _state = State::ATTACK;
        _action = Action::FORWARD;
        break;
    }
}

void Robot::act(){
    // this function reads the current action and sends motor commands
    switch (_action)
    {
    case Action::FORWARD:
        forward();
        break;
    case Action::BRAKE:
        brake();
        break;
    case Action::ROTATE_LEFT:
        rotateLeft();
        break;
    case Action::ROTATE_RIGHT:
        rotateRight();
        break;
    }
}
//-----------------------------//

//------- INTERNAL HELPERS -------//
void Robot::updateUltrasonicSensors(){
    _ultrasonicDistances[static_cast<int>(UltrasonicPosition::LEFT)] = _leftUltrasonic.readDistance();
    _ultrasonicDistances[static_cast<int>(UltrasonicPosition::FRONT_LEFT)] = _frontLeftUltrasonic.readDistance();
    _ultrasonicDistances[static_cast<int>(UltrasonicPosition::FRONT_RIGHT)] = _frontRightUltrasonic.readDistance();
    _ultrasonicDistances[static_cast<int>(UltrasonicPosition::RIGHT)] = _rightUltrasonic.readDistance();
}

void Robot::forward(){
    _driver.forward();
}

void Robot::backward(){
    _driver.backward();
}

void Robot::rotateRight(){
    _driver.rotateRight();
}

void Robot::rotateLeft(){
    _driver.rotateLeft();
}

void Robot::brake(){
    _driver.brake();
}
//-------------------------------//