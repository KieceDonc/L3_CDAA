#include "log.h"
#include "contact.h"

/**
 * @class Log
 *
 * \subsection actype Action types
 * The Action enum defines the type of action that has been perfomed on the contact with enum constants as follows :
 * <table><tr><td><b>ACTION_TYPE</b><td><b>Integer value</b></td><td>Corresponding action</td></tr>
 * <tr><td>ACTION_CREATION_CONTACT</td><td>0</td><td>The contact has been made</td></tr>
 * <tr><td>ACTION_UPDATE_CONTACT/td><td>1</td><td>The contact has been updated</td></tr>
 * <tr><td>ACTION_DELETE_ENTERPRISE</td><td>2</td><td>The contact has been deleted</td></tr>
 * </table>
 *
 */

/**
 * @brief This program won't compile using std::to_string - Therefore we need to build a function that works the same using a template and a stringstream.
 *
 * @tparam T
 * @param value
 * @return std::string
 */
template<class T>
std::string toString(const T &value) {
  // https://stackoverflow.com/questions/32140018/why-is-this-program-giving-an-error-to-string-is-not-a-member-of-std-why/32140400
  std::ostringstream os;
  os << value;
  return os.str();
}

/**
 * @brief Constructs a new Log object
 *
 * @param contact
 * @param ACTION_TYPE
 */
Log::Log(Contact* contact, const ActionType actype){
  this->contact = contact;
  this->ACTION_TYPE = actype;
  this->dateOfAction = Date();
}

/**
 * @brief Returns the contact concerned by the action
 *
 * @return Contact*
 */
Contact* Log::getContact(){
  return this->contact;
}

/**
 * @brief Returns the day at which the action happaned
 *
 * @return Date
 */
Date Log::getDateOfAction(){
  return this->dateOfAction;
}

/**
 * @brief Returns an int corresponding to the action done on the contact.
 *
 * @return int = 0  Contact creation
 * @return int = 1  Contact update
 * @return int = 2  Contact deletion
 */
Log::ActionType Log::getACTION_TYPE(){
  return this->ACTION_TYPE;
}

std::string Log::toString(){
    std::string out;
    switch(this->ACTION_TYPE){
        case Log::CREATION_CONTACT : {
            out+= "[CREATED CONTACT] ";
            break;
        }
        case Log::UPDATE_CONTACT : {
            out+= "[UPDATED CONTACT]   ";
            break;
        }
        case Log::DELETE_CONTACT : {
            return "[DELETED CONTACT] ";
        }
    }
    std::string name;
    if(this->getContact() == nullptr)
        name = "-----";
    else
        name = this->getContact()->getFirstName()+" "+this->getContact()->getLastName();

    return out+name;
}

/**
 * @brief Returns Log values ( date, contact ), suitable for debugging
 *
 * @param nbTabulations Number of tabulations needed to show informations.
 * If called outside of getDebugValues function this value should be set to 0.
 * Inside DebugValue this value should be set to nbTabulations+1 for others getDebugsValues()
 * @return std::string
 */
std::string Log::getDebugValues(int nbTabulations){
  std::string tabulations = "";
  for(int x = 0;x<nbTabulations;x++){
      tabulations+="  ";
  }
  return "\n"+tabulations+"Log{"+
  "\n  "+tabulations+this->toString()+
  "\n"+tabulations+"}\n";
}

/**
 * @brief Compares log objects and determines if they're equals
 *
 * @param toCompare
 * @return boolean
 */
bool Log::operator==(const Log &toCompare){
  // We check if contact and date are the same so we call their respect equal function
  // We also check if it's the same action or not
  return &(this->contact) == &(toCompare.contact) && this->ACTION_TYPE == toCompare.ACTION_TYPE && this->dateOfAction == toCompare.dateOfAction;
}

/**
 * @brief Overloading the << operator.
 *
 * @param os
 * @param log
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, Log& log ){
    os << log.toString() << std::endl;
    return os;
}
