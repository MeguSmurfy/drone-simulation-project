#include "Publisher.h"
#include <iostream>

Publisher::Publisher() {
  attachedObserver = -1;
}

Publisher::~Publisher() {
  for (int i = 0; i < observers.size(); i++) {
    delete observers.at(i);
  }
}

void Publisher::AddObserver(IObserver* observer) {
  observers.push_back(observer);
}

void Publisher::RemoveObserver(IObserver* observer) {
  for (int i = 0; i < observers.size(); i++) {
    if (observer == observers.at(i)) {
      observers.erase(observers.begin() + i);
    }
  }
}

std::vector<std::string> Publisher::NotifyObserver(double dt) {
  std::vector<std::string> result;
  if (attachedObserver == -1) {
    for (int i = 0; i < observers.size(); i++) {
      result.push_back(observers.at(i)->Update(dt));
    }
  } else {
    result.clear();
    for (int i = 0; i < observers.size(); i++) {
      if (observers.at(i)->GetId() != attachedObserver) {
        observers.at(i)->Update(dt);
      } else {
        result.push_back(observers.at(i)->Update(dt));
      }
    }
  }
  return result;
}

void Publisher::Attach(int id) {
  attachedObserver = id;
}

void Publisher::Detach() {
  attachedObserver = -1;
}