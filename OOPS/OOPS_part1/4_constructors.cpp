#include<bits/stdc++.h>
#define endl '\n'

/*

We will see the internal working when we define "Student s1"
1. It will internally call s1.Student().
2. The above function name is same as class name and function intializes the properties
   to the garbage value.
3. It is called as constructor, also called as default constructor.

Properties of default constructor
1. Same name as class
2. No return type
3. No input argumenet

---------------------------------------------------------------

Q) When we dynamically create an object, how the default constructor is called?

Ans : For every object the constructor is called only once.
	  Student *s1 = new Student

	  Internally it is called like (*s1).Student() or s1->Student()

------------------------------------------------------------------

When we create our own constructor then the built in constructor will not be available.

*/

using namespace std;

class Student{
public:
	int rollNumber;
private:
	int age;

public:
	Student(){
		cout<<"This is default constructor"<<endl;
	}

	// parameterized constructor
	Student(int r){
		cout<<"Paramterized 1 constructor called"<<endl;
		rollNumber = r;
	}

	Student(int a, int r){
		cout<<"Paramterized 2 constructor called"<<endl;
		age = a;
		rollNumber = r;
	}

	/*
		If there is no matching constructor, then compiler raises an error.
	*/
};

int main(){
	Student s1;  // Default constructor is called

	Student s2(20); // Single paramtereized constructor is called

	Student s3(20,25); // Dual paramaterized constructor is called

	// Dynamically created object

	Student *s4 = new Student;

	Student *s5 = new Student(31);

	Student *s6 = new Student(32,23);
	return 0;
}