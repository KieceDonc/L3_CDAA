#include "../headers/Interaction.h"


Interaction::Interaction(const Date& date, const std::string& content) {
    this->setDate(date);   
    this->setContent(content); 
}

void Interaction::setContent(const std::string& content) {
    this->content = content;
}

void Interaction::setDate(const Date& date) {
    this->date = date;
}

std::string Interaction::getContent() {
    return this->content;
}

Date Interaction::getDate() {
    return this->date;
}

std::string Interaction::getDebugValues(){
    return "Interaction{\n  Date = "+
    this->getDate().getDebugValues()+"\n Content = "+
    this->getContent()+"\n}\n";
}

bool Interaction::operator==(Interaction &toCompare){
    return this->getContent()==toCompare.getContent() && this->getDate()==toCompare.getDate();
}