#include "../headers/InteractionTodos.h"


InteractionTodos::InteractionTodos() {
    this->setItList(new std::list<InteractionTodo>());
}

void InteractionTodos::setItList(std::list<InteractionTodo> * itList){
    this->itList = itList;
}

std::list<InteractionTodo> * InteractionTodos::getItList() {
    return this->itList;
}

void InteractionTodos::addInteraction(Interaction * interaction) {
    /* Static method returning the list of InteractionTodo of a given interaction

     The structure of an interaction is as follows ([] = optional ) :
            [COMMENT]
            [@TODO todo description [@DATE dd/mm/yyyy]]      -> n times (n between 0 and infinity (please not))
    */

    //*out = std::list<InteractionTodo>();
    
    

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
        splits.pop_front();

    // 3 - Fill the InteractionTodo list with freshly created todos from the splits list (and an iterator)
    for(std::list<std::string>::iterator it = splits.begin() ; it != splits.end() ; it++ ){
        this->getItList()->push_back(InteractionTodo(new Todo(*it) , interaction));
    }   
}

/**
 * @brief 
 * 
 * @param nbTabulations Number of tabulations you want before showing informations. 
 * If you call outside of getDebugValues function you should set this value to 0. 
 * Also if you're inside DebugValues you should set this value to nbTabulations+1 for others getDebugsValues()
 * @return std::string 
 */
std::string InteractionTodos::getDebugValues(int nbTabulations) {
    return "ok";
}

/**
 * @brief 
 * 
 * @param toCompare 
 * @return true 
 * @return false 
 */
bool InteractionTodos::operator==(InteractionTodos& toCompare) {
    return true;
}
