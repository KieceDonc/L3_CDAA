#include <iostream>
#include "Date.h"

class Todo{

    private:
        std::string content;
        Date date;

    public:
        Todo();
        Todo(const Date& , const std::string&);

        void setContent(const std::string&);
        void setDate(const Date&);
        std::string getContent();
        Date getDate();

        std::string getDebugValues();

        bool operator==(Todo& toCompare);
        friend std::ostream& operator<<(std::ostream& , const Todo&);
};