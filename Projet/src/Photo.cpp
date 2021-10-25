#include "../headers/Photo.h"

/**
 * @brief Construct a new Photo:: Photo object
 * 
 */
Photo::Photo(){
  this->uri = "../assets/default.jpg";
}

/**
 * @brief Construct a new Photo:: Photo object
 * 
 * @param uri 
 */
Photo::Photo(std::string uri){
  this->uri = uri;
}

/**
 * @brief 
 * 
 * @return std::string 
 */
std::string Photo::getUri(){
  return this->uri;
}

/**
 * @brief return Photo uri which is suitable for debugging
 * 
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
