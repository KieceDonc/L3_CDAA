#include "../headers/Log.h"
#include "../headers/Contact.h"

/**
 * @class 
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
 * @brief Construct a new Log:: Log object
 * 
 * @param contact 
 * @param ACTION_TYPE 
 */
Log::Log(Contact* contact, const int ACTION_TYPE){
  this->contact = contact;
  this->ACTION_TYPE = ACTION_TYPE;
  this->dateOfAction = Date();
}

/**
 * @brief Returns the contact which is concerned by the action
 * 
 * @return Contact* 
 */
Contact* Log::getContact(){
  return this->contact;
}

/**
 * @brief Returns the day at which the action happend on the contact.
 * 
 * @return Date 
 */
Date Log::getDateOfAction(){
  return this->dateOfAction;
}

/**
 * @brief Returns an int corresponding to the action done on the contact.
 * 
 * @return int = 0  Creation of Contact
 * @return int = 1  Photo has been edited
 * @return int = 2  Enterprise has been edited
 * @return int = 3  Mail has been edited
 * @return int = 4  Phone number has been edited
 * @return int = 5  Contact has been deleted
 */
int Log::getACTION_TYPE(){
  return this->ACTION_TYPE;
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
  "\n  "+tabulations+"Contact = "+this->contact->getDebugValues(nbTabulations+1)+
  "\n  "+tabulations+"Date of action = "+this->dateOfAction.getDebugValues(nbTabulations+1)+
  "\n  "+tabulations+"ACTION_TYPE = "+toString(this->ACTION_TYPE)+
  "\n"+tabulations+"}\n";
}

/**
 * @brief Compares log object and determines if they're equal
 * 
 * @param toCompare 
 * @return boolean
 */
bool Log::operator==(const Log &toCompare){
  // We check if contact and date are the same so we call their respect equal function
  // We also check if it's the same action or not
  return &(this->contact) == &(toCompare.contact) && this->ACTION_TYPE == toCompare.ACTION_TYPE && this->dateOfAction == toCompare.dateOfAction;
}