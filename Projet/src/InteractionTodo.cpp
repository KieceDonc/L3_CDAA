#include "../headers/InteractionTodo.h"

/**
 * @brief Construct a new Interaction Todo:: Interaction Todo object
 * 
 * @param t 
 * @param i 
 */
InteractionTodo::InteractionTodo(Todo * t, Interaction * i) {
    this->setT(t);
    this->setI(i);
}

/**
 * @brief 
 * 
 * @param t 
 */
void InteractionTodo::setT(Todo * t) {
    this->t = t;
}

/**
 * @brief 
 * 
 * @param i 
 */
void InteractionTodo::setI(Interaction * i) {
    this->i = i;
}

/**
 * @brief 
 * 
 * @return Todo* 
 */
Todo * InteractionTodo::getT() {
    return this->t;
}

/**
 * @brief 
 * 
 * @return Interaction* 
 */
Interaction * InteractionTodo::getI() {
    return this->i;
}

/**
 * @brief return InteractionTodo values ( interaction, todo ) which is suitable for debugging
 * 
 * @return std::string 
 */
std::string InteractionTodo::getDebugValues(){
    return "InteractionTodo{\n  Interaction = "+
    this->getT()->getDebugValues()+"\n Todo = "+
    this->getI()->getDebugValues()+"\n}\n";
}

/**
 * @brief Compare InteractionTodo object and determine if they're equal
 * 
 * @param toCompare 
 * @return true 
 * @return false 
 */
bool InteractionTodo::operator==(InteractionTodo& toCompare){
    return this->getT()==toCompare.getT() && this->getI()==toCompare.getI();
}


/*std::list<InteractionTodo> * InteractionTodo::listAllInteractionTodos(Interaction&) {
    // @TODO : Fonction qui récupère la liste des InteractionTodo pour une interaction donnée
}*/
