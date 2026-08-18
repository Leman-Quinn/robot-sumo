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
    _driver(pol1, pol2, pwma, pol3, pol4, pwmb){

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
    // 1. Checks raw sensor readings
    float leftDistance = getUltrasonicDistance(UltrasonicPosition::LEFT);
    float frontLeftDistance = getUltrasonicDistance(UltrasonicPosition::FRONT_LEFT);
    float frontRightDistance = getUltrasonicDistance(UltrasonicPosition::FRONT_RIGHT);
    float rightDistance = getUltrasonicDistance(UltrasonicPosition::RIGHT);

    // 2. Distance threshold filter
    bool targetOnLeft = leftDistance < MAX_ENEMY_DISTANCE;
    bool targetOnFrontLeft = frontLeftDistance < MAX_ENEMY_DISTANCE;
    bool targetOnFront = (frontLeftDistance < MAX_ENEMY_DISTANCE) && (frontRightDistance < MAX_ENEMY_DISTANCE);
    bool targetOnFrontRight = frontRightDistance < MAX_ENEMY_DISTANCE;
    bool targetOnRight = rightDistance < MAX_ENEMY_DISTANCE;

    front_deadband();

    // 3. Registers enemy position
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

    // 4. Changes the state and action
    switch (_enemyPosition)
    {
        case EnemyPosition::FRONT:
            _state = State::ATTACK;
            _action = Action::FORWARD;
            break;
        case EnemyPosition::FRONT_LEFT:
            _state = State::ATTACK;
            _action = Action::FORWARD;
            break;
        case EnemyPosition::FRONT_RIGHT:
            _state = State::ATTACK;
            _action = Action::FORWARD;
            break;   
        case EnemyPosition::LEFT:
            _state = State::ALIGN;
            _action = Action::ROTATE_LEFT;
            break;
        case EnemyPosition::RIGHT:
            _state = State::ALIGN;
            _action = Action::ROTATE_RIGHT;
            break;
        case EnemyPosition::NONE:
            _state = State::SEARCH;
            _action = Action::BRAKE;
            break;
        default:
            _state = State::SEARCH;
            _action = Action::BRAKE;
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
        case Action::BACKWARD:
            backward();
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

void Robot::forward(int pwm_percentage){
    _driver.forward(pwm_percentage);
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


//---------- DEBUGGING ----------//
float Robot::front_deadband(){
    // Deadband & correction filter
    float frontLeftDistance = getUltrasonicDistance(UltrasonicPosition::FRONT_LEFT);
    float frontRightDistance = getUltrasonicDistance(UltrasonicPosition::FRONT_RIGHT);
    float frontDbFactor = frontLeftDistance - frontRightDistance;

    Serial.begin(9600);
    Serial.print("FL: ");
    Serial.print(frontLeftDistance);
    Serial.print(" | ");
    Serial.print("FR: ");
    Serial.print(frontRightDistance);
    Serial.print(" | ");
    Serial.print("DIFF: ");
    Serial.print(frontDbFactor);
    Serial.print(" | ");
    
    if ((frontDbFactor >= -5) && (frontDbFactor <= 5)) 
    {
        Serial.println("NO ALIGNMENT");
    }
    else if (frontDbFactor < -5)
    {
        Serial.println("STEER LEFT");
    }
    else if (frontDbFactor > 5)
    {
        Serial.println("STEER RIGHT");
    }

    delay(500);
//-------------------------------//
}