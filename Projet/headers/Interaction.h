#include <iostream>
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

        friend std::ostream& operator<<(std::ostream& , const Interaction&);
};