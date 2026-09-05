#include "config.h"
#include "Robot.h"

Robot robot(
    TRI_L, ECHO_L,
    TRI_FL, ECHO_FL,
    TRI_FR, ECHO_FR,
    TRI_R, ECHO_R,
    AIN1, AIN2, PWMA, 
    BIN1, BIN2, PWMB
);

void setup() { 
    //---------- SERIAL (DEBUG) ----------//
    Serial.begin(9600);
    robot.begin();
}

void loop() { 
    // robot.sense();
    // robot.think();
    // robot.act();
    
    static unsigned long timer = 0;

    if((millis() - timer) <= 1000){ // until 1000 milliseconds (1 second)
        robot.forward(100);
        timer = millis();
    } 

    if((millis() - timer) <= 1000){ // until 1000 milliseconds (1 second)
        robot.forwardRight(50);
        timer = millis();
    } 

    if((millis() - timer) <= 1000){ // until 1000 milliseconds (1 second)
        robot.forwardLeft(50);
        timer = millis();
    } 

    if((millis() - timer) <= 1000){ // until 1000 milliseconds (1 second)
        robot.backward(100);
        timer = millis();
    } 

    if((millis() - timer) <= 1000){ // until 1000 milliseconds (1 second)
        robot.backwardRight(50);
        timer = millis();
    } 

    if((millis() - timer) <= 1000){ // until 1000 milliseconds (1 second)
        robot.backwardLeft(50);
        timer = millis();
    } 

    if((millis() - timer) <= 1000){ // until 1000 milliseconds (1 second)
        robot.rotateRight();
        timer = millis();
    } 

    if((millis() - timer) <= 1000){ // until 1000 milliseconds (1 second)
        robot.rotateLeft();
        timer = millis();
    } 

    if((millis() - timer) <= 1000){ // until 1000 milliseconds (1 second)
        robot.brake();
        timer = millis();
    } 

    // continue testing with the public test methods of the Robot class.
}