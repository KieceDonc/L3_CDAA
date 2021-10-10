/* inspired and modified from http://www.cplusplus.com/forum/beginner/158359/ */

#include "../include/Date.h"

#include <stdexcept>
#include <time.h>

/**
 * @brief Default constructor of Date ( set the date when it was created )
 * 
 */
Date::Date(){
	time_t t = time(0);
	this->d = localtime(&t);

	int currentYear = d->tm_year+1900;
	int currentMonth = d->tm_mon+1;
	int currentDay = d->tm_mday;
	
	this->setMonth(month);
	this->setDay(day);
	this->setYear(year);
}

/**
 * @brief Constructor of date with parameters
 * 
 * @param month must be between 1 and 12 
 * @param day must be between 1 and 31 
 * @param year must be higher than 1970
 */
Date::Date(const int month,const int day,const int year){
	this->setMonth(month);
	this->setDay(day);
	this->setYear(year);
}

/**
 * @brief Destroy the Date:: Date object
 * 
 */
Date::~Date(){
	delete this->d;
}

/**
 * @brief 
 * 
 * @param day must be between 1 and 31
 * @throw invalid_argument day isn't between 1 and 31
 */
void Date::setDay(const int day){
	if (day < 1 && day > 31){
		throw std::invalid_argument("Error in method setDay of class Date :\n\nThe day is invalid\n"+getDebugValues());
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
	if (month < 1 && month > 12){
		throw std::invalid_argument("Error in method setMonth of class Date :\n\nThe day is invalid\n"+getDebugValues());
  }else{
    this->month = month;
  }
}

/**
 * @brief 
 * 
 * @param year must be higher than 1970
 * @throw invalid_argument year isn't between 1970 
 */
void Date::setYear(const int year){
	if (year < 1970){
		throw std::invalid_argument("Error in method setYear of class Date :\n\nThe day is invalid\n"+getDebugValues());
	}else{
		this->year = year;
	}
}

/**
 * @brief contain date values ( month, day, year ) which is suitable for debugging
 * 
 * @return std::string 
 */
std::string Date::getDebugValues(){
	return "\nDebug values :\nDate{\n	Month = "+
	std::to_string(this->month)+"\n	Day = "+
	std::to_string(this->day)+"\n	Year = "+
	std::to_string(this->year)+"\n}\n";
}

bool Date::operator==(const Date &toCompare){
	return this->day == toCompare.day && this->month == toCompare.month && this->year == toCompare.year;
}
