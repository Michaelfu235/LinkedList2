#include "student.h"
#include "node.h"
#include <iostream>

using namespace std;

Student::Student(char* firstname, char* lastname, int id, float gpa){
  fName = new char[20];
  strcpy(fName, firstname);
  lName = new char[20];
  strcpy(lName, lastname);

  ID = id;
  GPA = gpa;
}

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

void Student::printStudent(){
  cout << "First name: " << fName << endl;
  cout << "Last name: " << lName << endl;
  cout << "ID: " << ID << endl;
  cout << "GPA: "  << GPA << endl;
  cout << endl;
}
