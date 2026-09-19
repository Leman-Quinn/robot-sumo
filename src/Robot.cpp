#include "config.h"
#include "Robot.h"
#include "Strategies.h"

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
    // Determine where the enemy is
    updateEnemyPosition();

    // Apply the strategy
    Strategies::searchAndAttack(*this); // "*this" is this very robot, that it is incorporated into the strategy 
}

void Robot::act(){
    // Translates action into motor commands
    switch (_action)
    {
        case Action::FORWARD:
            forward(100); // the percentage can change
            break;
        case Action::FORWARD_LEFT:
            forwardLeft(50);
            break;
        case Action::FORWARD_RIGHT:
            forwardRight(50);
            break;
        case Action::BACKWARD:
            backward(100); // the percentage can change
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

//------- (SENSE) INTERNAL HELPERS -------//
void Robot::updateUltrasonicSensors(){
    _ultrasonicDistances[static_cast<int>(UltrasonicPosition::LEFT)] = _leftUltrasonic.readDistance();
    _ultrasonicDistances[static_cast<int>(UltrasonicPosition::FRONT_LEFT)] = _frontLeftUltrasonic.readDistance();
    _ultrasonicDistances[static_cast<int>(UltrasonicPosition::FRONT_RIGHT)] = _frontRightUltrasonic.readDistance();
    _ultrasonicDistances[static_cast<int>(UltrasonicPosition::RIGHT)] = _rightUltrasonic.readDistance();
}

//------- (THINK) INTERNAL HELPERS -------//
void Robot::updateEnemyPosition(){
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
}

//------- (ACT) INTERNAL HELPERS -------//
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


//---------- TESTING/DEBUGGING TOOL ----------//
float Robot::front_deadband() {
    // Deadband & correction filter
    float frontLeftDistance = getUltrasonicDistance(UltrasonicPosition::FRONT_LEFT);
    float frontRightDistance = getUltrasonicDistance(UltrasonicPosition::FRONT_RIGHT);
    float frontDbFactor = frontLeftDistance - frontRightDistance;

    // Serial.begin(9600); --> it is already in setup(), so this one should not be here permanently.
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

    // delay(500); --> it can cause the robot to get stuck for half a second. 
//-------------------------------//
}