/**
 * @file Publisher.h
 * @brief Header file for the Publisher class, implementing the Publisher part
 * of the Observer pattern.
 */
#ifndef PUBLISHER_H_
#define PUBLISHER_H_

#include <vector>

#include "IObserver.h"

/**
 * @class Publisher
 * @brief Class responsible for managing observers in the Observer pattern.
 *
 * The Publisher class handles the addition, removal, and notification of
 * observers. It maintains a list of observers and provides methods to add or
 * remove observers. Additionally, it includes functionality to notify all
 * registered observers about changes.
 */
class Publisher {
 public:
  /**
   * @brief Constructor for the Publisher class.
   *
   * Initializes a new Publisher instance, setting up for observer management.
   */
  Publisher();

  /**
   * @brief Destructor for the Publisher class.
   *
   * Cleans up resources used by the Publisher, detaching all observers.
   */
  ~Publisher();

  /**
   * @brief Adds an observer to the Publisher.
   *
   * Adds an observer to the Publisher, allowing it to receive notifications.
   *
   * @param observer Pointer to the IObserver to be added.
   */
  void AddObserver(IObserver* observer);

  /**
   * @brief Removes an observer from the Publisher.
   *
   * Removes an observer from the Publisher, stopping it from receiving further
   * notifications.
   *
   * @param observer Pointer to the IObserver to be removed.
   */
  void RemoveObserver(IObserver* observer);

  /**
   * @brief Notifies all registered observers of a change.
   *
   * Triggers the update method on all registered observers, informing them of a
   * change.
   *
   * @param dt Relevant data for the notification.
   * @return std::vector<std::string> Update responses from the observers.
   */
  std::vector<std::string> NotifyObserver(double dt);

  /**
   * @brief Attaches the Publisher to a specific observer.
   *
   * Designates a specific observer by its ID as the main recipient of
   * notifications.
   *
   * @param id The unique identifier of the observer to attach to.
   */
  void Attach(int id);

  /**
   * @brief Detaches the Publisher from its currently attached observer.
   *
   * Removes the current primary observer attachment, if any.
   */
  void Detach();

 private:
  int attachedObserver;
  std::vector<IObserver*> observers;
};

#endif
