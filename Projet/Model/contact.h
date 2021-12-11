#ifndef CONTACT_H
#define CONTACT_H
#include "photo.h"
#include "date.h"
#include "logs.h"
#include "interaction.h"

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
    std::string phone;
    Photo photo;
    Date dateOfCreation;
    std::list<Interaction *> interactions;
    void setDateOfCreation();

  public:
    Contact(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const Photo&, const Date& = Date(), Logs * = nullptr);

    void setFirstName(const std::string&, Logs * = nullptr);
    void setLastName(const std::string&, Logs * = nullptr);
    void setEnterprise(const std::string&, Logs * = nullptr);
    void setMail(const std::string&, Logs * = nullptr);
    void setPhone(const std::string&, Logs * = nullptr);
    void setPhoto(const Photo&, Logs * = nullptr);
    void setDateOfCreation(const Date& = Date());
    void setInteractions(std::list<Interaction *>);


    std::string getFirstName();
    std::string getLastName();
    std::string getEnterprise();
    std::string getMail();
    std::string getPhone();
    Photo getPhoto();
    Date getDateOfCreation();
    std::list<Interaction *> getInteractions();

    void addInteraction(Interaction*, Logs * = nullptr);
    void removeInteraction(int, Logs * = nullptr);

    ///@private hiding the debug func from doxygen
    std::string getDebugValues(int nbTabulations);

    bool operator==(const Contact &toCompare);
    friend std::ostream& operator<<(std::ostream& , Contact&);

};

#endif
