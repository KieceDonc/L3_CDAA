#include "interactiontodo.h"

/**
 * @class InteractionTodo
 * An InteractionTodo object has for sole purpose to link a pointer on Todo and a pointer on Interaction.<br>
 * It <b>conceptually means "Interaction i CONTAINS Todo t"</b><br>
 * It is similar to the way a Relational Database works : Attributes are <b>Atomic</b> since we associate a single interaction with a single todo.<br>
 * Somewhere in the program will be an InteractionTodos object that acts as a list of InteractionTodo (with a few useful methods to manipulate them) to store
 * all the possible links between existing Interaction objects and Todo objects.
 *
 * \subsection ex Example
 * Here is an example of an InteractionTodo object with both its attributes :
 *
 * <table><tr><td><b>attribute I</b></td><td><b>attribute T</b></td></tr><tr><td>new Interaction("Huge meeting @TODO call the boss")</td><td>new Todo("call the boss")</td></tr></table>
 *
 *
 */

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
 * @brief Sets T to a pointer on Todo<br>
 * A pointer is required here since we want a single object dynamically allocated in memory to represent a todo.<br>
 * Two todos from two different interactions with the same content are <b> conceptually NOT equals</b> - Therefore we can use their pointer values (adress) to compare them.
 *
 * @param t
 */
void InteractionTodo::setT(Todo * t) {
    this->t = t;
}

/**
 * @brief Sets I to a pointer on Interaction
 * A pointer is required here since we want a single object dynamically allocated in memory to represent a todo.<br>
 * Two interactions with the same content are <b> conceptually NOT equals</b> - Therefore we can use their pointer values (adress) to compare them.
 *
 *
 * @param i
 */
void InteractionTodo::setI(Interaction * i) {
    this->i = i;
}

/**
 * @brief Returns a pointer on Todo
 *
 * @return Todo*
 */
Todo * InteractionTodo::getT() {
    return this->t;
}

/**
 * @brief Returns a pointer on Interaction
 *
 * @return Interaction*
 */
Interaction * InteractionTodo::getI() {
    return this->i;
}

/**
 * @private
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
 * @brief Compares InteractionTodo object and determines if they're equals.
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

