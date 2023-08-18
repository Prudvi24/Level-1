/*

Here we discuss how to access the private variables.

We also discuss how to set and get the private variables using setters and getters respectively.

Create a student class with roll number as public variable and age as private variable.

Also provide security to the age variable, make sure only authorized persons access and set the age.

*/
#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

class Student{
public:
	int rollNumber;
private:
	int age;

public:
	void setAge(int a, int password){
		if(password!=123){
			cout<<"Check the password before setting the age"<<endl;
			return ;
		}
		else if(a<0){
			cout<<"Age cannot be negative"<<endl;
		}
		else{
			age = a;
		}
	}

	int getAge(){
		return age;
	}

	void display(){
		cout<<"Roll number = "<<rollNumber<<" and Age = "<<age<<endl;
	}
};

int main(){
	Student s1;
	s1.rollNumber = 11;
	s1.setAge(24,123);

	Student s2;
	s2.rollNumber = 12;
	s2.setAge(25,124);

	Student *s3 = new Student;
	s3->rollNumber = 13;
	s3->setAge(22,123);

	// get details of s1
	cout<<"Details of student s1"<<endl;
	s1.display();

	// get details of s2 
	cout<<"Details of student s2"<<endl;
	s2.display();// For student s2, we entered wrong password, so the age will be set to a garbage value

	// get details of s3
	cout<<"Details of student s3"<<endl;
	s3->display();


	cout<<"Age of student s1 is "<<s1.getAge()<<", s2 is "<<s2.getAge()<<", and s3 is "<<s3->getAge()<<endl;
	return 0;
}


/*

Output looks like
-------------------------------------------
Check the password before setting the age
Details of student s1
Roll number = 11 and Age = 24
Details of student s2
Roll number = 12 and Age = 0
Details of student s3
Roll number = 13 and Age = 22
Age of student s1 is 24, s2 is 0, and s3 is 22

*/