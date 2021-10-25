#include "../headers/InteractionTodo.h"
/**
 * @brief Constructs a new InteractionTodo object from pointers toward an Interaction and a Todo as parameters.
 * 
 * @param t 
 * @param i 
 */
InteractionTodo::InteractionTodo(Todo * t, Interaction * i) {
    this->setT(t);
    this->setI(i);
}

/**
 * @brief Sets a pointer to the Todo
 * 
 * @param t 
 */
void InteractionTodo::setT(Todo * t) {
    this->t = t;
}

/**
 * @brief Sets a pointer to the Interaction
 * 
 * @param i 
 */
void InteractionTodo::setI(Interaction * i) {
    this->i = i;
}

/**
 * @brief Returns a pointer to the Todo
 * 
 * @return Todo* 
 */
Todo * InteractionTodo::getT() {
    return this->t;
}

/**
 * @brief Returns a pointer to the Interaction
 * 
 * @return Interaction* 
 */
Interaction * InteractionTodo::getI() {
    return this->i;
}

/**
 * @brief Returns InteractionTodo values ( interaction, todo ), suitable for debugging.
 * 
 * @param nbTabulations Number of tabulations needed to show informations. 
 * If called outside of getDebugValues function this value should be set to 0. 
 * Inside DebugValue this value should be set to nbTabulations+1 for others getDebugsValues()
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
 * @brief Compares InteractionTodo object and determines if they're equal.
 * 
 * @param toCompare 
 * @return true 
 * @return false 
 */
bool InteractionTodo::operator==(InteractionTodo& toCompare){
    return this->getT()==toCompare.getT() && this->getI()==toCompare.getI();
}

/**
 * @brief Overloading of the << operator. Redirects the following string in the output stream :<br><br>
 * <i>Interaction :</i><br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; [Interaction] </i><br><i>Is linked to the following TODO :</i><br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; [Todo]
 * 
 * @param os The out stream
 * @param it The InteractionTodo object to get values from
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const InteractionTodo& it){
    os << "Interaction :\n\t" << *it.i << "\nIs linked to the following TODO :\n\t" << *it.t << std::endl;
    return os;
}

