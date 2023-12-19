#include "student.h"
#include "node.h"
#include <iostream>

using namespace std;
//constructor
Student::Student(char* firstname, char* lastname, int id, float gpa){
  fName = new char[20];
  strcpy(fName, firstname);
  lName = new char[20];
  strcpy(lName, lastname);

  ID = id;
  GPA = gpa;
}

// functions to return the first name, last name, ID and GPA
char* Student::getFirstName(){
  return fName;
}

char* Student::getSecondName(){
  return lName;
}

int Student::getID(){
  return ID;
}

float Student::getGPA(){
  return GPA;
}

//print all the student information
void Student::printStudent(){
  cout.setf(ios::fixed, ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout << "First name: " << fName << endl;
  cout << "Last name: " << lName << endl;
  cout << "ID: " << ID << endl;
  cout << "GPA: " << GPA << endl;
  cout << endl;
}
