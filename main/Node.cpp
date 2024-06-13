//Node.cpp

#include "Node.h"
#include <iostream>

//define global variables
Node *t;
Node *stp;
Node *head = new Node(0, 0);
bool found;
bool found2;

//Default Constructor
Node::Node(){
	this->student = 0;
	this->classes = 0;
	this->grade = 0;
	this->studentptr = nullptr;
	this->classptr = nullptr;
}

//Initializing Constructor
Node::Node(int student, int classes){
	this->student = student;
	this->classes = classes;
	this->studentptr = nullptr;
	this->classptr = nullptr;
}

//Destructor
Node::~Node(){
	delete studentptr;
	delete classptr;	
}

//Search student
int Node::searchStudent(Node *t, int student){
	//move through each student
	while(t->studentptr != nullptr){
		t = t->studentptr;
		//if student exists return 0
		if(t->student == student){
			return 0;
		}
	}
	//student does not exist
	return -1;
}

//Search class
int Node::searchClass(Node *t, int classes){
	//move through each class
	while(t->classptr != NULL){
		t = t->classptr;
		//if class exists return 0
		if(t->classes == classes){
			return 0;
		}
	}
	//class does not exist
	return -1;
}

//Insert Student
void Node::insertStudent(Node *t, int student){
	//go to the end of the students
	while(t->studentptr != NULL){
		t = t->studentptr;
	}
	//last student now points to new node
	t->studentptr = new Node(student, 0);
}

//Insert Class
void Node::insertClass(Node *t, int classes){
	//go to the end of the classes
	while(t->classptr != NULL){
		t = t->classptr;
	}
	//last class now points to new node
	t->classptr = new Node(0, classes);
}

//Insert node
void Node::insertNode(Node *t, int student, int classes){
	//create new Node, store address in stp
	t = head;
	stp = new Node(student, classes);
	//search for the new student
	while(t->studentptr != nullptr){
                t = t->studentptr;
                if(t->student == student){
                        break;
                }
        }
	//search for class of the student
	while(t->classptr != NULL){
		t = t->classptr;
	}
	//previous class now points to new node
	t->classptr = stp;
	t = head;
	//search for the new class
	while(t->classptr != nullptr){
		t = t->classptr;
		if(t->classes == classes){
			break;
		}
	}
	//search for the student of the class
	while(t->studentptr != NULL){
		t = t->studentptr;
	}
	//previous student now points to new node
	t->studentptr = stp;
}

//Insert Grade
void Node::insertGrade(Node *t,int student,int classes,int grade){
	//search for the student
	while(t->studentptr != nullptr){
		t = t->studentptr;
		if(t->student == student){
			break;
		}
	}
	//search for the class of the student
	while(t->classptr != NULL){
		t = t->classptr;
		if(t->classes == classes){
			break;
		}
	}
	//add the grade to that node
	t->grade = grade;
}

//Print students by class
void Node::printStudents(Node *t) const{
	//print all students of a specific class
	std::cout<<" Students: ";
	while(t->studentptr != NULL){
		t = t->studentptr;
		std::cout<<t->student<<" ";
	}
}

//Print students in class
void Node::printStudentInClass(Node *t) const{
	//go through each class
	while(t->classptr != NULL){
		t = t->classptr;
		//print the class
		std::cout<<"Class: "<<t->classes;
		//print the students in the class
		printStudents(t);
		std::cout<<std::endl;
	}
}

//Print classes for student
void Node::printClasses(Node *t) const{
	//print all classes of a student
	std::cout<<" Classes: ";
	while(t->classptr != NULL){
		t = t->classptr;
		std::cout<<t->classes<<" ";
	}
}

//Print classes by student
void Node::printClassesByStudent(Node *t) const{
	//go through each student
        while(t->studentptr != NULL){
		t = t->studentptr;
		//print the student
		std::cout<<"Student: "<<t->student;
		//print the classes of the student
		printClasses(t);
		std::cout<<std::endl;
	}
}

//New entry
void Node::insertRecord(int student, int classes, int grade){
	t = head;
	//search for student
	found = searchStudent(t, student);
	//if student exists
	if(found == 0){
		//search for their class
		found2 = searchClass(t, classes);
		//if class exists for student
		if(found2 == 0){
			//duplicate
			std::cout<<"Duplicate"<<std::endl;
		}
		//if class does not exist for the student
		else{
			//insert the class
			insertClass(t, classes);
			//insert the new node
			insertNode(t, student, classes);
			//insert grade for the new node
			insertGrade(t, student, classes, grade);
		}
	}
	//if student is not found
	else{
		//insert new student
		insertStudent(t, student);
		//search for the class
		found2 = searchClass(t, classes);
		//if class found
		if(found2 == 0){
			//insert new node
			insertNode(t, student, classes);
			//insert grade for new node
			insertGrade(t, student, classes, grade);
		}
		//if class not found
		else{
			//insert new class
			insertClass(t, classes);
			//insert new Node
			insertNode(t, student, classes);
			//insert grade for new node
			insertGrade(t, student, classes, grade);
		}	
	}

}

//Print All
void Node::printAll(){
	//print student with all their classes
	t = head;
	printClassesByStudent(t);
	std::cout<<std::endl;
	//print the class with all their students
	t = head;
	printStudentInClass(t);
}

