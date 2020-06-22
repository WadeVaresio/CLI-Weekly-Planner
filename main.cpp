#include <iostream>
#include "Assignment.h"
#include "HashTable.h"
#include "Date.h"

void parseAssignment();

int main() {
  Date testDate = Date();
  Assignment testAssignment = Assignment("test", "test", testDate);
  Assignment test2 = Assignment("test2", "foo bar", testDate);

  HashTable<Assignment> ht;
  ht.insert(testAssignment,1);
  ht.insert(test2, 1);

  bool b = ht.search(testAssignment, 1);

//  int selection;
//  std::cout << "CLI Homework Assignment Manager" << std::endl;
//  std::cout << "Select an option: \n1: Add Assignment \n2: Quit" << std::endl;
//  std::cin >> selection;
//
//  while(selection != 2){
//    switch(selection){
//      case 1:
//        parseAssignment();
//        break;
//      default:
//        break;
//
//    }
//
//    std::cin >> selection;
//  }

  return 0;
}


void parseAssignment(){
  std::string assignmentName, assignmentDetails;
  unsigned int year, month, day;

  std::cout << "Enter Due Date: ";
  std::cin >> month;
  std::cin >> day;
  std::cin >> year;

  std::cout << "Enter Assignment Name: ";
  std::cin >> assignmentName;

  std::cout << "Enter Assignment Details: ";
  std::cin >> assignmentDetails;

  Assignment newAssignment(assignmentName, assignmentDetails, Date(year, month, day));
}