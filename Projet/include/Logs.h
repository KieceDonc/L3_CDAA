#include <algorithm>
#include <iostream>
#include <list>
#include "Log.h"
#include "Contact.h"

class Logs{
  private:
    std::list<Log> logs;

  public:
    void add(Log log);

    int getSize();
    Log get(int index);
    Logs get(Contact* contact, int ACTION_TYPE, Date dateOfAction);
    std::string getDebugValues();
};