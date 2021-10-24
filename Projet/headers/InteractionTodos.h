#ifndef INTERACTIONTODOS_H
#define INTERACTIONTODOS_H

#include "InteractionTodo.h"
#include <list>
#include <string>

class InteractionTodos{

    private:
        std::list<InteractionTodo> * itList;

    public:
        InteractionTodos();

        std::list<InteractionTodo> * getItList() ;
        void setItList(std::list<InteractionTodo> *);

        void addInteraction(Interaction *);

        std::string getDebugValues(int nbTabulations);

        bool operator==(InteractionTodos& toCompare);

};

#endif