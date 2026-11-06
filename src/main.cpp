#include "config.h"
#include "Robot.h"

Robot robot(
    OUT_FL, OUT_FR,
    OUT_RL, OUT_RR,
    TRI_L, ECHO_L,
    TRI_FL, ECHO_FL,
    TRI_FR, ECHO_FR,
    TRI_R, ECHO_R,
    RPWM_A, LPWM_A,
    RPWM_B, LPWM_B
);

void setup() { 
    //---------- SERIAL (DEBUG) ----------//
    //Serial.begin(115200);
    robot.begin();
}

void loop() { 
    robot.sense();
    robot.think();
    robot.act();
}