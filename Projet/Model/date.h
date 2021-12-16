#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>
#include <stdexcept>
#include <time.h>

/**
 * @brief Simplifies the use of C++ tm struct to represent dates. Uses the dd-MM-yyyy or dd/MM/yyyy formats.
 *
 *
 */
class Date{

  private:
    struct tm * d;
      int month, day, year;

    void setDay(const int day);
    void setMonth(const int month);
    void setYear(const int year);

  public:
      Date();
      Date(const int month,const int day,const int year);
      Date(const std::string&);

    ///@private hiding the debug func from doxygen
    std::string getDebugValues(int nbTabulations);
    std::string toString();
    std::string toLexicalString();

    bool operator==(const Date &toCompare);
    friend std::ostream& operator<<(std::ostream& , Date);

};

#endif
