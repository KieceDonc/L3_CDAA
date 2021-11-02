#ifndef CONTACT_H
#define CONTACT_H
#include "date.h"

#include <string>
#include <stdexcept>
#include <list>

/**
 * @brief A contact object represents an entity any user can interact with
 *
 */
class Contact{

  private:
    std::string firstName;
    std::string lastName;
    std::string enterprise;
    std::string mail;
    Date dateOfCreation;

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setDateOfCreation();

  public:
    Contact(const std::string& firstName, const std::string& lastName, const std::string& enterprise, const std::string& mail);


    void setEnterprise(const std::string& enterprise);
    void setMail(const std::string& mail);

    std::string getFirstName();
    std::string getLastName();
    std::string getEnterprise();
    std::string getMail();
    Date getDateOfCreation();

    ///@private hiding the debug func from doxygen
    std::string getDebugValues(int nbTabulations);

    bool operator==(const Contact &toCompare);

};

#endif
