#ifndef LOG_H
#define LOG_H

#include "date.h"

#include <sstream>

class Contact;

/**
 * @brief A log represents an action done on a contact at a specific date
 *
 */
class Log{

      public:

        enum ActionType{
            CREATION_CONTACT,
            EDIT_FIRST_NAME,
            EDIT_LAST_NAME,
            EDIT_PHOTO,
            EDIT_ENTREPRISE,
            EDIT_MAIL,
            EDIT_PHONE,
            DELETE_CONTACT,
            REMOVE_INTERACTION,
            ADD_INTERACTION,
            EDIT_INTERACTION
        };

        Log(Contact*, const ActionType);

        Contact* getContact();
        Date getDateOfAction();
        ActionType getACTION_TYPE();
        std::string toString();

        bool operator==(const Log &toCompare);
        ///@private hiding the debug func from doxygen
        friend std::ostream& operator<<(std::ostream& , Log&);

        std::string getDebugValues(int nbTabulations);

    private:
      Contact* contact;
      Date dateOfAction;
      ActionType ACTION_TYPE;
};

#endif
