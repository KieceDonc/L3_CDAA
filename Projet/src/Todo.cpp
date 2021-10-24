#include "../headers/Todo.h"

/**
 * @brief Construct a new Todo:: Todo object
 * 
 * @param date 
 * @param content 
 */
Todo::Todo(const Date& date, const std::string& content) {
    this->setDate(date);
    this->setContent(content);
}

/**
 * @brief Construct a new Todo:: Todo object
 * 
 * @param date 
 * @param content 
 */
Todo::Todo(const std::string& content) {
    this->setDate(Date());
    this->setContent(content);
}

/**
 * @brief 
 * 
 * @param content 
 */
void Todo::setContent(const std::string& content) {
    this->content = content;
}

/**
 * @brief 
 * 
 * @param date 
 */
void Todo::setDate(const Date& date) {
    this->date = date;
}

/**
 * @brief 
 * 
 * @return std::string 
 */
std::string Todo::getContent() {
    return this->content;
}

/**
 * @brief 
 * 
 * @return Date 
 */
Date Todo::getDate() {
    return this->date;
}

/**
 * @brief return Todo values( date, content ) which is suitable for debugging
 * 
 * @return std::string 
 */
std::string Todo::getDebugValues(int nbTabulations){
    std::string tabulations = "";
    for(int x = 0;x<nbTabulations;x++){
        tabulations+="  ";
    }
    return "\n"+tabulations+"Todo{"+
    "\n  "+tabulations+"Date = "+this->getDate().getDebugValues(nbTabulations)+
    "\n  "+tabulations+"Content = "+this->getContent()+
    "\n"+tabulations+"}\n";
}

/**
 * @brief Compare Todo object and determine if they're equal
 * 
 * @param toCompare 
 * @return true 
 * @return false 
 */
bool Todo::operator==(Todo &toCompare){
    // We check if content object and date object are equals 
    // We call their respective equal function
    return this->getContent()==toCompare.getContent() && this->getDate()==toCompare.getDate();
}

std::ostream& operator<<(std::ostream& os , const Todo& todo){
    os << "[" << todo.date << "] " << todo.content;
    return os;
}