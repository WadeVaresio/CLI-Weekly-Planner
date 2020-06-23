#ifndef WEEKLY_CALENDAR_ASSIGNMENTMANAGER_H
#define WEEKLY_CALENDAR_ASSIGNMENTMANAGER_H

#include "HashTable.h"
#include "Assignment.h"

class AssignmentManager {
public:
  AssignmentManager();

  int getNumEntries();

  bool addAssignment(Assignment&);

  int generateKey(Assignment&);


private:
  int entries;
  HashTable<Assignment> assignments;
};

#endif //WEEKLY_CALENDAR_ASSIGNMENTMANAGER_H
