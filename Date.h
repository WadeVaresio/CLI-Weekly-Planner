#ifndef WEEKLY_CALENDAR_DATE_H
#define WEEKLY_CALENDAR_DATE_H

#include <iostream>
#include <string>
#include <sstream>

class Date {
public:
  Date();

  Date(unsigned int year, unsigned int month, unsigned int day);

  Date(std::string);

  unsigned int getYear() const;

  unsigned int getMonth() const;

  unsigned int getDay() const;

  bool operator==(const Date&) const;

private:
  unsigned int year, month, day;
};


#endif //WEEKLY_CALENDAR_DATE_H
