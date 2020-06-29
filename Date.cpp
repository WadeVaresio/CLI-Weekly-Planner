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

Date::Date(std::string date){
  std::string dateVals[3];

  std::stringstream ss;
  ss.str(date);

  try{
    for(int i = 0; i <= 2; i++){
      std::getline(ss, dateVals[i], '/');
    }
  }catch(std::stringstream::failure){
    std::cout << "failed to load assignment"; // TODO make error more specific
  }

  this->month = std::stoi(dateVals[0]);
  this->day = std::stoi(dateVals[1]);
  this->year = std::stoi(dateVals[2]);
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