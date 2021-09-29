/* inspired and modified from http://www.cplusplus.com/forum/beginner/158359/ */

#include "../include/Date.h"

#include <stdexcept>

/*
 *
 * Default constructor of Date
 * It will set the month and the day to 1 and the year to 1970
 * ( January 01, 1970 )
 * 
**/
Date::Date(){
	month = 1, day = 1, year = 1970;
}

/*
 *
 * Constructor of date with parameters
 * 
 * @param month must be between 1 and 12 
 * @param day must be between 1 and 31 
 * @param year must be higher than 1970
 * 
**/
Date::Date(const int month,const int day,const int year){
	this->setMonth(month);
	this->setDay(day);
	this->setYear(year);
}

/*
 *
 * @param day must be between 1 and 31 
 * @throws day isn't between 1 and 31
 * 
**/
void Date::setDay(const int day){
	if (day < 1 && day > 31){
		throw std::invalid_argument("Error in method setDay of class Date :\n\nThe day is invalid\n"+getDebugValues());
	}else{
	  this->day = day;
  }
}

/*
 *
 * @param month must be between 1 and 12 
 * @throws month isn't between 1 and 12
 * 
**/
void Date::setMonth(const int month){
	if (month < 1 && month > 12){
		throw std::invalid_argument("Error in method setMonth of class Date :\n\nThe day is invalid\n"+getDebugValues());
  }else{
    this->month = month;
  }
}

/*
 *
 * @param year must be higher than 1970
 * @throws year isn't between 1970
 * 
**/
void Date::setYear(const int year){
	if (year < 1970){
		throw std::invalid_argument("Error in method setYear of class Date :\n\nThe day is invalid\n"+getDebugValues());
	}else{
		this->year = year;
	}
}

/*
 * @return string which contain date values ( month, day, year ) and which is suitable for debugging
 * 
 * Format :
 * 
 * Date{
 * 	Month = 1
 * 	Day = 1
 * 	Year = 1970
 * }
 * 
**/
std::string Date::getDebugValues(){
	return "\nDebug values :\nDate{\n	Month = "+
	std::to_string(this->month)+"\n	Day = "+
	std::to_string(this->day)+"\n	Year = "+
	std::to_string(this->year)+"\n}\n";
}