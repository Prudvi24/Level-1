#include<bits/stdc++.h>

using namespace std;

class Student{
public:
	int rollNumber;
	int age;
};

int main(){
	Student s1;
	s1.rollNumber = 100;
	s1.age = 24;

	Student s2;
	s2.rollNumber = 101;
	s2.age = 25;

	Student s3;

	//Dynamically created objects

	Student *s4 = new Student;
	(*s4).rollNumber = 102; 
	(*s4).age = 25;

	Student *s5 = new Student;
	s5->rollNumber = 103;  // '->' dereferencing operator
	s5->age = 24;

	// print s1 details
	cout<<"Details of s1 student"<<endl;
	cout<<"Roll Number of s1 is: "<<s1.rollNumber<<endl;
	cout<<"Age of s1 student is: "<<s1.age<<endl;

	// print s2 details
	cout<<"Details of s2 student"<<endl;
	cout<<"Roll Number of s2 is: "<<s2.rollNumber<<endl;
	cout<<"Age of s1 student is: "<<s2.age<<endl;

	// print s3 details (Since the s3 details are not defined, if we print s3 details it return garbage values)
	cout<<"Details of s3 student"<<endl;
	cout<<"Roll Number of s3 is: "<<s3.rollNumber<<endl;
	cout<<"Age of s3 student is: "<<s3.age<<endl;

	//print	s4 details
	cout<<"Details of s4 student"<<endl;
	cout<<"Roll Number of s4 is: "<<s4->rollNumber<<endl;
	cout<<"Age of s4 student is: "<<s4->age<<endl;
	return 0;
}