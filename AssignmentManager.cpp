#include "AssignmentManager.h"

AssignmentManager::AssignmentManager() {
  this->assignments = HashTable<Assignment>();
  // TODO change path
  this->logFileName = "../assignments.txt"; // TODO determine better way of storing files. Perhaps in a database?
  this->logEntries = true;
}

bool AssignmentManager::addAssignment(Assignment &entry) {
  int key = this->generateKey(entry);

  assignments.insert(entry, key);

  if(this->logEntries)
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

void AssignmentManager::loadAssignments() {
  std::ifstream inputFile(this->logFileName);
  this->logEntries = false; // Don't add the loaded assignment back to the file!

  while(!inputFile.eof()){
    std::string date, name, details;
    char delimiter = ',';

    try{
      std::getline(inputFile, date, delimiter);
      std::getline(inputFile, name, delimiter);
      std::getline(inputFile, details, '\n');
    }catch(std::stringstream::failure){
      std::cout << "Failed to load assignment" << std::endl;
    }

    Assignment loadedAssignment(name, details, Date(date));
    this->addAssignment(loadedAssignment);
  }

  this->logEntries = true; // start logging subsequent assignment entries
}

int AssignmentManager::getNumberOfEntries() { return this->assignments.getNumberOfEntries();}