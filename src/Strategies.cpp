#include "Strategies.h"
#include "Robot.h" // here, it is indeed necessary to declare it

namespace Strategies {

    void basic(Robot& robot) {
        
        // Changes the state and action
        switch (robot.getEnemyPosition()) {

            case Robot::EnemyPosition::FRONT:
                robot.setState(Robot::State::ATTACK);
                robot.setAction(Robot::Action::FORWARD);
                break;

            case Robot::EnemyPosition::FRONT_LEFT:
                robot.setState(Robot::State::ALIGN);
                robot.setAction(Robot::Action::ROTATE_LEFT);
                break;

            case Robot::EnemyPosition::FRONT_RIGHT:
                robot.setState(Robot::State::ALIGN);
                robot.setAction(Robot::Action::ROTATE_RIGHT);
                break;

             case Robot::EnemyPosition::LEFT:
                robot.setState(Robot::State::ALIGN);
                robot.setAction(Robot::Action::ROTATE_LEFT);
                break;

            case Robot::EnemyPosition::RIGHT:
                robot.setState(Robot::State::ALIGN);
                robot.setAction(Robot::Action::ROTATE_RIGHT);
                break;

            case Robot::EnemyPosition::NONE:
                robot.setState(Robot::State::SEARCH);
                robot.setAction(Robot::Action::ROTATE_RIGHT);
                break;

            default:
                robot.setState(Robot::State::SEARCH);
                robot.setAction(Robot::Action::BRAKE);
                break;
        }
    }
}
