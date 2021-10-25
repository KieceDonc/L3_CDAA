#include "../headers/Logs.h"
/**
 * @class 
 * 
 */

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
 * @brief Constructs a new Logs object
 * Initializes the list inside the container
 */
Logs::Logs(){
  this->logs = new std::list<Log>();
}

/**
 * @brief Destroys the Logs
 * Will destruct the list inside the container
 * 
 */
Logs::~Logs(){
  delete logs;
}

/**
 * @brief Adds a Log at the end of the list
 * 
 * @param log 
 */
void Logs::add(Log log){
  this->logs->emplace_back(log);
}

/**
 * @brief Returns the amount of log in logs.
 * 
 * @return int 
 */
int Logs::getSize(){
  return this->logs->size();
}

/**
 * @brief Returns Log at a given index
 * 
 * @param index 
 * @return Log 
 */
Log Logs::get(int index){
  int size = this->getSize();
  if(index>size){
    throw std::invalid_argument("Error in method getLog of class Logs :\n\narray index out of bound\n"+getDebugValues(0));
  }else{
    std::list<Log>::iterator it = logs->begin();
    std::advance(it,index);
    return *it;
  }
}

/**
 * @brief Sorts logs from its parameters (they can be NULL , if they're NULL we consider that we don't need to sort depending on that parameter)
 * 
 * @param contact 
 * @param ACTION_TYPE if ACTION_TYPE < 0 we consider that we don't need to sort from that parameter
 * @param dateOfAction 
 * @return Logs 
 */
Logs Logs::get(Contact *contact, int ACTION_TYPE, Date dateOfAction){
  Logs foundedLogs = Logs();
  
  for(int x=0;x<this->getSize();x++){
    Log currentLog = this->get(x);
    if((!contact || currentLog.getContact()==contact) && (ACTION_TYPE<0 || currentLog.getACTION_TYPE()==ACTION_TYPE) && (!(&dateOfAction) || currentLog.getDateOfAction()==dateOfAction)){
      foundedLogs.add(currentLog);
    }
  }

  return foundedLogs;
}

/**
 * @brief Returns Logs values, suitable for debugging
 * 
 * @param nbTabulations Number of tabulations needed to show informations. 
 * If called outside of getDebugValues function this value should be set to 0. 
 * Inside DebugValue this value should be set to nbTabulations+1 for others getDebugsValues()
 * @return std::string 
 */
std::string Logs::getDebugValues(int nbTabulations){
  std::string tabulations = "";
  for(int x = 0;x<nbTabulations;x++){
      tabulations+="  ";
  }
  std::string toReturn ="\n"+tabulations+"Logs{";
  for(int x=0;x<this->getSize();x++){
    toReturn+="\n  "+tabulations+"Log n°"+toString(x)+" = "+this->get(x).getDebugValues(nbTabulations+1);
  }
  toReturn+="\n"+tabulations+"}\n";
  return toReturn;
}