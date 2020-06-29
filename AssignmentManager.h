#ifndef WEEKLY_CALENDAR_ASSIGNMENTMANAGER_H
#define WEEKLY_CALENDAR_ASSIGNMENTMANAGER_H

#include "HashTable.h"
#include "Assignment.h"
#include <fstream>

class AssignmentManager {
public:
  AssignmentManager();

  int getNumEntries();

  bool addAssignment(Assignment&);

  int generateKey(Assignment&);

  bool writeAssignmentToFile(Assignment&);

  void loadAssignments();

private:
  int entries;
  HashTable<Assignment> assignments;
  std::string logFileName;
};

#endif //WEEKLY_CALENDAR_ASSIGNMENTMANAGER_H
