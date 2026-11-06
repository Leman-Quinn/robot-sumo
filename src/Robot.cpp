#include "config.h"
#include "Robot.h"

//---------- CONSTRUCTOR ----------//
Robot::Robot(
    uint8_t leftTrigger, uint8_t leftEcho,
    uint8_t frontLeftTrigger, uint8_t frontLeftEcho,
    uint8_t frontRightTrigger, uint8_t frontRightEcho,
    uint8_t rightTrigger, uint8_t rightEcho,
    uint8_t rpwm_a, uint8_t lpwm_a,
    uint8_t rpwm_b, uint8_t lpwm_b
    ):
    _leftUltrasonic(leftTrigger, leftEcho),
    _frontLeftUltrasonic(frontLeftTrigger, frontLeftEcho),
    _frontRightUltrasonic(frontRightTrigger, frontRightEcho),
    _rightUltrasonic(rightTrigger, rightEcho),
    _driver(rpwm_a, lpwm_a, rpwm_b, lpwm_b)
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
            forward(255);
            break;
        case Action::FORWARD_LEFT:
            forwardLeft(100);
            break;
        case Action::FORWARD_RIGHT:
            forwardRight(100);
            break;
        case Action::BACKWARD:
            backward(255);
            break;
        case Action::BACKWARD_LEFT:
            backwardLeft(100);
            break;
        case Action::BACKWARD_RIGHT:
            backwardRight(100);
            break;
        case Action::BRAKE:
            brake();
            break;
        case Action::ROTATE_LEFT:
            rotateLeft(255);
            break;
        case Action::ROTATE_RIGHT:
            rotateRight(255);
            break;
        case Action::PATROL:
            simple_patrol();
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

    // 2. Sets flags for potential enemy location based on max distance threshold
    bool targetOnLeft = leftDistance >= 0 && leftDistance < MAX_ENEMY_DISTANCE;
    bool targetOnFrontLeft = frontLeftDistance >= 0 && frontLeftDistance < MAX_ENEMY_DISTANCE;
    bool targetOnFrontRight = frontRightDistance >= 0 && frontRightDistance < MAX_ENEMY_DISTANCE;
    bool targetOnRight = rightDistance >= 0 && rightDistance < MAX_ENEMY_DISTANCE;
    bool targetOnFront = targetOnFrontLeft && targetOnFrontRight;

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
    else
    {
        setEnemyPosition(EnemyPosition::NONE);
    }
}

void Robot::updateState(){
    EnemyPosition currentEnemyPosition = getEnemyPosition();

    switch (currentEnemyPosition)
    {
        case EnemyPosition::FRONT:
            setState(State::ATTACK);
            break;
        case Robot::EnemyPosition::FRONT_RIGHT:
            setState(State::ALIGN);
            break;
        case Robot::EnemyPosition::FRONT_LEFT:
            setState(State::ALIGN);
            break;
        case Robot::EnemyPosition::LEFT:
            setState(State::SEARCH_L);
            break;
        case Robot::EnemyPosition::RIGHT:
            setState(State::SEARCH_R);
            break;
        case Robot::EnemyPosition::NONE:
            setState(State::SEARCH);
            break;
    }
}

void Robot::updateAction(){
    float frontLeftDistance = getUltrasonicDistance(UltrasonicPosition::FRONT_LEFT);
    float frontRightDistance = getUltrasonicDistance(UltrasonicPosition::FRONT_RIGHT);
    float factor = frontLeftDistance - frontRightDistance;

    switch (_state)
    {
        case State::ATTACK:
            setAction(Action::FORWARD);
            break;
        case State::ALIGN:
            if (factor <= -5)
                {
                    // Align to the left
                    setAction(Action::FORWARD_LEFT);
                }
                else if (factor >= 5)
                {
                    // Align to the right
                    setAction(Action::FORWARD_RIGHT);
                }
            break;
        case State::SEARCH_R:
            setAction(Action::ROTATE_RIGHT);
            break;
        case State::SEARCH_L:
            setAction(Action::ROTATE_LEFT);
            break;
        case State::SEARCH:
            setAction(Action::PATROL);
            break;
    }
}

//------- ACT HELPERS -------//
void Robot::forward(int pwm){
    _driver.forward(pwm);
}

void Robot::forwardRight(int pwm){
    _driver.forwardRight(pwm);
}

void Robot::forwardLeft(int pwm){
    _driver.forwardLeft(pwm);
}

void Robot::backward(int pwm){
    _driver.backward(pwm);
}

void Robot::backwardRight(int pwm){
    _driver.backwardRight(pwm);
}

void Robot::backwardLeft(int pwm){
    _driver.backwardLeft(pwm);
}

void Robot::rotateRight(int pwm){
    _driver.rotateRight(pwm);
}

void Robot::rotateLeft(int pwm){
    _driver.rotateLeft(pwm);
}

void Robot::brake(){
    _driver.brake();
}
//-------------------------------//

//--------------- STRATEGY -----------------//
void Robot::simple_patrol(){
    switch (_stratStep)
    {
    case StrategyStep::FORWARD:
        forward(100);

        if (millis() - _stratClock >= 750){
            _stratStep = StrategyStep::ROTATE_RIGHT;
            _stratClock = millis();
        }
        break;
    case StrategyStep::ROTATE_RIGHT:
        rotateRight(100);

        if (millis() - _stratClock >= 500){
            _stratStep = StrategyStep::FORWARD;
            _stratClock = millis();
        }
        break;
    }
}
//---------------------------------------------//

//------- DEBUGGING HELPERS -------//
void Robot::testForward(int pwm){
    _driver.forward(pwm);
    delay(2000);
    _driver.brake();
}

void Robot::testBackward(int pwm){
    _driver.backward(pwm);
    delay(2000);
    _driver.brake();
}

void Robot::testMixedMovements(int pwm){
    _driver.forward(pwm);
    delay(2000);
    _driver.brake();
    delay(1000);

    _driver.backward(pwm);
    delay(2000);
    _driver.brake();
    delay(1000);

    _driver.rotateLeft(pwm);
    delay(2000);
    _driver.brake();
    delay(1000);
    
    _driver.rotateRight(pwm);
    delay(2000);
    _driver.brake();
    delay(1000);
}
//-------------------------------//