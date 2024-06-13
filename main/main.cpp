//main.cpp

#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(){
	//create new node to start multilist
	Node n = Node();

	//number of entries
	int num = 10;

	//define variables to hold read lines
	std::string text;
	std::string Tempstudent;
	std::string Tempclasses;
	std::string Tempgrade;
	int student;
	int classes;
	int grade;
	std::stringstream converter;

	//open file multilist_input.txt
	std::ifstream inFile;
	inFile.open("multilist_input.txt");

	//for loop to go through each new entry
	for(int i=0; i<num; i++){
		//read each line of the file
		getline(inFile, text);
		//define stringstream
		std::stringstream ss;
		ss.clear();
		//load stringstream with a line of the file
		ss.str(text);
		//read the student and convert to int
		getline(ss, Tempstudent, ',');
		converter.clear();
		converter << Tempstudent;
		converter >> student;
		//read the class and convert to int
		getline(ss, Tempclasses, ',');
		converter.clear();
		converter << Tempclasses;
		converter >> classes;
		//read the grade and convert to int
		getline(ss, Tempgrade);
		converter.clear();
		converter << Tempgrade;
		converter >> grade;
		//insert the new record
		n.insertRecord(student, classes, grade);
	}

	//print results
	n.printAll();

	//close the file
	inFile.close();


}//end main
