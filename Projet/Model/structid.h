#ifndef STRUCTID_H
#define STRUCTID_H

#include "contact.h"

/**
 * @brief Struct that contains a pointer to a contact and its ID (from the database)
 */

/**
 * @struct ContactID C Struct that holds a pointer to a contact and its ID in the database. That way, when we manipulate contacts with similar informations, they are different thanks to the ID.</br>
 * View <b>only manipulates</b> ContactID objects. <b>NEVER</b> contact.
 * GNJRDERG
 */
struct ContactID
{
    ///\brief id The id of the contact. Corresponds to its ID in the Database
    int id;
    ///\brief contact A pointer on a contact, its id in the Database is the id attribute (just above)
    Contact * contact;

    /**
     * @brief Simply compares the id of both contacts. Returns true if the IDs are similar.
     * @param toCompare the other ContactID to compare with.
     * @return
     */
    bool operator==(ContactID const & toCompare) const {
            return this->id == toCompare.id;
    }
};

#endif // STRUCTID_H
