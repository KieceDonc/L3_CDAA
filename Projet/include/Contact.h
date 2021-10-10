#ifndef CONTACT_H
#define CONTACT_H

#include "Date.h"
#include "Photo.h"
#include "Logs.h"
#include <string>


class Contact{

  private:
    Logs* logs;
    std::string firstName;
    std::string lastName;
    std::string enterprise;
    std::string mail;
    std::string phone;
    Photo photo;
    Date dateOfCreation;
    bool inConstructor; // tell if we're in constructor or not

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setDateOfCreation(const Date& dateOfCreation);

  public:
    Contact(Logs* logs,const std::string& firstName, const std::string& lastName, const std::string& enterprise, const std::string& mail, const std::string& phone, const Photo& photo);

    ~Contact();
    
    void setEnterprise(const std::string& enterprise);
    void setMail(const std::string& mail);
    void setPhone(const std::string& phone);
    
    std::string getFirstName();
    std::string getLastName();
    std::string getEnterprise();
    std::string getMail();
    std::string getPhone();
    Photo getPhoto();
    Date getDateOfCreation();
    std::string getDebugValues();

    void setPhoto(const Photo& photo);

    bool operator==(const Contact &toCompare);
};

#endif