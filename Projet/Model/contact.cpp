#include "contact.h"

/**
 * @class Contact
 * A contact represents an entity akin to a person, a group of persons, a service, a company...<br>
 * It is the main element of the class - Or at least the one that will be iterated onto the most along Interactions.<br>
 * A contact stores all of its basic informations (names, mail, etc...), a list of interactions.<br>
 *
 * <img src="../assets/ContactRepresentation.png">
 */

/**
 * @brief Constructs a new Contact object from all its parameters.
 *
 * @param firstName
 * @param lastName
 * @param entreprise
 * @param mail
 * @param phone
 * @param dateOfCreation
 * @param photo
 * @param interactions The interaction list of the contact.
 */
Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& enterprise, const std::string& mail, const std::string& phone, const std::string& photo, const Date& date){
    try{
        this->setFirstName(firstName);
        this->setLastName(lastName);
        this->setEnterprise(enterprise);
        this->setMail(mail);
        this->setPhone(phone);
        this->setDateOfCreation(date);
        this->setPhoto(photo);
        this->interactions = std::list<Interaction *>();
    }catch(...){
        throw std::invalid_argument("Error in contact constructor");
    }
}

/**
 * @brief Sets the firstname of a contact. Must have at contain one character.
 *
 * @throw invalid_argument firstname length must be higher than 0
 * @param lastName
 */
void Contact::setFirstName(const std::string& firstName){
    if(firstName.length() == 0)
        throw std::invalid_argument("Error in method setFirstName of class Contact :\n\nfirstName is invalid\n"+this->getDebugValues(0));
    else
        this->firstName = firstName;

}

/**
 * @brief Sets the lastname of a contact. Must at least contain one character.
 *
 * @throw invalid_argument lastName length must be higher than 0
 * @param lastName
 */
void Contact::setLastName(const std::string& lastName){
    if(lastName.length() == 0)
        throw std::invalid_argument("Error in method setLastName of class Contact :\n\nlastName is invalid\n"+this->getDebugValues(0));
    else
        this->lastName = lastName;
}

/**
 * @brief Sets the Company of a contact. Must at least have one character.
 *
 * @throw invalid_argument enterprise length must be higher than 0
 * @param enterprise
 */
void Contact::setEnterprise(const std::string& enterprise){
    if(enterprise.length() == 0)
        throw std::invalid_argument("Error in method setEnterprise of class Contact :\n\nenterprise is invalid\n"+this->getDebugValues(0));
    else
        this->enterprise = enterprise;

}

/**
 * @brief Sets the email of a contact. Must at least have one character, one @ and one "."
 *
 * @throw invalid_argument enterprise length must be higher than 0 and one @ and one "."
 * @param mail
 */
void Contact::setMail(const std::string& mail){
    if(mail.length() == 0 || !mail.find('@') || !mail.find('.'))
        // We check if mail isn't empty, if it contains an @ and a .
        throw std::invalid_argument("Error in method setMail of class Contact :\n\nmail is invalid\n"+this->getDebugValues(0));
    else
        this->mail = mail;

}

/**
 * @brief set phone of a contact. Must at least have one character.
 *
 * @throw invalid_argument phone length must be higher than 0
 * @param lastName
 */
void Contact::setPhone(const std::string& phone){
    if(phone.length() == 0)
        throw std::invalid_argument("Error in method setPhone of class Contact :\n\nphone is invalid\n"+this->getDebugValues(0));
    else
        this->phone = phone;
}

/**
 * @brief Set the date of creation of the contact. Represent when he was created.
 *
 * @param dateOfCreation
 */
void Contact::setDateOfCreation(const Date& date){
    this->dateOfCreation = date;
}

void Contact::setInteractions(std::list<Interaction *> lst)
{
    this->interactions = lst;
}

/**
 * @brief Sets the path of the contact's photo as a std::string.
 *
 * @param photo
 */
void Contact::setPhoto(const std::string& photo){
    this->photo = photo;
}


/**
 * @brief Returns the firstname of a contact.
 *
 * @return std::string
 */
std::string Contact::getFirstName(){
  return this->firstName;
}

/**
 * @brief Return the lastname of a contact.
 *
 * @return std::string
 */
std::string Contact::getLastName(){
  return this->lastName;
}

/**
 * @brief Return the enterprise of a contact.
 *
 * @return std::string
 */
std::string Contact::getEnterprise(){
  return this->enterprise;
}

/**
 * @brief Returns the mail of a contact.
 *
 * @return std::string
 */
std::string Contact::getMail(){
  return this->mail;
}

/**
 * @brief Returns the phone number of contact.
 *
 * @return std::string
 */
std::string Contact::getPhone(){
  return this->phone;
}

/**
 * @brief Returns the path to the contact's picture as a string.
 *
 * @return std::string
 */
std::string Contact::getPhoto(){
  return this->photo;
}

/**
 * @brief Returns the date of creation of this contact.
 *
 * @return Date
 */
Date Contact::getDateOfCreation(){
  return this->dateOfCreation;
}

/**
 * @brief
 *
 * @return std::list<Interaction *>
 */
std::list<Interaction *> Contact::getInteractions(){
  return this->interactions;
}

/**
 * @brief Adds an interaction to the list from a pointer.
 *
 * @param Interaction *
 */
void Contact::addInteraction(Interaction * interaction){
    this->interactions.push_back(interaction);
}

/**
 * @brief Removes an interaction from its index in the list using iterators.
 *
 * @param i
 */
void Contact::removeInteraction(int i){
  std::list<Interaction *>::iterator index;
  index = this->interactions.begin();
  if(i < (int)this->interactions.size()){
    std::advance(index,i);
    this->interactions.erase(index);
  }
}

/**
 * @brief returns Contact values ( firstname, lastname, mail ... ), suitable for debugging.
 *
 * @param nbTabulations Amount of tabulations needed to showing informations, allowing recursive calls.
 * If you call outside of getDebugValues function you should set this value to 0.
 * Also if you're inside DebugValues you should set this value to nbTabulations+1 for others getDebugsValues()
 * @return std::string
 */
std::string Contact::getDebugValues(int nbTabulations){
  std::string tabulations = "";
  for(int x = 0;x<nbTabulations;x++){
    tabulations+="  ";
  }
    return "\n"+tabulations+"Contact{"+
  "\n  "+tabulations+"First name = "+this->firstName+
  "\n  "+tabulations+"Last name = "+this->lastName+
  "\n  "+tabulations+"Enterprise = "+this->enterprise+
  "\n  "+tabulations+"Mail = "+this->mail+
  "\n  "+tabulations+"Phone = "+this->phone+
  "\n  "+tabulations+"Date of creation = "+this->dateOfCreation.getDebugValues(nbTabulations+1)+
  "\n"+tabulations+"}\n";
}

/**
 * @brief Compares Contact objects and determines if they're equals
 *
 * @param toCompare
 * @return bool
 */
bool Contact::operator==(const Contact &toCompare){
  return true
  && this->firstName == toCompare.firstName
  && this->lastName == toCompare.lastName
  && this->enterprise == toCompare.enterprise
  && this->mail == toCompare.mail
  && this->phone == toCompare.phone
  && this->photo == toCompare.photo
  && this->dateOfCreation == toCompare.dateOfCreation;
}

std::ostream& operator<<(std::ostream& os, Contact& c){
    os << c.getDebugValues(0);
    return os;
}

