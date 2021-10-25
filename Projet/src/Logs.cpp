#include "../headers/Logs.h"

/**
 * @brief I don't really understand how it work but it fix my problem and I'm ok with that
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
 * @brief Construct a new Logs:: Logs object
 * 
 */
Logs::Logs(){
  this->logs = new std::list<Log>();
}

/**
 * @brief Destroy the Logs:: Logs object
 * 
 */
Logs::~Logs(){
  delete logs;
}

/**
 * @brief 
 * 
 * @param log 
 */
void Logs::add(Log log){
  this->logs->emplace_back(log);
}

/**
 * @brief 
 * 
 * @return int 
 */
int Logs::getSize(){
  return this->logs->size();
}

/**
 * @brief 
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
 * @brief Sort logs from parameters (they can  be NULL , if they're NULL we consider that we don't need to sort from that parameter)
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
 * @brief return Logs values which is suitable for debugging
 * 
 * @param nbTabulations Number of tabulations you want before showing informations. 
 * If you call outside of getDebugValues function you should set this value to 0. 
 * Also if you're inside DebugValues you should set this value to nbTabulations+1 for others getDebugsValues()
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