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
            UPDATE_CONTACT,
            DELETE_CONTACT,
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
