#include <iostream>

class Todo{

    private:
        std::string content;
        tm * date;

    public:
        Todo();
        Todo(const tm& , std::string&);
        ~Todo();

        void setContent(const std::string&);
        void setDate(const tm&);
        std::string getContent();
        tm * getDate();

        friend std::ostream& operator<<(std::ostream& , const Todo&);


};