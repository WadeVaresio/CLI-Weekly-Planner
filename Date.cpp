#include "Date.h"

Date::Date(){
  this->year = 0;
  this->month = 0;
  this->day = 0;
}

Date::Date(unsigned int year, unsigned int month, unsigned int day){
  this->year = year;
  this->month = month;
  this->day = day;
}

unsigned int Date::getYear() const { return this->year;}

unsigned int Date::getMonth() const { return this->month;}

unsigned int Date::getDay() const { return this->day;}

bool operator<=(const Date& leftDate, const Date& rightDate){
  return !(leftDate.getYear() > rightDate.getYear() || leftDate.getMonth() > rightDate.getMonth() || leftDate.getDay() > rightDate.getDay());
}

bool Date::operator==(const Date& compare) const{
  return this->getYear() == compare.getYear() && this->getMonth() == compare.getMonth() && this->getDay() == compare.getDay();
}