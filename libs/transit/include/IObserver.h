/**
 * @file IObserver.h
 * @brief Header file for the IObserver interface.
 */#ifndef I_OBSERVER_H_
#define I_OBSERVER_H_

#include <string>

/**
 * @class IObserver
 * @brief Interface for the Observer pattern.
 *
 * IObserver is an interface defining the structure for observer classes in this
 * project. It provides the essential functions that all observer
 * classes need to implement to be notified about whatever they are observing.
 */
class IObserver {
 public:
   /**
   * @brief Virtual update method to be implemented by concrete observers.
   *
   * This method is called to update the observer with specifics occuring in
   * the concrete observers.
   *
   * @param dt Time delta or other relevant information needed for the update.
   * @return std::string A summary or status update after processing the update.
   */
  virtual std::string Update(double dt) = 0;
 
   /**
   * @brief Virtual method to get the ID of the observer.
   *
   * This method returns the observer's ID. 
   *
   * @return int The unique ID of the observer.
   */
  virtual int GetId() = 0;
};

#endif
