#ifndef I_PERCENTAGE_DECORATOR_H_
#define I_PERCENTAGE_DECORATOR_H_

#include "IObserver.h"

class IPercentageDecorator : public IObserver {
 protected:
  IObserver* observer;
 public:
  IPercentageDecorator(IObserver* observer);
  virtual ~IPercentageDecorator();
  virtual void update(double dt);
};

#endif