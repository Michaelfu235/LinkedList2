#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

//Constructor 
Node::Node(Student* newStudent) {
  student = newStudent;
  next = NULL;
}

//Destructor
Node::~Node() {
  delete student;
  next = NULL;
}

//Gets the next student pointer
Node* Node::getNext() {
  return next;
}

//Sets the pointer to the next student
void Node::setNext(Node* newnext) {
  next = newnext;
}

//Gets the student
Student* Node::getStudent() {
  return student;
}
