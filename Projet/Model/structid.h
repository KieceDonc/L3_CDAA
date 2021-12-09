#ifndef STRUCTID_H
#define STRUCTID_H

#include "contact.h"

struct ContactID
{
    int id;
    Contact * contact;
};

struct InteractionID
{
    int id;
    Interaction * interaction();
};

#endif // STRUCTID_H
