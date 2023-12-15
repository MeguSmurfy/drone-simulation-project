#ifndef PACKAGE_OBSERVER_H_
#define PACKAGE_OBSERVER_H_

#include "IObserver.h"
#include "Package.h"
#include "Robot.h"

class PackageObserver: public IObserver {
 public:
  PackageObserver(Package* package);
  ~PackageObserver() {}
  std::string Update(double dt);
  int GetId();
 private:
  Package* package;
  std::string name;
  std::string ownerName;
  bool setForDelivery;
  bool delivered;
};

#endif