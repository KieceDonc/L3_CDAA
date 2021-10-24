#ifndef INTERACTION_H
#define INTERACTION_H

#include <iostream>
#include <regex>
#include "Date.h"

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

        std::string getDebugValues();

        bool operator==(Interaction& toCompare);
        friend std::ostream& operator<<(std::ostream& , const Interaction&);

};

#endif