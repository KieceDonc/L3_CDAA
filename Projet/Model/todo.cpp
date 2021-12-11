#include "todo.h"

/**
 * @class Todo
 *
 * A todo object conceptually represent a SINGLE task to do, ponctually, in an interaction that can contain as many todos as it needs.<br>
 * Todos are defined using <b>@TODO</b> tags in an interaction.<br>
 * Todos dates are defined using <b>@DATE</b> tags in a todo.<br>
 * If no date is defined, then it is implied to be the current date!<br>
 * When printing a todo object, we do not need the tags since they are only needed to retrieve them from interaction contents.
 *
 * \subsection ex Examples
 * Consider the following interaction object :<br><br>
 * <dl><dt>Interaction{ </dt>
 * <dd>content = "Please Valentin we really need to finish this school project. @TODO Brew some coffee @TODO Rush the remaining work tomorrow (the @DATE 26/10/2021)"</dd><br>
 * <dd>date = Date(23/10/2021)</dd><br>}</dl><br><br>
 *
 * The todo objects we want to build here are :<br><br>
 * <dl><dt>Todo{ </dt>
 * <dd>content = "Brew some coffee"</dd><br>
 * <dd>date = Date(23/10/2021)</dd><br>}</dl><br></br>
 * <dl><dt>Todo{ </dt>
 * <dd>content = " Rush the remaining work tomorrow (the 26/10/2021)"</dd><br>
 * <dd>date = Date(26/10/2021)</dd><br>}</dl><br><br>
 *
 * \subsection err Errors
 *  There is only one error to manage here : Imputing a wrong date (incorrect format or whatever) - Or imputing two or more dates.<br>
 *  In both case, if there is an error, then the @DATE(S) will simply remain, not be treated, and the todo will be created at the current date
 */

/**
 * @brief Constructs a new Todo object from both parameters. Does not parse any tags.
 *
 * @param date
 * @param content
 */
Todo::Todo(const Date& date, const std::string& content) {
    this->setDate(date);
    this->setContent(content);
}

/**
 * @brief Construct a new Todo object from its content. <b>PARSES @DATE TAGS.</b><br>
 * Looks for the first occurence of @DATE and checks if the following word is a date to the dd/mm/yyyy format with regex.<br>
 * It then sets the todo date to that.<br>
 * If it doesn't match the regex, or there are multiple @DATE elements - Doesn't treat dates at all and sets the date to current date.
 *
 * @param content A string containing 0 or 1 "@DATE"
 */
Todo::Todo(const std::string& content){

    // Content is set to content, Date is set to date.
    this->setContent(content);
    this->setDate(Date());

    bool flag = false;

    std::string s = content;
    std::string dateStr;
    Date date;
    const std::regex DATEPATTERN("^([0-2][0-9]|[3][0|1])[-/]([0][1-9]|[1][0-2])[-/]([1][9][7-9][0-9]|[2][0-2][0-9][0-9])$");

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
 * @brief Sets the content of a todo without parsing any tags.
 *
 * @param content
 */
void Todo::setContent(const std::string& content) {
    this->content = content;
}

/**
 * @brief Sets the date using a date object. Must be valid.
 *
 * @param date
 */
void Todo::setDate(const Date& date) {
    this->date = date;
}

/**
 * @brief Returns the content of a todo as a string
 *
 * @return std::string
 */
std::string Todo::getContent() {
    return this->content;
}

/**
 * @brief Returns the date of the todo as a Date object
 *
 * @return Date
 */
Date Todo::getDate() {
    return this->date;
}

/**
 * @brief returns Todo values( date, content ), suitable for debugging
 *
 * @param nbTabulations Number of tabulations needed to show informations.
 * If called outside of getDebugValues function this value should be set to 0.
 * Inside DebugValue this value should be set to nbTabulations+1 for others getDebugsValues()
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
 * @brief Compares Todo objects and determines if they're equals
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

/**
 * @brief Overloading of the << operator. Redirects the following string in the output stream :
 * <i> [ TODO : dd/mm/yyyy ] content </i>
 *
 * @param os
 * @param todo
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os , const Todo& todo){
    os << "[ TODO : " << todo.date << "] " << todo.content;
    return os;
}
