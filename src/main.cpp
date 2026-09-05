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

/* void testMethods(){
    static unsigned long timer = 0;

    if(timer <= 1000){ // general timer (until 1000 milliseconds - 1 second)
        robot.backwardLeft(100);
        timer = millis();
    } else if((timer > 1000) && (timer <= 2000)){ // general timer (until 2000 milliseconds - 2 seconds)
        robot.backwardLeft(75);
        timer = millis();
    } else if((timer > 2000) && (timer <= 3000)){ // general timer (until 3000 milliseconds - 3 seconds)
        robot.backwardLeft(50);
        timer = millis();
    } else if((timer > 3000) && (timer <= 4000)){ // general timer (until 4000 milliseconds - 4 seconds)
        robot.backwardLeft(25); 
        timer = millis();
    }
} */

void setup() { 
    //---------- SERIAL (DEBUG) ----------//
    Serial.begin(9600);
    robot.begin();
}

void loop() { 
    // robot.sense();
    // robot.think();
    // robot.act();
    
    // testMethods();
}

