#include "SimulationModel.h"

#include "DroneFactory.h"
#include "PackageFactory.h"
#include "RobotFactory.h"
#include "HumanFactory.h"
#include "HelicopterFactory.h"
#include "DroneObserver.h"
#include "PackageObserver.h"
#include "RobotObserver.h"
#include "PercentageDecorator.h"

SimulationModel::SimulationModel(IController& controller)
    : controller(controller) {
  entityFactory.AddFactory(new DroneFactory());
  entityFactory.AddFactory(new PackageFactory());
  entityFactory.AddFactory(new RobotFactory());
  entityFactory.AddFactory(new HumanFactory());
  entityFactory.AddFactory(new HelicopterFactory());
  publisher = new Publisher();
}

SimulationModel::~SimulationModel() {
  // Delete dynamically allocated variables
  for (auto& [id, entity] : entities) {
    delete entity;
  }
  delete graph;
  delete publisher;
}

IEntity* SimulationModel::createEntity(JsonObject& entity) {
  std::string name = entity["name"];
  std::string type = entity["type"];
  JsonArray position = entity["position"];
  std::cout << name << ": " << position << std::endl;

  IEntity* myNewEntity = nullptr;
  if (myNewEntity = entityFactory.CreateEntity(entity)) {
    // Call AddEntity to add it to the view
    myNewEntity->linkModel(this);
    controller.addEntity(*myNewEntity);
    entities[myNewEntity->getId()] = myNewEntity;
  }

  IObserver* observer = nullptr;
  
  if (type == "drone") {
    observer = new PercentageDecorator(new DroneObserver(reinterpret_cast<Drone*>(myNewEntity)));
  } else if (type == "package") {
    observer = new PercentageDecorator(new PackageObserver(reinterpret_cast<Package*>(myNewEntity)));
  } else if (type == "robot") {
    observer = new RobotObserver(reinterpret_cast<Robot*>(myNewEntity));
  }

  if (observer) {
    publisher->AddObserver(observer);
  }

  return myNewEntity;
}

void SimulationModel::removeEntity(int id) {
  removed.insert(id);
}

/// Schedules a Delivery for an object in the scene
void SimulationModel::scheduleTrip(JsonObject& details) {
  std::string name = details["name"];
  JsonArray start = details["start"];
  JsonArray end = details["end"];
  std::cout << name << ": " << start << " --> " << end << std::endl;

  Robot* receiver = nullptr;

  for (auto& [id, entity] : entities) {
    if (name == entity->getName()) {
      if (Robot* r = dynamic_cast<Robot*>(entity)) {
        if  (r->requestedDelivery) {
          receiver = r;
          break;
        }
      }
    }
  }

  Package* package = nullptr;

  for (auto& [id, entity] : entities) {
    if (name + "_package" == entity->getName()) {
      if (Package* p = dynamic_cast<Package*>(entity)) {
        if  (p->requiresDelivery) {
          package = p;
          break;
        }
      }
    }
  }

  if (receiver && package) {
    package->initDelivery(receiver);
    std::string strategyName = details["search"];
    package->setStrategyName(strategyName);
    scheduledDeliveries.push_back(package);
    controller.sendEventToView("DeliveryScheduled", details);
  }
}

const routing::IGraph* SimulationModel::getGraph() {
  return graph;
}

/// Updates the simulation
void SimulationModel::update(double dt) {
  for (auto& [id, entity] : entities) {
    entity->update(dt);
    controller.updateEntity(*entity);
  }

  for (int id : removed) {
    removeFromSim(id);
  }
  removed.clear();

  std::string message = "";
  std::vector<std::string> notifications = publisher->NotifyObserver(dt);
  for (int i = 0; i < notifications.size(); i++) {
    if (notifications.at(i) != "") {
      message += notifications.at(i);
    }
  }
  if (message != "") {
    JsonObject messageObject;
    messageObject["info"] = message;
    controller.sendEventToView("Notify", messageObject);
  }
}

void SimulationModel::stop(void) {
  controller.stop();
}

void SimulationModel::removeFromSim(int id) {
  IEntity* entity = entities[id];
  if (entity) {
    for (auto i = scheduledDeliveries.begin();
      i != scheduledDeliveries.end(); ++i) {
      if (*i == entity) {
        scheduledDeliveries.erase(i);
        break;
      }
    }
    controller.removeEntity(*entity);
    entities.erase(id);
    delete entity;
  }
}

void SimulationModel::Attach(int id) {
  publisher->Attach(id);
}

void SimulationModel::Detach() {
  publisher->Detach();
}
