#ifndef LOG_H
#define LOG_H

#include "Date.h"

#include <sstream>

class Contact;

class Log{
  
  private:
    Contact* contact;
    Date dateOfAction;
    int ACTION_TYPE;

  public:
    Log(Contact* contact, const int ACTION_TYPE);

    Contact* getContact();
    Date getDateOfAction();
    int getACTION_TYPE();

    const static int ACTION_CREATION_CONTACT = 0;
    const static int ACTION_EDIT_PHOTO_CONTACT = 1;
    const static int ACTION_EDIT_ENTERPRISE = 2;
    const static int ACTION_EDIT_MAIL = 3;
    const static int ACTION_EDIT_PHONE = 4;
    const static int ACTION_DELETE_CONTACT = 5;
    
    std::string getDebugValues();

    bool operator==(const Log &toCompare);
};

#endif