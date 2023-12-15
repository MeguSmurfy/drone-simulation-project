/**
 * @file DronePercentageDecorator.h
 * @brief Header file for the DronePercentageDecorator class.
 */
#ifndef DRONE_PERCENTAGE_DECORATOR_H_
#define DRONE_PERCENTAGE_DECORATOR_H_

#include "IPercentageDecorator.h"

/**
 * @class DronePercentageDecorator
 * @brief Decorator class for augmenting drone functionality.
 *
 * DronePercentageDecorator is a class that extends the functionality of a drone
 * by decorating it with a perccetange tracker of the distance the drone has 
 * traveled during the current delivery.
 */
class DronePercentageDecorator : public IPercentageDecorator {
 public:
 
  /**
   * @brief Constructs a new DronePercentageDecorator object.
   *
   * Initializes a DronePercentageDecorator instance.
   */
  DronePercentageDecorator();
 
  /**
   * @brief Virtual destructor for DronePercentageDecorator.
   *
   * Allows for polymorphic use of DronePercentageDecorator
   * instances.
   */
  virtual ~DronePercentageDecorator();
 
  /**
   * @brief Updates the state of the decorator.
   *
   * This method is used to update the decorator with the percentage
   * of the route traveled so far.
   *
   * @param dt Time delta for updating the decorator's state.
   */
  void update(double dt);
};

#endif
