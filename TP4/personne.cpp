#include "personne.h"

/**
 * @brief Construct a new Contact:: Contact object
 *
 * @param logs
 * @param firstName
 * @param lastName
 * @param enterprise
 * @param mail
 * @param phone
 * @param photo
 */
Personne::Personne(const QString& firstName, const QString& lastName, const QString birthdate, const QString ville){
    this->firstName = firstName;
    this->lastName = lastName;
    this->birthdate = birthdate;
    this->ville = ville;
}

/**
 * @brief
 *
 * @return QString
 */
QString Personne::getFirstName(){
  return this->firstName;
}

/**
 * @brief
 *
 * @return QString
 */
QString Personne::getLastName(){
  return this->lastName;
}

/**
 * @brief
 *
 * @return QString
 */
QString Personne::getBirthdate(){
  return this->birthdate;
}



/**
 * @brief
 *
 * @return QString
 */
QString Personne::getVille(){
  return this->ville;
}

