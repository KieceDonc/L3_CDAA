#ifndef PHOTO_H
#define PHOTO_H

#include <string>

/**
 * @brief Contains path to the real image
 * 
 */
class Photo{

  private:
    std::string uri;

  public:
    Photo();
    Photo(std::string uri);

    std::string getUri();

    ///@private hiding the debug func from doxygen
    std::string getDebugValues(int nbTabulations);

    bool operator==(Photo toCompare);
};

#endif