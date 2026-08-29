#ifndef ROBOT_H
#define ROBOT_H

#include "UltrasonicSensor.h"
#include "Driver.h"

class Robot {
    public:
        //---------- CONSTRUCTOR ----------//
        Robot(
            uint8_t leftTrigger, uint8_t leftEcho,
            uint8_t frontLeftTrigger, uint8_t frontLeftEcho,
            uint8_t frontRightTrigger, uint8_t frontRightEcho,
            uint8_t rightTrigger, uint8_t rightEcho,
            uint8_t pol1, uint8_t pol2, uint8_t pwma,
            uint8_t pol3, uint8_t pol4, uint8_t pwmb
        );
        //---------------------------------//
        
        //---------- INTERFACES ----------//
        enum class UltrasonicPosition {LEFT, FRONT_LEFT, FRONT_RIGHT, RIGHT, COUNT};
        float getUltrasonicDistance(UltrasonicPosition position);
        
        enum class EnemyPosition{NONE, LEFT, FRONT_LEFT, FRONT, FRONT_RIGHT, RIGHT, COUNT};
        EnemyPosition getEnemyPosition();
        void setEnemyPosition(EnemyPosition enemyPosition);
        
        enum class State{SEARCH, ALIGN, ATTACK, EVADE_ENEMY, EVADE_LINE, COUNT};
        State getState();
        void setState(State state);

        enum class Action{FORWARD, BACKWARD, BRAKE, ROTATE_LEFT, ROTATE_RIGHT};
        Action getAction();
        void setAction(Action action);
        //-------------------------------//

        //---------- METHODS ----------//
        void begin();
        void sense();
        void think();
        void act();
        //-----------------------------//

        //-------- FOR TESTING --------//
        void forward(int pwm_perc){
            this->forward(pwm_perc);
        }
        void forwardRight(int pwm_perc){
            this->forwardRight(pwm_perc);
        }
        void forwardLeft(int pwm_perc){
            this->forwardLeft(pwm_perc);
        }
        void backward(int pwm_perc){
            this->backward(pwm_perc);
        }
        void backwardRight(int pwm_perc){
            this->backwardRight(pwm_perc);
        }
        void backwardLeft(int pwm_perc){
            this->backwardLeft(pwm_perc);
        }
        void rotateRight(){
            this->rotateRight();
        }
        void rotateLeft(){
            this->rotateLeft();
        }
        void brake(){
            this->brake();
        }
    private:
        //---------- INTERNAL PROPERTIES ----------//
        float _ultrasonicDistances[static_cast<int>(UltrasonicPosition::COUNT)];
        EnemyPosition _enemyPosition = EnemyPosition::NONE;
        State _state = State::SEARCH;
        Action _action = Action::BRAKE;
        UltrasonicSensor _leftUltrasonic;
        UltrasonicSensor _frontLeftUltrasonic;
        UltrasonicSensor _frontRightUltrasonic;
        UltrasonicSensor _rightUltrasonic;
        Driver _driver;
        //-----------------------------------------//
        
        //---------- (SENSE) INTERNAL HELPERS ----------//
        void updateUltrasonicSensors();
        //----------------------------------------------//

        //---------- (THINK) INTERNAL HELPERS ----------//
        
        //----------------------------------------------//

        //---------- (ACT) INTERNAL HELPERS ----------//
        void forward(int pwm_percentage);
        void forwardRight(int pwm_percentage);
        void forwardLeft(int pwm_percentage);
        void backward(int pwm_percentage);
        void backwardRight(int pwm_percentage);
        void backwardLeft(int pwm_percentage);
        void rotateRight();
        void rotateLeft();
        void brake();
        //--------------------------------------------//

        //---------- DEBUGGING ----------//
        float front_deadband();
};

#endif