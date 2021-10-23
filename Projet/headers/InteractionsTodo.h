#ifndef LOGS_H
#define LOGS_H

#include "InteractionTodo.h"

#include <algorithm>
#include <iostream>
#include <list>
#include <stdexcept>

class InteractionsTodo{
  private:
    std::list<InteractionTodo> * interactionsTodo;

  public:
    InteractionsTodo();
    ~InteractionsTodo();
    void add(InteractionTodo interactionTodo);

    int getSize();
    InteractionTodo get(int index);
    InteractionsTodo get(InteractionTodo interactionTodo);

    std::string getDebugValues();
};

#endif