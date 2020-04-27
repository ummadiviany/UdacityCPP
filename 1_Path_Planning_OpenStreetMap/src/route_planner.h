#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "route_model.h"


class RoutePlanner {
  public:
    RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y);
    // Add public variables or methods declarations here.
    float GetDistance() const { return distance; };
    void AStarSearch();

  private:
    // Add private variables or methods declarations here.
    float CalculateHValue(RouteModel::Node  *node);
    std::vector<RouteModel::Node> ConstructFinalPath(RouteModel::Node *);
    RouteModel::Node *NextNode();
    RouteModel &m_Model;
    RouteModel::Node * start_node;
    RouteModel::Node * end_node;
    float distance;
    std::vector<RouteModel::Node *> open_list;
};

/*

To complete this exercise:
1. Add the following private variables to the `RoutePlanner` class in `route_planer.h`:
  - A `RouteModel` reference `m_Model`. This will refer to the model that you will be performing A\* search on.
  - `RouteModel::Node` pointers `start_node` and `end_node`. These will point to the nodes in the model which are closest to our starting and ending points.
  - A float `distance`. This variable will hold the total distance for the route that A\* search finds from `start_node` to `end_node`.
2. Add the following public method to the `RoutePlanner` class in `route_planner.h`:
  - A `GetDistance()` method. This is a public getter method for the `distance` variable, and should just return `distance`. This method will later be used to print out the total distance from `main.cpp`.
3. Use an initializer list in the `RoutePlanner` constructor in `route_planner.cpp` to initialize the `m_Model` variable with the passed `RoutePlanner` reference `model`.

Note that this exercise has no tests associated with it, but there will be tests in future exercises using the `RoutePlanner` class.
*/