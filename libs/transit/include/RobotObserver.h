#ifndef ROBOT_OBSERVER_H_
#define ROBOT_OBSERVER_H_

#include "IObserver.h"
#include "Robot.h"
#include "Package.h"

class RobotObserver: public IObserver {
 public:
  RobotObserver(Robot* robot);
  ~RobotObserver();
  std::string Update(double dt);
  int GetId();
 private:
  Robot* robot;
  std::string name;
  std::string packageName;
  bool received;
};

#endif