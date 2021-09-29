#include "../include/Contact.h"
#include "../include/Date.h"
#include "../include/Photo.h"

#include <stdexcept>

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& enterprise, const std::string& mail, const std::string& phone, const Photo& photo, const Date& dateOfCreation){
  this->setFirstName(firstName);
  this->setLastName(lastName);
  this->setEnterprise(enterprise);
  this->setMail(mail);
  this->setPhone(phone);
  this->setDateOfCreation(dateOfCreation);
  this->setPhoto(photo);
}


void Contact::setFirstName(const std::string& firstName){
  if(firstName.length() == 0){
    throw std::invalid_argument("Error in method setFirstName of class Contact :\n\nfirstName is invalid\n"+getDebugValues());
  }else{
    this->firstName = firstName;
  }
}

void Contact::setLastName(const std::string& lastName){
  if(lastName.length() == 0){
    throw std::invalid_argument("Error in method setLastName of class Contact :\n\nlastName is invalid\n"+getDebugValues());
  }else{
    this->lastName = lastName;
  }
}

void Contact::setEnterprise(const std::string& enterprise){
  if(enterprise.length() == 0){
    throw std::invalid_argument("Error in method setEnterprise of class Contact :\n\nenterprise is invalid\n"+getDebugValues());
  }else{
    this->enterprise = enterprise;
  }
}

void Contact::setMail(const std::string& mail){
  if(mail.length() == 0 && !mail.find('@') && !mail.find('.')){
    // We check if mail isn't empty, if it contains an @ and a .
    throw std::invalid_argument("Error in method setMail of class Contact :\n\nmail is invalid\n"+getDebugValues());
  }else{
    this->mail = mail;
  }
}

void Contact::setPhone(const std::string& phone){
  if(phone.length() == 0){
    throw std::invalid_argument("Error in method setPhone of class Contact :\n\nphone is invalid\n"+getDebugValues());
  }else{
    this->phone = phone;
  }
}

void Contact::setDateOfCreation(const Date& dateOfCreation){
  this->dateOfCreation = dateOfCreation;
}

void Contact::setPhoto(const Photo& photo){
  this->photo = photo;
}

std::string Contact::getFirstName(){
  return this->firstName;
}

std::string Contact::getLastName(){
  return this->lastName;
}

std::string Contact::getEnterprise(){
  return this->enterprise;
}

std::string Contact::getMail(){
  return this->mail;
}

std::string Contact::getPhone(){
  return this->phone;
}

Photo Contact::getPhoto(){
  return this->photo;
}

Date Contact::getDateOfCreation(){
  return this->dateOfCreation;
}

/*
 * @return string which contain contact values ( firstname, lastname, mail ... ) and which is suitable for debugging
 * 
 * Format :
 * 
 * Contact{
 * 	First Name = Jean
 * 	LastName = Paul
 * 	Enterprise = StartupNumber654654
 *  Mail = Jean.Paul@StartupNumber654654.com
 *  Phone = 0701020304
 *  Date of creation = [Date]
 *  Photo = [photo]
 * }
 * 
**/
std::string Contact::getDebugValues(){
	return "\nDebug values :\nContact{\n	First name = "+
	this->firstName+"\n	Last name = "+
	this->lastName+"\n	Enterprise = "+
	this->enterprise+"\n Mail = "+
  this->mail+"\n	Phone = "+
  this->phone+"\n	Date of creation = "+
  this->dateOfCreation.getDebugValues()+"\n	Photo = "+
  this->photo.getDebugValues()+"\n}\n";
}