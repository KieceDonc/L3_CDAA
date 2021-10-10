#include "Date.h"
#include "Contact.h"

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
    const static int ACTION_SUPPRESSION_CONTACT = 5;
    
    bool operator==(const Log &toCompare);
};