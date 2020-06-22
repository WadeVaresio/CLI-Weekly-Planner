#ifndef WEEKLY_CALENDAR_DATE_H
#define WEEKLY_CALENDAR_DATE_H


class Date {
public:
  Date();

  Date(unsigned int year, unsigned int month, unsigned int day);

  unsigned int getYear() const;

  unsigned int getMonth() const;

  unsigned int getDay() const;

  bool operator==(const Date&) const;

private:
  unsigned int year, month, day;
};


#endif //WEEKLY_CALENDAR_DATE_H
