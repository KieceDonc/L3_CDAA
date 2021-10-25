#include "../headers/Photo.h"

/**
 * @class
 * 
 */

/**
 * @brief Construct a new Photo:: Photo object
 * Sets a path which leads to a default image ( no image provided )
 * 
 */
Photo::Photo(){
  this->uri = "../assets/default.jpg";
}

/**
 * @brief Construct a new Photo:: Photo object
 * Sets a path which leads to contact photo
 * 
 * @param uri 
 */
Photo::Photo(std::string uri){
  this->uri = uri;
}

/**
 * @brief Return path to contact image
 * 
 * @return std::string 
 */
std::string Photo::getUri(){
  return this->uri;
}

/**
 * @brief return Photo uri which is suitable for debugging
 * 
 * @param nbTabulations Number of tabulations you want before showing informations. 
 * If you call outside of getDebugValues function you should set this value to 0. 
 * Also if you're inside DebugValues you should set this value to nbTabulations+1 for others getDebugsValues()
 * @return std::string 
 */
std::string Photo::getDebugValues(int nbTabulations){
  std::string tabulations = "";
  for(int x = 0;x<nbTabulations;x++){
      tabulations+="  ";
  }
  return "\n"+tabulations+"Photo{"+
  "\n  "+tabulations+"uri = "+this->getUri()+
  "\n"+tabulations+"}\n";
}

/**
 * @brief Compares photo object and determines if they're equal
 * 
 * @param toCompare 
 * @return true 
 * @return false 
 */
bool Photo::operator==(Photo toCompare){
  // We check if uri is same
  return this->getUri()==toCompare.getUri();
}
