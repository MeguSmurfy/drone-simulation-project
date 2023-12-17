/**
 * @file PackageObserver.h
 * @brief Header file for the PackageObserver class.
 */
#ifndef PACKAGE_OBSERVER_H_
#define PACKAGE_OBSERVER_H_

#include "IObserver.h"
#include "Package.h"
#include "Robot.h"

/**
 * @class PackageObserver
 * @brief Observer class for monitoring package state changes.
 *
 * PackageObserver is an implementation of the observer pattern. It is used to
 * track and respond to changes in the state of a Package object. This class
 * extends the IObserver interface, providing specific functionalities for
 * package observation.
 */
class PackageObserver : public IObserver {
 public:
  /**
   * @brief Constructs a PackageObserver object.
   *
   * Initializes a new instance of the PackageObserver class, setting the target
   * Package object to observe.
   *
   * @param package Pointer to the Package object to observe.
   */
  PackageObserver(Package* package);

  /**
   * @brief Destructor for PackageObserver.
   */
  ~PackageObserver();

  /**
   * @brief Updates the observer based on the observed Package's state.
   *
   * Called to update the state of the PackageObserver in response to changes
   * in the observed Package's state.
   *
   * @param dt Time delta for updating observer's state.
   * @return std::string A summary of the current state of the observer.
   */
  std::string Update(double dt);

  /**
   * @brief Retrieves the ID of the observed Package.
   *
   * @return int The ID of the Package being observed.
   */
  int GetId();

 private:
  Package* package;       ///< Pointer to the observed Package.
  std::string name;       ///< Name of the observer.
  std::string ownerName;  ///< Name of the owner of the package.
  bool setForDelivery;  ///< Flag indicating if the package is set for delivery.
  bool delivered;       ///< Flag indicating if the package has been delivered.
  bool setIntialPosition;
  Vector3 initPos;
};

#endif
