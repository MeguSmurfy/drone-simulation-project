
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
 * functionality specific to percentage reports. It follows the 
 * Decorator Design Pattern, allowing dynamic addition of attributes to objects.
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
   * @param dt Delta time.
   */
  virtual std::string Update(double dt);

  /**
  * @brief Displays the Percentage of the object's progress.
  *
  * @return std::string The percent value of the decorated object's 
  * progress
  */
  virtual std::string DisplayPercentageThreshold() = 0;

  /**
  * @brief Returns the ID of the decorated observer
  *
  * @return int The ID of the observer
  */
  virtual int GetId() {return observer->GetId();}
};

#endif
