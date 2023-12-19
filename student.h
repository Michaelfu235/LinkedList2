#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student{
 public:
  //constructor
  Student(char* firstname, char* lastname, int id, float gpa);

  //variables
  char* fName;
  char* lName;
  int ID;
  float GPA;

  //functions
  char* getFirstName();
  char* getSecondName();
  int getID();
  float getGPA();
  void printStudent();
};
#endif
