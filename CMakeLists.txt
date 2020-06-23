cmake_minimum_required(VERSION 3.16)
project(weekly_calendar)

set(CMAKE_CXX_STANDARD 20)

add_executable(weekly_calendar main.cpp Assignment.cpp Assignment.h Date.cpp Date.h AssignmentManager.cpp AssignmentManager.h HashTable.cpp HashTable.h LinkedList.cpp LinkedList.h)