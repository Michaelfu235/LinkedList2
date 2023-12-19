//using the code of: Nick Braun
//12/5/2023
//Linked List Part 1
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

class Node {
 public:
  Node(Student*); //Constructor
  ~Node(); //Deconstructor
  Node* getNext(); //Gets next node pointer
  void setNext(Node* newnext); //Sets the next pointer to the corresponding node pointer
  Student* getStudent(); //Get student pointer
 private:
  Student* student;
  Node* next;
};
#endif
