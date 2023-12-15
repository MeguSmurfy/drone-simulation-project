#include "PackageObserver.h"

PackageObserver::PackageObserver(Package* package) {
    this->package = package;
    name = (std::string) package->getDetails()["name"];
    setForDelivery = false;
    delivered = false;
}

std::string PackageObserver::Update(double dt) {
    if (!setForDelivery) {
        setForDelivery = true;
        ownerName = (std::string) package->getOwner()->getDetails()["name"];
        return name + " is set to be delivered to " + ownerName + ".\n";
    } else {
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