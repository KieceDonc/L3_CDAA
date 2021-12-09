#include "photo.h"

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
 * @brief Returns Photo uri, suitable for debugging
 *
 * @param nbTabulations Number of tabulations needed to show informations.
 * If called outside of getDebugValues function this value should be set to 0.
 * Inside DebugValue this value should be set to nbTabulations+1 for others getDebugsValues()
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
