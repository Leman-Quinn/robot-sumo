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
    
    Serial.println("+++ Initializing hardware.");
    robot.begin();
}

void loop() {
    robot.updateUltrasonicSensors();

    //---------- LEFT ULTRASONIC TEST ----------//
    float left_uss = robot.getUltrasonic(Robot::LEFT);
    Serial.print("Left ultrasonic dist: ");
    Serial.println(left_uss);

    //---------- FRONT LEFT ULTRASONIC TEST ----------//
    float frontleft_uss = robot.getUltrasonic(Robot::FRONT_LEFT);
    Serial.print("Front left ultrasonic dist: ");
    Serial.println(frontleft_uss);

    //---------- FRONT RIGHT ULTRASONIC TEST ----------//
    float frontright_uss = robot.getUltrasonic(Robot::FRONT_RIGHT);
    Serial.print("Front right ultrasonic dist: ");
    Serial.println(frontright_uss);

    //---------- RIGHT ULTRASONIC TEST ----------//
    float right_uss = robot.getUltrasonic(Robot::RIGHT);
    Serial.print("Right ultrasonic dist: ");
    Serial.println(right_uss);

    delay(100);
}