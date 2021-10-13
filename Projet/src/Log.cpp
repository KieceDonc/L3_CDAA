#include "../headers/Log.h"
#include "../headers/Contact.h"

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
 * @brief 
 * 
 * @return std::string 
 */
std::string Log::getDebugValues(){
	return "Log{\n  Contact = "+
    this->contact->getDebugValues()+"\n Date of action = "+
    this->dateOfAction.getDebugValues()+"\n ACTION_TYPE = "+
    toString(this->ACTION_TYPE)+"\n}\n";
}

/**
 * @brief 
 * 
 * @param toCompare 
 * @return true 
 * @return false 
 */
bool Log::operator==(const Log &toCompare){
  return &(this->contact) == &(toCompare.contact) && this->ACTION_TYPE == toCompare.ACTION_TYPE && this->dateOfAction == toCompare.dateOfAction;
}