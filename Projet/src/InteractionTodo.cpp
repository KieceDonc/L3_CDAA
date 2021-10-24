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
 * @brief Compares InteractionTodo object and determine if they're equal
 * 
 * @param toCompare 
 * @return true 
 * @return false 
 */
bool InteractionTodo::operator==(InteractionTodo& toCompare){
    return this->getT()==toCompare.getT() && this->getI()==toCompare.getI();
}


void InteractionTodo::listAllInteractionTodos(Interaction * interaction, std::list<InteractionTodo> * out) {
    /* Static method returning the list of InteractionTodo of a given interaction

     The structure of an interaction is as follows ([] = optional ) :
            [COMMENT]
            [@TODO todo description [@DATE dd/mm/yyyy]]      -> n times (n between 0 and infinity (please not))
    */
    
    // Return statement - The object we need to return is a list named out
    /*std::list<InteractionTodo> * out;
    *out = std::list<InteractionTodo>();*/

    // 1 - Let's split the interaction between the TODO tags and push the substrings in a list. For self-harm purposes, we will use regex and according smatch.
    std::list<std::string> splits = std::list<std::string>();
    std::string contenu = interaction->getContent();
    std::regex pattern("@TODO");
    std::smatch match;

    while(regex_search(contenu,match,pattern)){
        int positionTodo = match.position();                        // 1st @TODO position in the string
        splits.push_back(contenu.substr(0,positionTodo));           // Adding the content of the string before the first @TODO in the list
        contenu = contenu.substr(positionTodo + match.length());    // Removing the @TODO
        if(contenu[0] == ' ')                                       // Removing the first space character if there is one
            contenu = contenu.substr(1,contenu.length());     
    }   
    if(!contenu.empty())                                            // Adding the last todo element
        splits.push_back(contenu);

    // 2 - If there is a comment, remove it
    if(!splits.front().find("@TODO") != std::string::npos)
        out->pop_front();

    // 3 - Fill the InteractionTodo list with freshly created todos from the splits list (and an iterator)
    for(std::list<std::string>::iterator it = splits.begin() ; it != splits.end() ; it++ ){
        Todo todo = Todo(std::string(*it));
        out->push_back(InteractionTodo(&todo , interaction));
    }

    //return out;
}
