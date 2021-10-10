#include "../include/Log.h"

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
 * @param toCompare 
 * @return true 
 * @return false 
 */
bool Log::operator==(const Log &toCompare){
  return &(this->contact) == &(toCompare.contact) && this->ACTION_TYPE == toCompare.ACTION_TYPE && this->dateOfAction == toCompare.dateOfAction;
}