#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*
We must always takecare of assigning constant and reference variables
when we declare.

It can't be resolved using constructors because before going into constructor
the memoery for constant and reference variables are already created and allocated
with gargbage values.

In classes, it can be resolved using "Initialization list"

Initialization list assign values to constants and reference variable at the time of delcaration.

It not only initializes the constants, references, but also normal variables.

*/

class Student{
public: 
	int age;
	const int rollNumber;
	int &x; //age reference variable

/*
	Student(int r, int a,...<any numbers of arguments>):datamember(){

	}
*/
	Student(int r, int age) : rollNumber(r), age(age), x(this->age){    // Initialization list
		cout<<"Paramterized constructor"<<endl;
	}

	void display(){
		cout<<"Address of age: "<<&age<<" address of x (ref to age): "<<&x<<endl;
		cout<<"Roll number: "<<rollNumber<<" and age: "<<age<<endl;
	}
};

int main(){
	Student s1(101,24);
	s1.display();	
	return 0;
}

/*

Paramterized constructor
Address of age: 0x7ffd4c0d0920 address of x (ref to age): 0x7ffd4c0d0920
Roll number: 101 and age: 24

*/