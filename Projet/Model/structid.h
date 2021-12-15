#ifndef STRUCTID_H
#define STRUCTID_H

#include "contact.h"

struct ContactID
{
    int id;
    Contact * contact;
    bool operator==(ContactID const & toCompare) const {
            return this->id == toCompare.id;
    }
};

struct InteractionID
{
    int id;
    Interaction * interaction();
};

#endif // STRUCTID_H
