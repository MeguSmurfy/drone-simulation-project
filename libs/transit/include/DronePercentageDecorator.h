#ifndef DRONE_PERCENTAGE_DECORATOR_H_
#define DRONE_PERCENTAGE_DECORATOR_H_

#include "IPercentageDecorator.h"

class DronePercentageDecorator : public IPercentageDecorator {
 public:
  DronePercentageDecorator();
  virtual ~DronePercentageDecorator();
  void update(double dt);
};

#endif