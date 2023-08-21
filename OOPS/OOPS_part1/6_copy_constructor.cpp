#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

When we create an object along with default constructor we get copy constructor as well.

*/

class Student{
public:
	int rollNumber;
private:
	int age;

public:

	Student(){
		//cout<<"Default constructor!!"<<endl;
	}

	Student(int rollNumber){
		//cout<<"Single parameterized constructor!!"<<endl;
		this->rollNumber = rollNumber;
	}

	Student(int rollNumber, int age){
		//cout<<"Dual parameterized constructor!!"<<endl;
		this->rollNumber = rollNumber;
		this->age = age;
	}

	void display(){
		cout<<"Roll Number is: "<<rollNumber<<" and age is: "<<age<<endl;
	}
};

int main(){
	cout<<"Details of student s1"<<endl;
	Student s1(100,23);
	s1.display();
	cout<<"-------------------------------"<<endl<<endl;
	cout<<"Copied detials from s1 to s2 student"<<endl;
	Student s2(s1);

	/*
		the above statement internally execute the following lines

		s2.rollNumber = s1.rollNumber
		s2.age = s1.age
	*/

	s2.display();
	cout<<"-------------------------------"<<endl<<endl;

	cout<<"Details of student s1"<<endl;
	Student *s3 = new Student(101,24);
	s3->display();

	cout<<"-------------------------------"<<endl<<endl;
	cout<<"Copied detials from s3 to s4 student"<<endl;
	Student *s4 = new Student(*s3);   // we can't pass s3 directly because s3 is a reference, but we have pass the block
	s4->display();

	cout<<"-------------------------------"<<endl<<endl;
	cout<<"Copied detials from s3 to s5 student"<<endl;
	Student s5(*s3);
	s5.display();
	return 0;
}

/*

Details of student s1
Roll Number is: 100 and age is: 23
-------------------------------

Copied detials from s1 to s2 student
Roll Number is: 100 and age is: 23
-------------------------------

Details of student s1
Roll Number is: 101 and age is: 24
-------------------------------

Copied detials from s3 to s4 student
Roll Number is: 101 and age is: 24
-------------------------------

Copied detials from s3 to s5 student
Roll Number is: 101 and age is: 24

*/