#ifndef LOGS_H
#define LOGS_H

#include "Date.h"
#include "Log.h"

#include <algorithm>
#include <iostream>
#include <list>
#include <stdexcept>

/**
 * @brief Container for Log objects. 
 * 
 */
class Logs{
  private:
    std::list<Log> * logs;

  public:
    Logs();
    ~Logs();
    void add(Log log);

    int getSize();
    Log get(int index);

    ///@private hiding the debug func from doxygen
    Logs get(Contact * contact, int ACTION_TYPE, Date dateOfAction);

    std::string getDebugValues(int nbTabulations);
};

#endif