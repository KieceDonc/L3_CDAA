#ifndef INTERACTIONTODO_H
#define INTERACTIONTODO_H

#include "Interaction.h"
#include "Todo.h"
#include <list>
#include <string>

/**
 * @brief An InteractionTodo objects serves the purpose of linking an Interaction object with a Todo object through their pointers. 
 * 
 */
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

};

#endif