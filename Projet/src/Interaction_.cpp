
#include "../headers/Interaction.h"
/**
 * @brief Construct a new Interaction:: Interaction object
 * 
 * @param date 
 * @param content 
 */
Interaction::Interaction(const Date& date, const std::string& content) {
    this->setDate(date);   
    this->setContent(content); 
}

/**
 * @brief sets the content of an interaction
 * 
 * @param content 
 */
void Interaction::setContent(const std::string& content) {
    this->content = content;
}

/**
 * @brief 
 * 
 * @param date 
 */
void Interaction::setDate(const Date& date) {
    this->date = date;
}

/**
 * @brief 
 * 
 * @return std::string 
 */
std::string Interaction::getContent() {
    return this->content;
}

/**
 * @brief 
 * 
 * @return Date 
 */
Date Interaction::getDate() {
    return this->date;
}

/**
 * @brief return Interaction values ( date, content ) which is suitable for debugging
 * 
 * @param nbTabulationss
 * @return std::string 
 */
std::string Interaction::getDebugValues(int nbTabulations){
    std::string tabulations = "";
    for(int x = 0;x<nbTabulations;x++){
        tabulations+="  ";
    }
    return "\n"+tabulations+"Interaction{"+
    "\n  "+tabulations+"Date = "+this->getDate().getDebugValues(nbTabulations+1)+
    "\n  "+tabulations+"Content = "+this->getContent()+
    "\n"+tabulations+"}\n";
}

/**
 * @brief Compare interaction object and determine if they're equal
 * 
 * @param toCompare 
 * @return true 
 * @return false 
 */
bool Interaction::operator==(Interaction &toCompare){
    // We check if content object and date object are equals 
    // We call their respective equal function
    return this->getContent()==toCompare.getContent() && this->getDate()==toCompare.getDate();
}

/**
 * @brief 
 * 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Interaction& i){
    os << "[" << i.date << "] " << i.content;
    return os;
}