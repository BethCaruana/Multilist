//Node.h

#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS

class Node {
	private:
		int student;
		int classes;
		int grade;
		Node *studentptr;
		Node *classptr;

	public:
		Node();
		Node(int, int);
		~Node();
		int searchStudent(Node*, int);
		int searchClass(Node*, int);
		void insertStudent(Node*, int);
		void insertClass(Node*, int);
		void insertNode(Node*, int, int);
		void insertGrade(Node*,int,int,int);
		void printStudents(Node*)const;
		void printStudentInClass(Node*) const;
		void printClasses(Node*) const;
		void printClassesByStudent(Node*) const;
		void insertRecord(int, int, int);
		void printAll();

};	//end Node class definition

#endif
