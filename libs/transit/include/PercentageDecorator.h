/**
 * @file PercentageDecorator.h
 * @brief Header file for the PercentageDecorator class.
 */
#ifndef PERCENTAGE_DECORATOR_H_
#define PERCENTAGE_DECORATOR_H_

#include "IPercentageDecorator.h"

/**
 * @class PercentageDecorator
 * @brief Decorator class for augmenting entity functionality.
 *
 * PercentageDecorator is a class that extends the functionality of an entity
 * by decorating it with a percentage tracker of the distance the entity has 
 * traveled during the current delivery.
 */
class PercentageDecorator : public IPercentageDecorator {
 public:
  /**
   * @brief Constructs a new PercentageDecorator object.
   *
   * Initializes a PercentageDecorator instance.
   */
  PercentageDecorator(IObserver* observer);

  std::string DisplayPercentageThreshold(double dt);

 private:
  bool quarter;
  bool half;
  bool threeQuarters;
};

#endif
