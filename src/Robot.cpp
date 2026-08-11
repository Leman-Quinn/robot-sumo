#include "config.h"
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
    // 1. Checks the raw sensor readings
    float leftDistance = getUltrasonicDistance(UltrasonicPosition::LEFT);
    float frontleftDistance = getUltrasonicDistance(UltrasonicPosition::FRONT_LEFT);
    float frontrightDistance = getUltrasonicDistance(UltrasonicPosition::FRONT_RIGHT);
    float rightDistance = getUltrasonicDistance(UltrasonicPosition::RIGHT);

    // 2. Filters the readings to gauge potential enemy direction
    bool targetOnLeft = leftDistance < MAX_ENEMY_DISTANCE;
    bool targetOnFront = (frontleftDistance < MAX_ENEMY_DISTANCE) && (frontrightDistance < MAX_ENEMY_DISTANCE);
    bool targetOnRight = rightDistance < MAX_ENEMY_DISTANCE;

    // 3. Saves enemy position
    if (targetOnLeft &&
        !targetOnFront &&
        !targetOnRight)
    {
        setEnemyPosition(EnemyPosition::LEFT);
    }
    else if (!targetOnLeft &&
            !targetOnFront &&
            targetOnRight)
    {
        setEnemyPosition(EnemyPosition::RIGHT);
    }
    else if (!targetOnLeft &&
            targetOnFront &&
            !targetOnRight)
    {
        setEnemyPosition(EnemyPosition::FRONT);
    }
    else
    {
        setEnemyPosition(EnemyPosition::NONE);
    }

    // 4. Changes the state and action
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
    // Translates action into motor commands
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