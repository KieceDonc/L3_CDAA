#include <iostream>

class Interaction{

    private:
        std::string content;
        tm * date;

    public:
        Interaction();
        Interaction(const tm& , std::string&);
        ~Interaction();

        void setContent(const std::string&);
        void setDate(const tm&);
        std::string getContent();
        tm * getDate();

        friend std::ostream& operator<<(std::ostream& , const Interaction&);
};