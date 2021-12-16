#ifndef CONTACT_H
#define CONTACT_H
#include "date.h"
#include "interaction.h"

#include <string>
#include <stdexcept>
#include <list>

/**
 * @brief A contact object represents an entity any user can interact with.
 *
 */
class Contact{

  private:
    std::string firstName;
    std::string lastName;
    std::string enterprise;
    std::string mail;
    std::string phone;
    std::string photo;
    Date dateOfCreation;
    std::list<Interaction *> interactions;
    void setDateOfCreation();

  public:
    Contact(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const Date& = Date());

    void setFirstName(const std::string&);
    void setLastName(const std::string&);
    void setEnterprise(const std::string&);
    void setMail(const std::string&);
    void setPhone(const std::string&);
    void setPhoto(const std::string&);
    void setDateOfCreation(const Date& = Date());
    void setInteractions(std::list<Interaction *>);


    std::string getFirstName();
    std::string getLastName();
    std::string getEnterprise();
    std::string getMail();
    std::string getPhone();
    std::string getPhoto();
    Date getDateOfCreation();
    std::list<Interaction *> getInteractions();

    void addInteraction(Interaction*);
    void removeInteraction(int);

    ///@private hiding the debug func from doxygen
    std::string getDebugValues(int nbTabulations);

    bool operator==(const Contact &toCompare);
    friend std::ostream& operator<<(std::ostream& , Contact&);

};

#endif
