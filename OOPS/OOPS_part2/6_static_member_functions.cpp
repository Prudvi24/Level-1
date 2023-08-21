#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

Functions in the class can also be static

If we want to retrieve total number students present in the class by a function.
we must use static functions

Most important points
=========================
1. Static functions can only acess the static members.
2. Static properties doesn't have this variable.

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

	static int getTotalStudents(){
		return total_students;
	}
};

int Student::total_students = 0;  // Initialization of static data members.

int main(){
	Student s1;
	Student s2,s3,s4,s5,s6;
	//cout<<s2.total_students<<endl; // It doesnot raise any error but it is not recommended to use with objects.
	//cout<<"Total number of students: "<<Student::total_students<<endl;

	cout<<"Total number of students in the class: "<<Student::getTotalStudents()<<endl;
	return 0;
}

/*
Total number of students in the class: 6
*/