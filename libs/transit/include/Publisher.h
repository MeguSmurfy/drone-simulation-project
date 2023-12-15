#ifndef PUBLISHER_H_
#define PUBLISHER_H_

#include "IObserver.h"
#include <vector>

class Publisher {
 public:
  Publisher();
  ~Publisher();
  void AddObserver(IObserver* observer);
  void RemoveObserver(IObserver* observer);
  std::vector<std::string> NotifyObserver(double dt);
  void Attach(int id);
  void Detach();
  int getObserverCount();
 private:
  int attachedObserver;
  std::vector<IObserver*> observers;
};

#endif