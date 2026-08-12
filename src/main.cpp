#include "config.h"
#include "Robot.h"

Robot robot(
    TRI_L, ECHO_L,
    TRI_FL, ECHO_FL,
    TRI_FR, ECHO_FR,
    TRI_R, ECHO_R,
    AIN1, AIN2, BIN1, BIN2
);

void setup() { 
    //---------- SERIAL (DEBUG) ----------//
    Serial.begin(9600);
    robot.begin();
}

void loop() { 
    robot.sense();
    robot.think();
    robot.act();
    
    /*
    //---------- INTEGRAL BEHAVIOUR TEST ----------//
    robot.updateUltrasonicSensors();
    
    float left_uss = robot.getUltrasonic(Robot::LEFT);
    float frontleft_uss = robot.getUltrasonic(Robot::FRONT_LEFT);
    float frontright_uss = robot.getUltrasonic(Robot::FRONT_RIGHT);
    float right_uss = robot.getUltrasonic(Robot::RIGHT);
    
    if (frontleft_uss <= 10.0 || frontright_uss <= 10.0)
    {
        robot.forward();
        delay(100);
    }
    else if (frontleft_uss > 10.0 && frontright_uss > 10.0)
    {
        robot.rotateRight();
        delay(250);
    }          
    //---------- MOTOR DRIVER TESTS ----------//
    Serial.println("Moving");
    robot.forward();
    delay(500);

    Serial.println("Stopping ");
    robot.stop();
    delay(500);

    //---------- ULTRASONIC TESTS ----------//
    robot.updateUltrasonicSensors();
    
    // LEFT ULTRASONIC TEST
    float left_uss = robot.getUltrasonic(Robot::UltrasonicPositions::LEFT);
    Serial.print("Left ultrasonic dist: ");
    Serial.println(left_uss);
    
    // FRONT LEFT ULTRASONIC TEST
    float frontleft_uss = robot.getUltrasonic(Robot::UltrasonicPositions::FRONT_LEFT);
    Serial.print("Front left ultrasonic dist: ");
    Serial.println(frontleft_uss);
    
    // FRONT RIGHT ULTRASONIC TEST
    float frontright_uss = robot.getUltrasonic(Robot::UltrasonicPositions::FRONT_RIGHT);
    Serial.print("Front right ultrasonic dist: ");
    Serial.println(frontright_uss);

    // RIGHT ULTRASONIC TEST
    float right_uss = robot.getUltrasonic(Robot::UltrasonicPositions::RIGHT);
    Serial.print("Right ultrasonic dist: ");
    Serial.println(right_uss);
    
    delay(100);
    */
}