#ifndef INTERACTION_H
#define INTERACTION_H

#include <iostream>
#include <regex>
#include "Date.h"

/**
 * @brief An interaction is a block of text. It can be tagged with @TODO and @DATE to indicate tasks and change the date of said todos. 
 * An interaction is always linked to its date of creation.
 * 
 */
class Interaction{

    private:
        std::string content;
        Date date;

    public:
        Interaction();
        Interaction(const Date& , const std::string&);

        void setContent(const std::string&);
        void setDate(const Date&);
        std::string getContent();
        Date getDate();

        std::string getDebugValues(int nbTabulations);

        bool operator==(Interaction& toCompare);
        friend std::ostream& operator<<(std::ostream& , const Interaction&);

};

#endif