#include "mapinteractiontodo.h"

#include <qdebug.h>

/**
 * <p></p>
 * @class MapInteractionTodo This class encapsulates a std::map.
 * The keys are Interaction pointers.
 * The values are std::lists of Todo pointers.
 * Therefore, it links an interaction to its corresponding Todos. Without the @TODO and @DATE tags.
 *
 * <img src="../assets/MapITRepresentation.png">
 */

/**
 * <p></p>
 * @brief The constructor initializes the object with an empty map.
 */
MapInteractionTodo::MapInteractionTodo(){
    map = std::map<Interaction *, std::list<Todo *>>();
}

/**
 * This methods works in three steps :<br>
 * <b>1 :</b> Split the interaction content in multiple substrings between each "@TODO", and put those substrings in a list.<br>
 * For example, the string [aaaaa@TODObbbbb@TODOccccc] will be split into 3 strings : [aaaaa],[@TODObbbbb],[@TODOccccc].<br><br>
 * <b>2 :</b>If the first string did not contain @TODO, remove it from the substrings list.<br>
 * <b>3 :</b>Get the list<todo *> into the map at key(Interaction *), push new Todos made with those substrings into it. <br><br>
 * @brief The insert function takes an interaction as parameter. Its goal is to insert a list containing the Todos of this interaction and link it to the key : a Pointer on this interaction.
 * @param interaction
 */
void MapInteractionTodo::insert(Interaction * interaction){
    // 1 - Let's split the interaction between the TODO tags and push the substrings in a list. For self-harm purposes, we will use regex and according smatch.
    std::list<std::string> splits = std::list<std::string>();
    std::string contenu = interaction->getContent();
    std::regex pattern("@TODO");
    std::smatch match;
    this->map[interaction] = std::list<Todo *>();


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
    if(splits.front().find("@TODO") == std::string::npos)          //Checking for any list element that does not contain @TODO
        splits.pop_front();


    // 3 - Fill the InteractionTodo list with freshly created todos from the splits list (and an iterator)
    for(std::list<std::string>::iterator it = splits.begin() ; it != splits.end() ; it++ ){
        this->map.at(interaction).push_back(new Todo(*it));
    }
}

/**
 * <p></p>
 * @brief Pushes a todo * in the list<todo *> at key passed in parameter.
 * @param interaction
 * @param todo
 */
void MapInteractionTodo::insert(Interaction * interaction, Todo * todo){
    if ( this->map.find(interaction) == this->map.end() )
        this->map[interaction] = std::list<Todo *>();
    this->map.at(interaction).push_back(todo);
}

/**
 * <p></p>
 * @brief Deletes all the todos at the key passed in paramater, then erases the key.
 * @param interaction
 */
void MapInteractionTodo::remove(Interaction * interaction){
    std::list<Todo *>::iterator it;
    while(!this->map.at(interaction).empty())
        delete this->map.at(interaction).front();
    this->map.erase(interaction);
}

/**
 * <p></p>
 * @brief Returns true if the map has the key passed in parameter, else returns false.
 * @param interaction
 * @return bool
 */
bool MapInteractionTodo::hasKey(Interaction * interaction){
    return !(this->map.find(interaction) == map.end());
}

/**
 * <p></p>
 * @brief Return the list<Todo *> at the key passed in parameter.
 * @param interaction
 * @return std::list<Todo *>
 */
std::list<Todo *> MapInteractionTodo::at(Interaction * interaction){
    return this->map.at(interaction);
}
