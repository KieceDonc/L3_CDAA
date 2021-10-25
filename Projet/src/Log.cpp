#include "../headers/Log.h"
#include "../headers/Contact.h"

/**
 * @brief I don't really understand how it works but it fixes my problem and I'm ok with that
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
 * @brief 
 * 
 * @return Contact* 
 */
Contact* Log::getContact(){
  return this->contact;
}

/**
 * @brief 
 * 
 * @return Date 
 */
Date Log::getDateOfAction(){
  return this->dateOfAction;
}

/**
 * @brief 
 * 
 * @return int 
 */
int Log::getACTION_TYPE(){
  return this->ACTION_TYPE;
}

/**
 * @brief return Log values ( date, contact ) which is suitable for debugging
 * 
 * @param nbTabulations Number of tabulations you want before showing informations. 
 * If you call outside of getDebugValues function you should set this value to 0. 
 * Also if you're inside DebugValues you should set this value to nbTabulations+1 for others getDebugsValues()
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
 * @brief Compare log object and determine if they're equal
 * 
 * @param toCompare 
 * @return true 
 * @return false 
 */
bool Log::operator==(const Log &toCompare){
  // We check if contact and date are the same so we call their respect equal function
  // We also check if it's the same action or not
  return &(this->contact) == &(toCompare.contact) && this->ACTION_TYPE == toCompare.ACTION_TYPE && this->dateOfAction == toCompare.dateOfAction;
}