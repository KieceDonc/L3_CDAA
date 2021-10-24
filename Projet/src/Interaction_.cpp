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
 * @brief 
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
 * @return std::string 
 */
std::string Interaction::getDebugValues(){
    return "Interaction{\n  Date = "+
    this->getDate().getDebugValues()+"\n Content = "+
    this->getContent()+"\n}\n";
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