#include "config.h"
#include "Robot.h"

//---------- CONSTRUCTOR ----------//
Robot::Robot(
    uint8_t leftTrigger, uint8_t leftEcho,
    uint8_t frontLeftTrigger, uint8_t frontLeftEcho,
    uint8_t frontRightTrigger, uint8_t frontRightEcho,
    uint8_t rightTrigger, uint8_t rightEcho,
    uint8_t pol1, uint8_t pol2, uint8_t pwma, 
    uint8_t pol3, uint8_t pol4, uint8_t pwmb
    ):
    _leftUltrasonic(leftTrigger, leftEcho),
    _frontLeftUltrasonic(frontLeftTrigger, frontLeftEcho),
    _frontRightUltrasonic(frontRightTrigger, frontRightEcho),
    _rightUltrasonic(rightTrigger, rightEcho),
    _driver(pol1, pol2, pwma, pol3, pol4, pwmb)
    {
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
    updateEnemyPosition();
    updateState();
    updateAction();
}

void Robot::act(){
    // Translates actions into motor commands
    switch (_action)
    {
        case Action::FORWARD:
            forward(100);
            break;
        case Action::FORWARD_LEFT:
            forwardLeft(50);
            break;
        case Action::FORWARD_RIGHT:
            forwardRight(50);
            break;
        case Action::BACKWARD:
            backward(100);
            break;
         case Action::BACKWARD_LEFT:
            backwardLeft(50);
            break;
        case Action::BACKWARD_RIGHT:
            backwardRight(50);
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

//------- SENSE HELPERS -------//
void Robot::updateUltrasonicSensors(){
    _ultrasonicDistances[static_cast<int>(UltrasonicPosition::LEFT)] = _leftUltrasonic.readDistance();
    delay(80);
    _ultrasonicDistances[static_cast<int>(UltrasonicPosition::FRONT_LEFT)] = _frontLeftUltrasonic.readDistance();
    delay(80);
    _ultrasonicDistances[static_cast<int>(UltrasonicPosition::FRONT_RIGHT)] = _frontRightUltrasonic.readDistance();
    delay(80);
    _ultrasonicDistances[static_cast<int>(UltrasonicPosition::RIGHT)] = _rightUltrasonic.readDistance();
    delay(80);
}

//------- THINK HELPERS -------//
void Robot::updateEnemyPosition(){
    // 1. Fetches ultrasonic readings
    float leftDistance = getUltrasonicDistance(UltrasonicPosition::LEFT);
    float frontLeftDistance = getUltrasonicDistance(UltrasonicPosition::FRONT_LEFT);
    float frontRightDistance = getUltrasonicDistance(UltrasonicPosition::FRONT_RIGHT);
    float rightDistance = getUltrasonicDistance(UltrasonicPosition::RIGHT);
    // 2. Sets flags for max detection
    bool targetOnLeft = leftDistance < MAX_ENEMY_DISTANCE;
    bool targetOnFrontLeft = frontLeftDistance < MAX_ENEMY_DISTANCE;
    bool targetOnFront = (frontLeftDistance < MAX_ENEMY_DISTANCE) && (frontRightDistance < MAX_ENEMY_DISTANCE);
    bool targetOnFrontRight = frontRightDistance < MAX_ENEMY_DISTANCE;
    bool targetOnRight = rightDistance < MAX_ENEMY_DISTANCE;

    // 3. Updates enemy position
    if (targetOnFront)
    {
        setEnemyPosition(EnemyPosition::FRONT);
    }
    else if (targetOnFrontLeft)
    {
        setEnemyPosition(EnemyPosition::FRONT_LEFT);
    }
    else if (targetOnFrontRight)
    {
        setEnemyPosition(EnemyPosition::FRONT_RIGHT);
    }
    else if (targetOnLeft)
    {
        setEnemyPosition(EnemyPosition::LEFT);
    }
    else if (targetOnRight)
    {
        setEnemyPosition(EnemyPosition::RIGHT);
    }
    else{
        setEnemyPosition(EnemyPosition::NONE);
    }
}

void updateState(){
    switch (_enemyPosition)
    {
        case EnemyPosition::FRONT:
            setState(State::ATTACK);
            break;
        case EnemyPosition::FRONT_RIGHT:
            setState(State::ALIGN);
            break;
        case EnemyPosition::FRONT_LEFT:
            setState(State::ALIGN);
            break;
        case EnemyPosition::LEFT:
            setState(State::SEARCH);
            break;
        case EnemyPosition::RIGHT:
            setState(State::SEARCH);
            break;
        case EnemyPosition::NONE:
            setState(State::SEARCH);
            break;
    }
}

void updateAction(){
    float frontLeftDistance = getUltrasonicDistance(UltrasonicPosition::FRONT_LEFT);
    float frontRightDistance = getUltrasonicDistance(UltrasonicPosition::FRONT_RIGHT);
    float factor = frontLeftDistance - frontRightDistance;
    
    switch (_state)
    {
        case State::ATTACK:
            setAction(Action::FORWARD);
            break;
        case State::ALIGN:
            if (factor < -5)
                {
                    // Align left
                    setAction(Action::FORWARD_LEFT);
                }
                else if (factor > 5)
                {
                    // Align right
                    setAction(Action::FORWARD_RIGHT);
                }
            break;
        case State::SEARCH:
            // To be replaced with CUSTOM STRATEGIES
            setAction(Action::ROTATE_LEFT);
            break;
    }
}

//------- ACT HELPERS -------//
void Robot::forward(int pwm_percentage){
    _driver.forward(pwm_percentage);
}

void Robot::forwardRight(int pwm_percentage){
    _driver.forwardRight(pwm_percentage);
}

void Robot::forwardLeft(int pwm_percentage){
    _driver.forwardLeft(pwm_percentage);
}

void Robot::backward(int pwm_percentage){
    _driver.backward(pwm_percentage);
}

void Robot::backwardRight(int pwm_percentage){
    _driver.backwardRight(pwm_percentage);
}

void Robot::backwardLeft(int pwm_percentage){
    _driver.backwardLeft(pwm_percentage);
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
