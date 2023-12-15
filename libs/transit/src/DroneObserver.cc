#include "DroneObserver.h"

DroneObserver::DroneObserver(Drone* drone) {
  this->drone = drone;
  name = (std::string) drone->getDetails()["name"];
  gettingToPackage = false;
  pickedUp = false;
  gettingToDestination = false;
  arrived = false;
  packageName = "";
}

std::string DroneObserver::Update(double dt) {
  if (!drone->getAvailability()) {
    if (!pickedUp) {
      if (!gettingToPackage) {
        packageName = (std::string) drone->getPackage()->getDetails()["name"];
        gettingToPackage = true;
        return name + " is going to pick up the package " + packageName + ".\n";
      }
      if (drone->getPackage()->getPosition().dist(drone->getPosition()) < 15) {
        pickedUp = true;
        return name + " has picked up the package " + packageName + ".\n";
      }
    } else {
      if (!gettingToDestination) {
        gettingToDestination = true;
        return name + " is delivering the package " + packageName + ".\n";
      }
      arrived = true;
    }
  } else {
    gettingToPackage = false;
    pickedUp = false;
    gettingToDestination = false;
    if (arrived) {
      arrived = false;
      return name + " has delivered " + packageName + " to the final destination.\n";
    }
    packageName = "";
  }
  return "";
}

int DroneObserver::GetId() {
  return drone->getId();
}