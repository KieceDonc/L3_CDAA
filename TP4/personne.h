#ifndef PERSONNE_H
#define PERSONNE_H

#include <QString>

class Personne{
public:
    Personne(const QString& firstName, const QString& lastName, const QString birthdate, const QString ville);
    QString getFirstName();
    QString getLastName();
    QString getMail();
    QString getBirthdate();
    QString getVille();

private:
    QString firstName;
    QString lastName;
    QString birthdate;
    QString ville;

};

#endif // PERSONNE_H
