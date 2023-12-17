#include "IPercentageDecorator.h"

IPercentageDecorator::IPercentageDecorator(IObserver* observer) {
  this->observer = observer;
}

IPercentageDecorator::~IPercentageDecorator() {
  // Delete dynamically allocated variables
  if (observer) delete observer;
}

std::string IPercentageDecorator::Update(double dt) {
  std::string message = observer->Update(dt) + DisplayPercentageThreshold();
  return message;
}