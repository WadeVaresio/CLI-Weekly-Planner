#include "AssignmentManager.h"

AssignmentManager::AssignmentManager() {
  this->entries = 0;
  this->assignments = HashTable<Assignment>();
  // TODO change path
  this->logFileName = "../assignments.txt"; // TODO determine better way of storing files. Perhaps in a database?
}

bool AssignmentManager::addAssignment(Assignment &entry) {
  int key = this->generateKey(entry);

  assignments.insert(entry, key);

  this->writeAssignmentToFile(entry);

  return true;
}

int AssignmentManager::generateKey(Assignment &assignment) {
  Date dueDate = assignment.getDueDate();

  return (int) ((dueDate.getYear() / 2) - dueDate.getMonth() - dueDate.getDay());
}

bool AssignmentManager::writeAssignmentToFile(Assignment &assignment) {
  std::ofstream logFile(this->logFileName, std::ios::app); // open log file in append mode

  if(!logFile.is_open())
    return false;

  logFile << assignment.getDueDateAsString() << "," << assignment.getName() << "," << assignment.getDetails() << std::endl;

  logFile.close();

  return true;
}
