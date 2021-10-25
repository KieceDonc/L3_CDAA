
#include "../headers/Interaction.h"

/**
 * @class Interaction
 * Class for an Interaction specifications. 
 * An instance of Interaction will always contain a string (content) and its date of creation (date) through both its attributes.
 * The content of an interaction will always be a single string - And the syntax of an Interaction is as follow :<br><br>
 * <i>[Interaction comment]  [<b>@TODO</b> todo n°1 [<b>@DATE</b> dd/mm/yyyy]]  [<b>@TODO</b> todo n°2 [<b>@DATE</b> dd/mm/yyyy]] . . . . . [<b>@TODO</b> todo n°n [<b>@DATE</b> dd/mm/yyyy]]</i><br><br>
 * With bracketed elements being optional<br>
 * And n between 0 and inifinity (please don't do this)
 * 
 */


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
 * @param nbTabulations Number of tabulations you want before showing informations. 
 * If you call outside of getDebugValues function you should set this value to 0. 
 * Also if you're inside DebugValues you should set this value to nbTabulations+1 for others getDebugsValues()
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