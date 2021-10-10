#include <string>

class Photo{

  public:
    std::string getDebugValues();

    bool operator==(const Photo &toCompare);

};