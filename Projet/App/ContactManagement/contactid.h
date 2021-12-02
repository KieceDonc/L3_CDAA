#ifndef CONTACTID_H
#define CONTACTID_H

#include "contact.h"



class ContactID : public Contact
{
public:
    int ID;
    ContactID();
    void afficheContactID();
};

#endif // CONTACTID_H
