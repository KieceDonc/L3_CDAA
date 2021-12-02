#ifndef TODO_H
#define TODO_H

#include <iostream>
#include <regex>
#include "date.h"

/**
 * @brief Represents a task from an interaction for a contact. Linked to Interaction objects using an InteractionTodo object.
 *
 */
class Todo{

    private:
        std::string content;
        Date date;

    public:
        Todo(const Date& , const std::string&);
        Todo(const std::string&);

        void setContent(const std::string&);
        void setDate(const Date&);
        std::string getContent();
        Date getDate();

        ///@private hiding the debug func from doxygen
        std::string getDebugValues(int nbTabulations);

        bool operator==(Todo& toCompare);
        friend std::ostream& operator<<(std::ostream& , const Todo&);
};

#endif
