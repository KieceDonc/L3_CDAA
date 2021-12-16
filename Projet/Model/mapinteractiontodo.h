#ifndef MAPINTERACTIONTODO_H
#define MAPINTERACTIONTODO_H

#include "interaction.h"
#include "todo.h"

#include <list>
#include <map>

/**
 * @brief An object that encapsulates a c++ map container. Maps an interaction pointer to a list of its todo pointers.
 */

class MapInteractionTodo
{
private :
    std::map<Interaction *, std::list<Todo *>> map;

public:
    MapInteractionTodo();
    void insert(Interaction *);
    void insert(Interaction *, Todo *);
    void remove(Interaction *);
    bool hasKey(Interaction *);
    std::list<Todo*> at(Interaction *);

};

#endif // MAPINTERACTIONTODO_H
