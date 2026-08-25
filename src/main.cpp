#include "config.h"
#include "Robot.h"

Robot robot(
    TRI_L, ECHO_L,
    TRI_FL, ECHO_FL,
    TRI_FR, ECHO_FR,
    TRI_R, ECHO_R,
    AIN1, AIN2, 
    BIN1, BIN2
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
}