#include "../headers/Todo.h"


Todo::Todo(const Date& date, const std::string& content) {
    this->setDate(date);
    this->setContent(content);
}

void Todo::setContent(const std::string& content) {
    this->content = content;
}

void Todo::setDate(const Date& date) {
    this->date = date;
}

std::string Todo::getContent() {
    return this->content;
}

Date Todo::getDate() {
    return this->date;
}

std::string Todo::getDebugValues(){
    return "Todo{\n  Date = "+
    this->getDate().getDebugValues()+"\n Content = "+
    this->getContent()+"\n}\n";
}

bool Todo::operator==(Todo &toCompare){
    return this->getContent()==toCompare.getContent() && this->getDate()==toCompare.getDate();
}