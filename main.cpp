//Author: Michael Fu
//Date: 12/19
//this is the main function for linked lists part 2, with add, delete, average, print and quit functions for a database of students, with full name, id and GPA. 
#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

//functions
void ADD(Node* current, Student* newStu, Node* &head);
void PRINT(Node* current, Node* &head);
void DELET(Node* current, int id, Node* &head);
float AVERAGE(Node* current, float aver, int temp);

int main(){
  //create a head node that's null, a current node that helps with the functions and a boolean of whether or not to keep going and a character aray for the input. 
  Node* head = NULL;
  Node* current = head;
  bool justKeepGoing = true;
  char input[20];


  
  while(justKeepGoing == true){
    //output a line just to make it look prettier
    cout << "-------------------------------------------------------------------------" << endl;

    //output what they want to do and store it in input.
    cout << "ADD, PRINT, DELETE, AVERAGE, or QUIT" << endl;
    cin.get(input, 10);
    cin.get();

    if(strcmp(input, "ADD")==0){
      //if they want to add a person, create variables for the first name, last name, ID and GPA, and input. Then input them and store them in the variables. 
      char* name1 = new char[20];
      char* name2 = new char[20];
      int ID;
      float GPA;

      cout << "first name?" << endl;
      cin.get(name1, 20);
      cin.get();

      cout << "last name?" << endl;
      cin.get(name2, 20);
      
      cout << "ID?" << endl;
      cin >> ID;
      cin.clear();
      
      cout << "GPA?" << endl;
      cin >> GPA;
      cin.clear();
      
      //create a student using the variables, and call the ADD function with the student. 
      Student* newStu = new Student(name1, name2, ID, GPA);
      ADD(head, newStu, head);
      cin.ignore();
    } else if(strcmp(input, "PRINT")==0){
      //if the user inputs print, then call the print function. 
      PRINT(head, head);
    } else if(strcmp(input, "DELETE")==0){
      //if the user input delete, create a variable of the ID to delete, and have the user input the ID they want to delete and store it in the variable. 
      int idtodel = 0;
      cout << "what is the ID of the student you want to delete?" << endl;
      cin >> idtodel;
      cin.clear();
      cin.ignore();

      //call the DELET function with the id to delete.
      DELET(head, idtodel, head);
    } else if(strcmp(input, "AVERAGE")==0){
      //if the user input AVERAGE, call the average function and output it. 
      cout << "Average: " << AVERAGE(head, 0.00, 0) << endl;
      cout << endl;
    } else if(strcmp(input, "QUIT")==0){
      //if the user input QUIT, set the justkeepgoing variables to false. 
      justKeepGoing = false;
    } else{
      //otherwise, output that the input wasn't a valid command. 
      cout << "not a valid command" << endl;
    }
    
  }
  
}


void ADD(Node* current, Student* newStu, Node* &head){
  //for the add function, create a temporary node for the new student. 
  Node* temp = new Node(newStu);
  if (head==NULL){
    //if the list is empty, then set head to the temporary node and set the next node to NULL.
    head = temp;
    head->setNext(NULL);
  } else if(newStu->getID() <= current->getStudent()->getID()){
    //if the ID of the student we want to add is less than or equal to the id of the student of the node we're currently on. And because of the other if sdtatements, this one only becomes true if the student we want to add will be the first in the list (head).
    temp->setNext(current);
    head = temp;
    
		  
    //if the next Node is null (end of the list) then set the next Node to temp and the one after that to NULL.
  } else if(current->getNext() == NULL){
    current->setNext(temp);
    current->getNext()->setNext(NULL);

    //if the ID of the next student is more than the ID of the student we want to add, then we set the next node of the current node to the new node. Then the next node of the new one is set to the previous next node. 
    
  } else if(current->getNext()->getStudent()->getID() > newStu->getID()){
    Node* temp = new Node(newStu);
    temp->setNext(current->getNext());
    current->setNext(temp);

    //if none of the previous statements were true, then we need to call ADD function for the next node (recursion) to check again if the student willl be in the right place. 
  } else{
    ADD(current->getNext(), newStu, head);
    
  }

  
}

//for the print function, if head is null, print database empty. Otherwise, if the current value is NULL, print that it's the end of the list. Otherwise, print the student's information and recursively call the print function for the next node. 
void PRINT(Node* current, Node* &head){
  if(head == NULL){
    cout << "Database is empty." << endl;
  } else if(current==NULL){
    cout << "End of database." << endl;
  }
  else{
    current->getStudent()->printStudent();
    PRINT(current->getNext(), head);
  }
}



//for the average function, if the current node is NULL (list is empty) return 0.00
//if the next node is null, call the average function with the next node (which will be null), aver + GPA of the current student, and the number of students plus 1. 
float AVERAGE(Node* current, float aver, int temp){
  cout.setf(ios::fixed, ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(2);
  if(current == NULL){
    return 0.00;
  } else if(current->getNext() != NULL){
    return AVERAGE(current->getNext(), aver+current->getStudent()->getGPA(), temp+1);
  } else {
    //at the very end, return the average plus the current student's GPA, divided by the number of students +1 to account for the current student. 
    return (aver + current->getStudent()->getGPA())/(temp+1);
  }
  
}

//for the delete function, if head is null, return empty database.
//if the current student's id is equal to head's ID and is the one we're looking for, then set head to the node after head.
//if the next node is null (or it's the end of the database) then output that the ID is not found.
//if the id of the next node is equal to the one we want to delete, create atemp equal to the next next node, and set the next node of the current node to the temp. then, delete the unused node.
//otherwise, call the DELET function (recursion) of the next node. 
void DELET(Node* current, int id, Node* &head){
  if(head == NULL){
    cout << "database empty" << endl;
  } else if(current->getStudent()->getID() == head->getStudent()->getID() &&current->getStudent()->getID() == id){
    Node* temp2 = head->getNext();
    head = temp2;
  } else if (current->getNext() == NULL){
    
    cout << "ID not found in database" << endl;
  } else if (current->getNext()->getStudent()->getID() == id){
    Node* temp = current->getNext()->getNext();
    delete (current->getNext());
    current->setNext(temp);
    
  } else {
    DELET(current->getNext(), id, head);
  }
}

