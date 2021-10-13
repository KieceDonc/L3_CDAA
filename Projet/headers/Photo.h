#ifndef PHOTO_H
#define PHOTO_H

#include <string>

class Photo{

  public:
    std::string getDebugValues();

    bool operator==(const Photo &toCompare);

};

#endif