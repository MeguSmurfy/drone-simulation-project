#include "IPercentageDecorator.h"

IPercentageDecorator::IPercentageDecorator(IObserver* observer) {
  this->observer = observer;
}

IPercentageDecorator::~IPercentageDecorator() {
  // Delete dynamically allocated variables
  if (strategy) delete strategy;
}