#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>
#include <stdexcept>
#include <time.h>

/**
 * @brief Simplifies the usage of C++ tm struct to represents dates. Uses the dd/mm/yyyy format
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

    std::string getDebugValues(int nbTabulations);

    bool operator==(const Date &toCompare);
    friend std::ostream& operator<<(std::ostream& , const Date&);

};

#endif