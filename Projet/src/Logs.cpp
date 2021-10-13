#include "../headers/Logs.h"


Logs::Logs(){
  this->logs = new std::list<Log>();
}

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
    throw std::invalid_argument("Error in method getLog of class Logs :\n\narray index out of bound\n"+getDebugValues());
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
 * @brief 
 * 
 * @return std::string 
 */
std::string Logs::getDebugValues(){
  std::string toReturn = "Logs{\n";
  for(int x=0;x<this->getSize();x++){
    toReturn+=+"  "+this->get(x).getDebugValues()+"\n";
  }
  toReturn+="}";
  return toReturn;
}