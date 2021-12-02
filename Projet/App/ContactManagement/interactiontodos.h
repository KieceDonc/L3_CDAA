#ifndef INTERACTIONTODOS_H
#define INTERACTIONTODOS_H

#include "interactiontodo.h"
#include <list>
#include <string>

/**
 * @brief Container for InteractionTodo objects.
 *
 */
class InteractionTodos{

    private:
        std::list<InteractionTodo> * itList;

    public:
        InteractionTodos();
        ~InteractionTodos();

        std::list<InteractionTodo> * getItList() ;
        void setItList(std::list<InteractionTodo> *);

        void addInteraction(Interaction *);

        ///@private hiding the debug func from doxygen
        std::string getDebugValues(int nbTabulations);

        friend std::ostream& operator<<(std::ostream& , InteractionTodos&);

};

#endif
