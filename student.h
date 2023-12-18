#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student{
 public:
  Student(char* firstname, char* lastname, int id, float gpa);

  char* fName;
  char* lName;
  int ID;
  float GPA;
  
  char* getFirstName();
  char* getSecondName();
  int getID();
  float getGPA();
  void printStudent();
};
#endif
