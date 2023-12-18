
#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

void ADD(Node* current, Student* newStu, Node* &head);
void PRINT(Node* current, Node* &head);
void DELET(Node* current, int id, Node* &head);
float AVERAGE(Node* current, float aver, int temp);

int main(){
  Node* head = NULL;
  Node* current = head;
  bool justKeepGoing = true;
  char inpt[20];


  
  while(justKeepGoing == true){
    cout << "ADD, PRINT, DELETE, AVERAGE, or QUIT" << endl;
    cin.get(input, 10);
    cin.get();

    if(strcpy(input, "ADD")==0){
      char* name1 = new char[20];
      char* name2 = new char[20];
      int ID;
      float GPA;

      cout << "first name?" << endl;
      cin.get(name1, 20);
      cin.get();

      cout << "last name?" << endl;
      cin.get(name2, 20);
      cin.get();

      cout << "ID?" << endl;
      cin >> ID;

      cout << "GPA?" << endl;
      cin >> GPA;

      
	
    }
  }
  /*
  char* name1 = new char[20];
  char* name2 = new char[20];
  int ID;
  float GPA;

  strcpy(name1, "Michael");
  strcpy(name2, "Fu");
  ID = 453117;
  GPA = 4.1333;

  Student* stud1 = new Student(name1, name2, ID, GPA);
  //stud1->printStudent();

  strcpy(name1, "Nikaansh");
  strcpy(name2, "Singh");
  ID = 123456;
  GPA = 0.531;

  Student* stud2 = new Student(name1, name2, ID, GPA);
  //stud2->printStudent();

  strcpy(name1, "Bob");
  strcpy(name2, "Biskington");
  ID = 234567;
  GPA = 1.565;

  Student* stud3 = new Student(name1, name2, ID, GPA);

  strcpy(name1, "a");
  strcpy(name2, "b");
  ID = 200000;
  GPA = 0.5;

  Student* stud4 = new Student(name1, name2, ID, GPA);
  
  ADD(head, stud1, head);
  ADD(head, stud2, head);
  ADD(head, stud3, head);
  ADD(head, stud4, head);

  //Node* head = new Node(stud1);
  //head->getStudent()->printStudent();

  //Node* second = new Node(stud2);
  //head->setNext(second);
  //head->getNext()->getStudent()->printStudent();

  //second->setNext(NULL);

  PRINT(head, head);
  cout << "before delet" << endl;
  DELET(head, 453117, head);
  cout << "a" << endl;
  PRINT(head, head);
  cout << "b" << endl;
  DELET(head, 123456, head);
  cout << "after delet" << endl;
  PRINT(head, head);

  DELET(head, 200000, head);
  DELET(head, 19375136, head);
  DELET(head, 234567, head);
  DELET(head, 123456, head);
  cout << "test" << endl;
  PRINT(head, head);
  */
}


void ADD(Node* current, Student* newStu, Node* &head){
  Node* temp = new Node(newStu);
  if (head==NULL){
    head = temp;
    head->setNext(NULL);
  } else if(newStu->getID() <= current->getStudent()->getID()){
    temp->setNext(current);
    head = temp;
    
		  
  
  } else if(current->getNext() == NULL){
    current->setNext(temp);
    current->getNext()->setNext(NULL);
  } else if(current->getNext()->getStudent()->getID() > newStu->getID()){
    Node* temp = new Node(newStu);
    temp->setNext(current->getNext());
    current->setNext(temp);

  
  } else{
    ADD(current->getNext(), newStu, head);
    
  }

  
}


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




float AVERAGE(Node* current, float aver, int temp){
  if(current == NULL){
    return 0.00;
  } else if(current->getNext() != NULL){
    return AVERAGE(current->getNext(), aver+current->getStudent()->getGPA(), temp+1);
  } else {
    return (aver + current->getStudent()->getGPA())/(temp+1);
  }
  
}

void DELET(Node* current, int id, Node* &head){
  if(head == NULL){
    cout << "database empty" << endl;
  } else if(current->getStudent()->getID() == head->getStudent()->getID() && current->getStudent()->getID() == id){
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

/*
void DELET(Node* current, int id, Node* &head){
  if(current == NULL){
    cout << "end of database" << endl;
  } else if(head->getStudent()->getID() == id && head->getNext() != NULL){
    cout << "bd" << endl;
    Node* temp = head->getNext();
    delete head;
    head = temp;
  } else if(head->getStudent()->getID() == id && head->getNext()==NULL){
    cout << "ab" << endl;
    delete head;
    head = NULL;
  } else if(current->getStudent()->getID() == id){
    cout << "gb" << endl;
    delete current;
    head = NULL;
    
  } else if(current->getNext() == NULL){
    cout << "Student with given ID not found" << endl;
  } else {
    cout << "bad" << endl;
    current->getNext()->getStudent()->printStudent();
    DELET(current->getNext(), id, head);
    return;
  }
}
*/