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
 * @brief return InteractionTodo values ( interaction, todo ) which is suitable for debugging.
 * 
 * @param nbTabulations Number of tabulations you want before showing informations. 
 * If you call outside of getDebugValues function you should set this value to 0. 
 * Also if you're inside DebugValues you should set this value to nbTabulations+1 for others getDebugsValues()
 * @return std::string 
 */
std::string InteractionTodo::getDebugValues(int nbTabulations){
    std::string tabulations = "";
    for(int x = 0;x<nbTabulations;x++){
        tabulations+="  ";
    }
    return "\n"+tabulations+"InteractionTodo{"+
    "\n  "+tabulations+"Interaction = "+this->getT()->getDebugValues(nbTabulations+1)+
    "\n  "+tabulations+"Todo = "+this->getI()->getDebugValues(nbTabulations+1)+
    "\n"+tabulations+"}\n";
}

/**
 * @brief Compares InteractionTodo object and determine if they're equal.
 * 
 * @param toCompare 
 * @return true 
 * @return false 
 */
bool InteractionTodo::operator==(InteractionTodo& toCompare){
    return this->getT()==toCompare.getT() && this->getI()==toCompare.getI();
}


