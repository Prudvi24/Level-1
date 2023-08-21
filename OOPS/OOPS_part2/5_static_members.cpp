#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

A static member is shared by all objects of the class. 
All static data is initialized to zero when the first object is created, if no other initialization is present. 
We can't put it in the class definition but it can be initialized outside the class as done in the following example by redeclaring the static variable,
 using the scope resolution operator :: to identify which class it belongs to.

Accessing the static property is done using :: (scope resolution operator)
E.g : cout<<Student :: totalStudent<<endl;


We need to do initialization of the static property outside the class

int Student :: totalStudent = 0;

*/

class Student{
public:
	int rollNumber;
	int age;
	//int totalStudents // totalStudents should not belong to the object, because a student should not hold totalStudent var.
						// to achieve this we use static members.
	static int total_students;

	Student(){
		total_students++;
	}
};

int Student::total_students = 0;  // Initialization of static data members.

int main(){
	Student s1;
	Student s2,s3,s4,s5,s6;
	cout<<s2.total_students<<endl; // It doesnot raise any error but it is not recommended to use with objects.
	cout<<"Total number of students: "<<Student::total_students<<endl;
	return 0;
}

/*

6
Total number of students: 6

*/