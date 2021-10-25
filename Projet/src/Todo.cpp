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
 * @param content 
 */
Todo::Todo(const std::string& content){

    this->setContent(content);
    this->setDate(Date());

    bool flag = false;
    
    std::string s = content;
    std::string dateStr;
    Date date;
    const std::regex DATEPATTERN("^([0-2][0-9]|[3][0|1])[/]([0][1-9]|[1][0-2])[/]([1][9][7-9][0-9]|[2][0-2][0-9][0-9])$");

    int match = s.find("@DATE");
    if(match != std::string::npos){
        s.erase(match,6);
        dateStr = s.substr(match,10);
        
        if(std::regex_match(dateStr,DATEPATTERN)){
            date = Date(std::stoi(dateStr.substr(0,2)),std::stoi(dateStr.substr(3,2)),std::stoi(dateStr.substr(6,4)));
        } 
        else flag = true;
    
        match = s.find("@DATE");
        if(match == std::string::npos && !flag){
            this->setContent(s);
            this->setDate(date);
        }
    }

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
 * @param nbTabulations
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