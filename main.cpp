#include <iostream>
#include "Assignment.h"
#include "Date.h"
#include "AssignmentManager.h"

Assignment parseAssignment();

int main() {
  AssignmentManager manager;

  manager.loadAssignments(); // load any saved assignments

  int selection = 0;
  std::cout << "CLI Homework Assignment Manager" << std::endl;
  std::cout << "Select an option: \n1: Add Assignment \n2: Quit" << std::endl;
  std::cin >> selection;

  // TODO convert hard coded numbers into external definitions header file
  while(selection != 2){
    switch(selection){
      case 1: {
        Assignment a = parseAssignment();
        manager.addAssignment(a);
        break;
      }

      default:
        break;
    }

    std::cout << "Select an option: \n1: Add Assignment \n2: Quit" << std::endl;
    std::cin >> selection;
  }

  return 0;
}


Assignment parseAssignment(){
  std::string assignmentName, assignmentDetails;
  unsigned int year, month, day;

  std::cout << "Enter Due Date (Month, Day, Year): ";
  std::cin >> month;
  std::cin >> day;
  std::cin >> year;

  std::cout << "Enter Assignment Name: ";
  std::cin.ignore();
  std::getline(std::cin, assignmentName);

  std::cout << "Enter Assignment Details: ";
  std::cin.ignore();
  std::getline(std::cin, assignmentDetails);

  return Assignment(assignmentName, assignmentDetails, Date(year, month, day));
}