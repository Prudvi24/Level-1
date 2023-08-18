#include<bits/stdc++.h>
#define endl '\n'

using namespace std;


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

/*

After creating if we want to copy s1 properties to s2.

Now we cant call copy constructor because constructor is called when the object is created

*/

int main(){
	cout<<"Details of student s1"<<endl;
	Student s1(100,23);
	s1.display();
	cout<<"-------------------------------"<<endl<<endl;
	cout<<"Copied detials from s1 to s2 student using copy assignment operartor"<<endl;
	Student s2;

	s2 = s1;

	/*

	s2 = s1 executes the following statements

	s2.rollNumber = s1.rollNumber

	s2.age = s1.age

	*/

	s2.display();
	cout<<"-------------------------------"<<endl<<endl;

	cout<<"Details of student s1"<<endl;
	Student *s3 = new Student(101,24);
	s3->display();

	cout<<"-------------------------------"<<endl<<endl;
	cout<<"Copied detials from s3 to s4 student using copy assignment operartor"<<endl;
	Student *s4 = new Student;

	*s4 = *s3;

	s4->display();

	cout<<"-------------------------------"<<endl<<endl;
	cout<<"Copied detials from s3 to s5 student using copy assignment operartor"<<endl;
	Student s5;

	s5 = *s3;

	s5.display();
	return 0;
}

/*

Details of student s1
Roll Number is: 100 and age is: 23
-------------------------------

Copied detials from s1 to s2 student using copy assignment operartor
Roll Number is: 100 and age is: 23
-------------------------------

Details of student s1
Roll Number is: 101 and age is: 24
-------------------------------

Copied detials from s3 to s4 student using copy assignment operartor
Roll Number is: 101 and age is: 24
-------------------------------

Copied detials from s3 to s5 student using copy assignment operartor
Roll Number is: 101 and age is: 24

*/