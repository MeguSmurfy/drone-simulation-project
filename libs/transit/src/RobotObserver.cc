#include "RobotObserver.h"

RobotObserver::RobotObserver(Robot* robot) {
    this->robot = robot;
    name = (std::string) robot->getDetails()["name"];
    received = false;
}

std::string RobotObserver::Update(double dt) {
    if (robot->getPackage() && !received) {
        received = true;
        packageName = (std::string) robot->getPackage()->getDetails()["name"];
        return name + " has successfully received the package " + packageName + ".\n";
    }
    return "";
}

int RobotObserver::GetId() {
  return robot->getId();
}