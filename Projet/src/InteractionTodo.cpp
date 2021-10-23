#include "../headers/InteractionTodo.h"


InteractionTodo::InteractionTodo(Todo * t, Interaction * i) {
    this->setT(t);
    this->setI(i);
}

void InteractionTodo::setT(Todo * t) {
    this->t = t;
}

void InteractionTodo::setI(Interaction * i) {
    this->i = i;
}

Todo * InteractionTodo::getT() {
    return this->t;
}

Interaction * InteractionTodo::getI() {
    return this->i;
}

std::string InteractionTodo::getDebugValues(){
    return "InteractionTodo{\n  Interaction = "+
    this->getT()->getDebugValues()+"\n Todo = "+
    this->getI()->getDebugValues()+"\n}\n";
}

bool InteractionTodo::operator==(InteractionTodo& toCompare){
    return this->getT()==toCompare.getT() && this->getI()==toCompare.getI();
}


/*std::list<InteractionTodo> * InteractionTodo::listAllInteractionTodos(Interaction&) {
    // @TODO : Fonction qui récupère la liste des InteractionTodo pour une interaction donnée
}*/
