#include "mapinteractiontodo.h"

#include <qdebug.h>

MapInteractionTodo::MapInteractionTodo(){
    map = std::map<Interaction *, std::list<Todo *>>();
}

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

void MapInteractionTodo::insert(Interaction * interaction, Todo * todo){
    if ( this->map.find(interaction) == this->map.end() )
        this->map[interaction] = std::list<Todo *>();
    this->map.at(interaction).push_back(todo);
}

void MapInteractionTodo::remove(Interaction * interaction){
    std::list<Todo *>::iterator it;
    while(!this->map.at(interaction).empty())
        delete this->map.at(interaction).front();
    this->map.erase(interaction);
}

bool MapInteractionTodo::hasKey(Interaction * interaction){
    return !(this->map.find(interaction) == map.end());
}

std::list<Todo *> MapInteractionTodo::at(Interaction * interaction){
    return this->map.at(interaction);
}
