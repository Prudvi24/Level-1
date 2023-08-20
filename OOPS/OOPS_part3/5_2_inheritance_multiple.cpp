#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

class Teacher{
private:
	int salary;
public:
	string name;
	int age;

	Teacher(){
		cout<<"Teacher default constructor and address is: "<<this<<endl;
	}

	~Teacher(){
		cout<<"Teacher destructor and address is: "<<this<<endl;
	}

	void print(){
		cout<<"Teacher class print"<<endl;
	}
};

class Student{
public:
	int fee;

	Student(){
		cout<<"Student default constructor and address is: "<<this<<endl;
	}

	~Student(){
		cout<<"Student destructor and address is: "<<this<<endl;
	}
	
	void print(){
		cout<<"Student class print "<<endl;
	}
};

class TA : public Teacher, public Student{  // The order in which we defined the parent class
public:										// constructors are called in the same order.
	int subjects;

	TA(){
		cout<<"TA default constructor and address is: "<<this<<endl;
	}

	~TA(){
		cout<<"TA destructor and address is: "<<this<<endl;
	}
};

int main(){
	TA t1;
	/*
		Q)Assume that we don't have print in TA class and If we want to call print function the parent class TA class, 
		which class print will be executed?

		Ans : It raises an error due to the ambiguity. To reslove this we have to specify the class name.
			  
			  Eg: "t1.ClassName::function()"
			  
			  If TA class has print function, it will execute the own class print.

	*/
	t1.Student::print();
	t1.Teacher::print();
	return 0; 
}

/*

Teacher default constructor and address is: 0x7ffe563ebbb0
Student default constructor and address is: 0x7ffe563ebbdc
TA default constructor and address is: 0x7ffe563ebbb0
Student class print 
Teacher class print
TA destructor and address is: 0x7ffe563ebbb0
Student destructor and address is: 0x7ffe563ebbdc
Teacher destructor and address is: 0x7ffe563ebbb0

*/