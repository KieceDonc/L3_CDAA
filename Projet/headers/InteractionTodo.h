#include "Interaction.h"
#include "Todo.h"
#include <list>

class InteractionTodo{

    private:
        Todo * t ;
        Interaction * i ;

    public:
        InteractionTodo();
        InteractionTodo(Todo *, Interaction *);

        void setT(Todo *) ;
        void setI(Interaction *) ;
        Todo * getT() ;
        Interaction * getI() ;
        
        //static std::list<InteractionTodo> * listAllInteractionTodos(Interaction&);

        std::string getDebugValues();

        bool InteractionTodo::operator==(InteractionTodo& toCompare);
};