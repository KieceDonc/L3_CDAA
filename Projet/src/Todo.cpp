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
