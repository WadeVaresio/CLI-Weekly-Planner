#ifndef WEEKLY_CALENDAR_ASSIGNMENT_H
#define WEEKLY_CALENDAR_ASSIGNMENT_H

#include <string>
#include "Date.h"


class Assignment {
public:
  Assignment();
  Assignment(std::string name, std::string details, Date dueDate);

  bool operator==(Assignment&) const;

  Date getDueDate();

private:
  std::string name;
  std::string details;
  Date dueDate;
};

#endif //WEEKLY_CALENDAR_ASSIGNMENT_H
