#include <sstream>
#include "Assignment.h"

Assignment::Assignment() {
  this->name = nullptr;
  this->details = nullptr;
}

//TODO make this an initializer list constructor
Assignment::Assignment(std::string name, std::string details, Date dueDate) {
  this->name = std::move(name);
  this->details = std::move(details);
  this->dueDate = dueDate;
}

bool Assignment::operator==(Assignment &compare) const{
  return this->name == compare.name && this->details == compare.details && this->dueDate == compare.dueDate;
}

Date Assignment::getDueDate(){ return this->dueDate; }

std::string Assignment::getDueDateAsString() {
  std::stringstream ss;

  ss << this->dueDate.getMonth() << "/" << this->dueDate.getDay() << "/" << this->dueDate.getYear();

  return ss.str();
}

std::string Assignment::getName(){ return this->name; }

std::string Assignment::getDetails(){ return this->details; }