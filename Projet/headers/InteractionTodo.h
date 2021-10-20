#include "Interaction.h"
#include "Todo.h"
#include <list>

class InteractionTodo{

    private:
        Todo * t ;
        Interaction * i ;

    public:
        InteractionTodo();
        InteractionTodo(const Todo& , const Interaction&);
        ~InteractionTodo();

        void setT(const Todo&) ;
        void setI(const Interaction&) ;
        Todo * getT() ;
        Interaction * getI() ;
        
        static std::list<InteractionTodo> * listAllInteractionTodos(Interaction&) ;
        

};