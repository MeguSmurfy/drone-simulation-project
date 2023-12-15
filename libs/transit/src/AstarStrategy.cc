/**
 * @file AstarStrategy.h
 * @brief This file contains the AstarStrategy class which implements the A* algorithm for pathfinding.
 */

#include "AstarStrategy.h"
#include "routing/astar.h"

/**
 * @class AstarStrategy
 * @brief Implements a strategy for pathfinding using the A* algorithm.
 * 
 * AstarStrategy is a class that uses the A* algorithm to find a path from a start
 * position to a destination in a graph. It is designed to work with
 * the routing::IGraph interface for obtaining the path.
 */

/**
 * @brief Creates an AstarStrategy object.
 * 
 * This constructor initializes the AstarStrategy object with a starting position, a 
 * destination, and a graph on which the A* algorithm will be executed.
 * 
 * @param pos The starting position as a Vector3.
 * @param des The destination position as a Vector3.
 * @param g Pointer to the graph on which A* algorithm will be used.
 */

AstarStrategy::AstarStrategy(Vector3 pos, Vector3 des,
                             const routing::IGraph* g) {
  std::vector<float> start = {
    static_cast<float>(pos[0]),
    static_cast<float>(pos[1]),
    static_cast<float>(pos[2])
  };
  std::vector<float> end = {
    static_cast<float>(des[0]),
    static_cast<float>(des[1]),
    static_cast<float>(des[2])
  };
  path = g->GetPath(start, end, routing::AStar::Default());
}
