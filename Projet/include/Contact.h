#include "Date.h"
#include "Photo.h"

class Contact{

  private:
    std::string firstName;
    std::string lastName;
    std::string enterprise;
    std::string mail;
    std::string phone;
    Photo photo;
    Date dateOfCreation;

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setEnterprise(const std::string& enterprise);
    void setMail(const std::string& mail);
    void setPhone(const std::string& phone);
    void setDateOfCreation(const Date& dateOfCreation);

  public:
    Contact(const std::string& firstName, const std::string& lastName, const std::string& enterprise, const std::string& mail, const std::string& phone, const Photo& photo, const Date& dateOfCreation);

    ~Contact(){}
    
    std::string getFirstName();
    std::string getLastName();
    std::string getEnterprise();
    std::string getMail();
    std::string getPhone();
    Photo getPhoto();
    Date getDateOfCreation();
    std::string getDebugValues();

    void setPhoto(const Photo& photo);
};