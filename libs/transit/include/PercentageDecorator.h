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

  /**
   * @brief Displays the percentage of distance traveled during this delivery.
   *
   * @return std::string Returns 25%, 50%, or 75% progress.
   */
  std::string DisplayPercentageThreshold();

 private:
  bool quarter;
  bool half;
  bool threeQuarters;
};

#endif
