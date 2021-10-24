#ifndef PHOTO_H
#define PHOTO_H

#include <string>

class Photo{

  private:
    std::string uri;

  public:
    Photo();
    Photo(std::string uri);

    std::string getUri();
    std::string getDebugValues(int nbTabulations);

    bool operator==(Photo toCompare);
};

#endif