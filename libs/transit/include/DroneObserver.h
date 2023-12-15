/**
 * @file DroneObserver.h
 * @brief Header file for the DroneObserver class.
 */
#ifndef DRONE_OBSERVER_H_
#define DRONE_OBSERVER_H_

#include "IObserver.h"
#include "Drone.h"
#include "Package.h"

/**
 * @class DroneObserver
 * @brief Observer class for monitoring drone state changes.
 *
 * DroneObserver implements the observer pattern and is used to track the state
 * and behavior of a Drone object. It updates its state based on the changes in the
 * observed Drone.
 */
class DroneObserver: public IObserver {
 public:
   /**
   * @brief Constructs a DroneObserver object.
   * 
   * Initializes a new instance of the DroneObserver class, setting the target
   * Drone object to observe.
   *
   * @param drone Pointer to the Drone object to observe.
   */
  DroneObserver(Drone* drone);
 
  /**
   * @brief Destructor for DroneObserver.
   */
  ~DroneObserver() {}
 
  /**
   * @brief Updates the observer based on the observed Drone's state.
   * 
   * Called to update the state of the DroneObserver in response to changes
   * in the observed Drone's state.
   *
   * @param dt Time delta for updating observer's state.
   * @return std::string A summary of the current state of the observer.
   */
  std::string Update(double dt);
 
  /**
   * @brief Retrieves the ID of the observed Drone.
   * 
   * @return int The ID of the Drone being observed.
   */
  int GetId();
 private:
  Drone* drone;
  std::string name;
  bool gettingToPackage;
  bool gettingToDestination;
  bool pickedUp;
  bool arrived;
  std::string packageName;
};

#endif
