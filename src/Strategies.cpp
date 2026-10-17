#include "Strategies.h"
#include "Robot.h" // here, it is indeed necessary to declare it

Strategy::Strategy(Robot& robot) : _robot(robot)
{

}

void Strategy::searchAndAttack(){
    switch (_robot.getEnemyPosition()) {
        case Robot::EnemyPosition::FRONT:
            _robot.setState(Robot::State::ATTACK);
            _robot.setAction(Robot::Action::FORWARD);
            break;
        case Robot::EnemyPosition::FRONT_LEFT:
            _robot.setState(Robot::State::ATTACK);
            _robot.setAction(Robot::Action::FORWARD_LEFT);
            break;
        case Robot::EnemyPosition::FRONT_RIGHT:
            _robot.setState(Robot::State::ATTACK);
            _robot.setAction(Robot::Action::FORWARD_RIGHT);
            break;
            case Robot::EnemyPosition::LEFT:
            _robot.setState(Robot::State::ALIGN);
            _robot.setAction(Robot::Action::ROTATE_LEFT);
            break;
        case Robot::EnemyPosition::RIGHT:
            _robot.setState(Robot::State::ALIGN);
            _robot.setAction(Robot::Action::ROTATE_RIGHT);
            break;
        default:
            _robot.setState(Robot::State::SEARCH);
            _robot.setAction(Robot::Action::ROTATE_RIGHT);
            break;
    }
}