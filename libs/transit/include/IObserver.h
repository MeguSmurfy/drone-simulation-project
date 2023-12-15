#ifndef I_OBSERVER_H_
#define I_OBSERVER_H_

#include <string>

class IObserver {
 public:
  virtual std::string Update(double dt) = 0;
  virtual int GetId() = 0;
};

#endif