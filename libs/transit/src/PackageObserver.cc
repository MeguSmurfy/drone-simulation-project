#include "PackageObserver.h"

PackageObserver::PackageObserver(Package* package) {
    this->package = package;
    name = (std::string) package->getDetails()["name"];
    setForDelivery = false;
    delivered = false;
    type = "Package";
    setIntialPosition = false;
    initPos = Vector3();
}

PackageObserver::~PackageObserver() {
    if (package) delete package;
}

std::string PackageObserver::Update(double dt) {
    if (!setForDelivery) {
        setForDelivery = true;
        ownerName = (std::string) package->getOwner()->getDetails()["name"];
        if (!setIntialPosition) {
            initPos = package->getPosition();
            setIntialPosition = true;
        }
        return name + " is set to be delivered to " + ownerName + ".\n";
    } else {
        progress = (package->getPosition().dist(initPos))/(package->getDestination().dist(initPos));
        if (package->getOwner()->getPackage() && !delivered) {
            delivered = true;
            return name + " has been delivered to " + ownerName + ".\n";
        }
    }
    return "";
}

int PackageObserver::GetId() {
  return package->getId();
}