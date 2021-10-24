#ifndef LOGS_H
#define LOGS_H

#include "Date.h"
#include "Log.h"

#include <algorithm>
#include <iostream>
#include <list>
#include <stdexcept>

class Logs{
  private:
    std::list<Log> * logs;

  public:
    Logs();
    ~Logs();
    void add(Log log);

    int getSize();
    Log get(int index);
    Logs get(Contact * contact, int ACTION_TYPE, Date dateOfAction);

    std::string getDebugValues(int nbTabulations);
};

#endif