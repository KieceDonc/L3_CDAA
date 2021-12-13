#ifndef MAPINTERACTIONTODO_H
#define MAPINTERACTIONTODO_H

#include "interaction.h"
#include "todo.h"

#include <list>
#include <map>



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
