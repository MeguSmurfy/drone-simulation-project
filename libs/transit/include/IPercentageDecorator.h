
/**
 * @file IPercentageDecorator.h
 * @brief Header file for the IPercentageDecorator interface.
 */
#ifndef I_PERCENTAGE_DECORATOR_H_
#define I_PERCENTAGE_DECORATOR_H_

#include "IObserver.h"

/**
 * @class IPercentageDecorator
 * @brief Interface for a decorator class that extends IObserver functionality.
 *
 * IPercentageDecorator is an interface that extends the IObserver interface, adding 
 * functionality specific to percentage calculations and reporting. It follows the 
 * Decorator Design Pattern, allowing dynamic addition of responsibilities to objects.
 */
class IPercentageDecorator : public IObserver {
 protected:
  IObserver* observer; ///< Pointer to the IObserver object being decorated.
 public:
   /**
   * @brief Constructs an IPercentageDecorator object.
   *
   * Initializes an IPercentageDecorator with a reference to an IObserver object,
   * decorating it with additional functionality.
   *
   * @param observer Pointer to the IObserver object to be decorated.
   */
  IPercentageDecorator(IObserver* observer);
 
   /**
   * @brief Virtual destructor for IPercentageDecorator.
   *
   * Ensures proper cleanup of resources.
   */
  virtual ~IPercentageDecorator();
 
  /**
   * @brief Virtual update method to be implemented by concrete decorators.
   *
   * This method should be overridden to provide specific update 
   * functions in decorators that use this interface.
   *
   * @param dt Relevant data for the update process (specific to concrete Decorator).
   */
  virtual void update(double dt);
};

#endif
