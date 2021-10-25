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


/**
 * @brief Method adding to the container the list of InteractionTodo objects from a given Interaction.<br>
 * As in, the set of links between the given Interaction and all its todos. <br>
 * 
 * @param interaction The interaction to retrieve the Todos from.
 */
void InteractionTodos::addInteraction(Interaction * interaction) {

    
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

    // 2 - If there is any text before the first TODO, remove it
    if(!splits.front().find("@TODO") != std::string::npos)          //Checking for any list element that does not contain @TODO
        splits.pop_front();

    // 3 - Fill the InteractionTodo list with freshly created todos from the splits list (and an iterator)
    for(std::list<std::string>::iterator it = splits.begin() ; it != splits.end() ; it++ ){
        this->getItList()->push_back(InteractionTodo(new Todo(*it) , interaction));
    }   
}

/**
 * @brief returns the debug values.
 * 
 * @param nbTabulations Number of tabulations needed to show informations. 
 * If called outside of getDebugValues function this value should be set to 0. 
 * Inside DebugValue this value should be set to nbTabulations+1 for others getDebugsValues()
 * @return std::string 
 */
std::string InteractionTodos::getDebugValues(int nbTabulations) {
    return " ";
}

/**
* @brief Overloading of the << operator. Redirects the following string in the output stream :<br><br>
 * [InteractionTodo]<br>[InteractionTodo]<br>. . . . .<br>[InteractionTodo]
 * 
 * @param os The out stream
 * @param it The InteractionTodo object to get values from
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, InteractionTodos& it){
    for(std::list<InteractionTodo>::iterator iter = it.getItList()->begin() ; iter != it.getItList()->end() ; iter++ ){
        os << *iter << "\n";
    }
    return os;
}
  
