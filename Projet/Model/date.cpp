/* inspired and modified from http://www.cplusplus.com/forum/beginner/158359/ */
#include "date.h"

#include <regex>

/**
 * @class Date
 *
 * Custom interface built from the tm struct<br>
 * It allows easy management of dates using only three parameters, day, month and year.<br>
 * Therefore, the class is easily adjustable so we can later include hours, minutes, seconds if necessary.
 */

/**
 * @brief This program won't compile using std::to_string - Therefore we need to build a function that works the same using a template and a stringstream.<br>
 * https://stackoverflow.com/questions/32140018/why-is-this-program-giving-an-error-to-string-is-not-a-member-of-std-why/32140400
 *
 * @tparam T
 * @param value
 * @return std::string
 */
template<class T> std::string toString(const T &value) {
  std::ostringstream os;
  os << value;
  return os.str();
}

/**
 * @brief Constructor of Date initialized with current date
 *
 */
Date::Date(){
    time_t t = time(0);
    this->d = localtime(&t);

    int currentYear = d->tm_year+1900;
    int currentMonth = d->tm_mon+1;
    int currentDay = d->tm_mday;

    this->setMonth(currentMonth);
    this->setDay(currentDay);
    this->setYear(currentYear);
}

/**
 * @brief Constructor of date with parameters
 *
 * @param day must be between 1 and 31
 * @param month must be between 1 and 12
 * @param year must be higher than 1970
 */
Date::Date(const int day,const int month,const int year){
    this->setDay(day);
    this->setMonth(month);
    this->setYear(year);
}

Date::Date(const std::string & date){
    const std::regex DATEPATTERN("^([0-2][0-9]|[3][0|1])[-/]([0][1-9]|[1][0-2])[-/]([1][9][7-9][0-9]|[2][0-2][0-9][0-9])$");
    if(std::regex_match(date,DATEPATTERN)){
        this->setDay(std::stoi(date.substr(0,2)));
        this->setMonth(std::stoi(date.substr(3,2)));
        this->setYear(std::stoi(date.substr(6,4)));
    }
}

/**
 * @brief
 *
 * @param day must be between 1 and 31
 * @throw invalid_argument day isn't between 1 and 31
 */
void Date::setDay(const int day){
    if (day < 1 || day > 31){
        throw std::invalid_argument("Error in method setDay of class Date :\n\nThe day is invalid\n"+getDebugValues(0));
    }else{
      this->day = day;
  }
}

/**
 * @brief
 *
 * @param month must be between 1 and 12
 * @throw invalid_argument month isn't between 1 and 12
 */
void Date::setMonth(const int month){
    if (month < 1 || month > 12){
        throw std::invalid_argument("Error in method setMonth of class Date :\n\nThe month is invalid\n"+getDebugValues(0));
  }else{
    this->month = month;
  }
}

/**
 * @brief
 *
 * @param year must be higher than 1970
 * @throw invalid_argument year before 1970
 */
void Date::setYear(const int year){
    if (year < 1970){
        throw std::invalid_argument("Error in method setYear of class Date :\n\nThe year is invalid\n"+getDebugValues(0));
    }else{
        this->year = year;
    }
}

/**
 * @brief return Date values ( month, day, year ) which is suitable for debugging
 *
 *
 * @param nbTabulations Number of tabulations you want before showing informations.
 * If you call outside of getDebugValues function you should set this value to 0.
 * Also if you're inside DebugValues you should set this value to nbTabulations+1 for others getDebugsValues()
 * @return std::string
 */
std::string Date::getDebugValues(int nbTabulations){
    std::string tabulations = "";
  for(int x = 0;x<nbTabulations;x++){
    tabulations+="  ";
  }
    return "\n"+tabulations+"Date{"+
  "\n  "+tabulations+"Day = "+std::to_string(this->day)+
  "\n  "+tabulations+"Month = "+std::to_string(this->month)+
  "\n  "+tabulations+"Year = "+std::to_string(this->year)+
  "\n"+tabulations+"}\n";
}

std::string Date::toString(){
    return std::to_string(this->day)+"-"+std::to_string(this->month)+"-"+std::to_string(this->year);
}

/**
 * @brief Compares Date objects and determines if they're equals
 *
 * @param toCompare
 * @return bool
 */
bool Date::operator==(const Date &toCompare){
    return this->day == toCompare.day && this->month == toCompare.month && this->year == toCompare.year;
}

/**
 * @brief
 *
 * @param os
 * @param date
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, Date date){
    os << date.toString();
    return os;
}