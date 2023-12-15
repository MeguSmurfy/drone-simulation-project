#ifndef DRONE_OBSERVER_H_
#define DRONE_OBSERVER_H_

#include "IObserver.h"
#include "Drone.h"
#include "Package.h"

class DroneObserver: public IObserver {
 public:
  DroneObserver(Drone* drone);
  ~DroneObserver() {}
  std::string Update(double dt);
  int GetId();
 private:
  Drone* drone;
  std::string name;
  bool gettingToPackage;
  bool gettingToDestination;
  bool pickedUp;
  bool arrived;
  std::string packageName;
};

#endif