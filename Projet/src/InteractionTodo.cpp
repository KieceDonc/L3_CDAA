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

std::list<InteractionTodo> * InteractionTodo::listAllInteractionTodos(Interaction&) {
    // @TODO : Fonction qui récupère la liste des InteractionTodo pour une interaction donnée
}
