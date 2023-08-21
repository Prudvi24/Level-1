#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

1. Destructor deallocates the memory. When we create our own desturctor the default destructor is disabled
or not accessible.

2. Destructor is called only once in lifetime of the object, specifically at the end of the object exection.

	Properties of destructor
	1. Same name as our class
	2. No return type
	3. No input argument
*/

class Student{
public:
	int rollNumber;
private:
	int age;

public:
	~ Student(){
		cout<<"Destructor called for the object: "<<this<<endl;
	}

	Student(int age){
		this->age = age;
	}

	Student(int rollNumber, int age){
		this->rollNumber = rollNumber;
		this->age = age;
	}
};

int main(){
	Student s1(100,26);
	cout<<"s1 object: "<<&s1<<endl;
	cout<<"---------------------"<<endl;
	
	Student s2(101,24);
	cout<<"s2 object: "<<&s2<<endl;
	cout<<"---------------------"<<endl;

	Student *s3 = new Student(102,25);        //If we don't the pointer to object explicity the destructor won't called called.
	cout<<"s3 object: "<<s3<<endl;
	cout<<"---------------------"<<endl;

	Student *s4 = new Student(103,23);
	cout<<"s4 object: "<<s4<<endl;
	delete s4;                               // Destructor is called at this point
	cout<<"---------------------"<<endl;	
	return 0;
}

/*
Output:

s1 object: 0x7ffc55a9ee38
---------------------
s2 object: 0x7ffc55a9ee40
---------------------
s3 object: 0x55f3909052c0
---------------------
s4 object: 0x55f3909052e0
Destructor called for the object: 0x55f3909052e0
---------------------
Destructor called for the object: 0x7ffc55a9ee40
Destructor called for the object: 0x7ffc55a9ee38

*/