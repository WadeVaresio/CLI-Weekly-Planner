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