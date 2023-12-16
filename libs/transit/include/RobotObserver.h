/**
 * @file RobotObserver.h
 * @brief Header file for the RobotObserver class.
 */
#ifndef ROBOT_OBSERVER_H_
#define ROBOT_OBSERVER_H_

#include "IObserver.h"
#include "Robot.h"
#include "Package.h"

/**
 * @class RobotObserver
 * @brief Observer class for monitoring robot state changes.
 *
 * RobotObserver is a concrete observer pattern for robots.
 * It observes and responds to state changes in a Robot object.
 * This class is an extension of the IObsever interface.
 */
class RobotObserver: public IObserver {
 public:
   /**
   * @brief Constructs a RobotObserver object.
   *
   * Initializes a new instance of the RobotObserver class, associating it with
   * a specific Robot object to observe.
   *
   * @param robot Pointer to the Robot object to observe.
   */
  RobotObserver(Robot* robot);
 
  /**
   * @brief Destructor for RobotObserver.
   */
  ~RobotObserver();
 
  /**
   * @brief Updates the observer based on the observed Robot's state.
   *
   * Called to update the state of the RobotObserver in response to changes
   * in the observed Robot's state.
   *
   * @param dt Time delta for updating observer's state.
   * @return std::string A summary of the current state of the observer.
   */
  std::string Update(double dt);
 
  /**
   * @brief Retrieves the ID of the observed Robot.
   *
   * @return int The ID of the Robot being observed.
   */
  int GetId();
 private:
  Robot* robot;
  std::string name;
  std::string packageName;
  bool received;
};

#endif
