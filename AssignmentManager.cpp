#include "AssignmentManager.h"

AssignmentManager::AssignmentManager() {
  this->entries = 0;
  this->assignments = HashTable<Assignment>();
}

bool AssignmentManager::addAssignment(Assignment &entry) {
  int key = this->generateKey(entry);

  assignments.insert(entry, key);
  return true;
}

int AssignmentManager::generateKey(Assignment &assignment) {
  Date dueDate = assignment.getDueDate();

  return (int) ((dueDate.getYear() / 2) - dueDate.getMonth() - dueDate.getDay());
}
