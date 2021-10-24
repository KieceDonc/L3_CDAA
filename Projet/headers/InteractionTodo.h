#ifndef INTERACTIONTODO_H
#define INTERACTIONTODO_H

#include "Interaction.h"
#include "Todo.h"
#include <list>
#include <string>

class InteractionTodo{

    private:
        Todo * t;
        Interaction * i;

    public:
        InteractionTodo();
        InteractionTodo(Todo *, Interaction *);

        void setT(Todo *) ;
        void setI(Interaction *) ;
        Todo * getT() ;
        Interaction * getI() ;

        std::string getDebugValues(int nbTabulations);

        bool operator==(InteractionTodo& toCompare);

        static std::list<InteractionTodo> * listAllInteractionTodos(Interaction *);
};

#endif