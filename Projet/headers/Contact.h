#ifndef CONTACT_H
#define CONTACT_H
#include "Photo.h"
#include "Date.h"
#include "Logs.h"
#include "Interaction.h"

#include <string>
#include <stdexcept>
#include <list>

/**
 * @brief A contact object represents an entity any user can interact with
 * 
 */
class Contact{

  private:
    Logs * logs;
    std::string firstName;
    std::string lastName;
    std::string enterprise;
    std::string mail;
    std::string phone;
    Photo photo;
    Date dateOfCreation;
    std::list<Interaction *> interactions;

    bool inConstructor; // tell if we're in constructor or not

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setDateOfCreation();

  public:
    Contact(Logs * logs,const std::string& firstName, const std::string& lastName, const std::string& enterprise, const std::string& mail, const std::string& phone, const Photo& photo);
    
    
    void setEnterprise(const std::string& enterprise);
    void setMail(const std::string& mail);
    void setPhone(const std::string& phone);
    void setPhoto(const Photo& photo);
    void addInteraction(Interaction *);
    
    std::string getFirstName();
    std::string getLastName();
    std::string getEnterprise();
    std::string getMail();
    std::string getPhone();
    Photo getPhoto();
    Date getDateOfCreation();
    std::list<Interaction *> getInteractions();

    ///@private hiding the debug func from doxygen
    std::string getDebugValues(int nbTabulations);

    bool operator==(const Contact &toCompare);
    
};

#endif