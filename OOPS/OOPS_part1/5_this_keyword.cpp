#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

"this" is a keyword, it holds the address of the current object

*/

class Student{
public:
	int rollNumber;
private:
	int age;

public:

	Student(){
		cout<<"Default constructor!!"<<endl;
	}

	Student(int rollNumber){
		cout<<"Single paramterized constructor!!"<<endl;
		
		//rollNumber = rollNumber;
		
		/*
		  There is ambiguity in the above statement because the compiler
		  will not understand the value is same as the variable name.

		  To get rid of this we can use Student(Student s1), but it raises an error due to undefined s1 object.
		  Hence s1 is not visible to the constructor

		  To resolve the conflict, we need a variable that holds the current address of object using the class.

		  "this" is keyword used to resolve the issue
		*/

		cout<<"The current address of the object executing is: "<<this<<endl;

		this->rollNumber = rollNumber;
	}

	Student(int rollNumber, int a){
		cout<<"Dual paramterized constructor!!"<<endl;

		//rollNumber = rollNumber;                // Ambiguity again, use "this" keyword to resolve the issue
		//age = age;
		cout<<"The current address of the object executing is: "<<this<<endl;
		this->rollNumber = rollNumber;
		this->age = a;                       // this keyword is optional here because of the name of paramter is different from the class variable
	}
};

int main(){
	Student s1(20);
	cout<<"Address of s1: "<<&s1<<endl;
	cout<<"Roll Number of s1: "<<s1.rollNumber<<endl;

	cout<<"--------------------------------"<<endl;

	Student s2(10,20);
	cout<<"Address of s2: "<<&s2<<endl;
	cout<<"Roll Number of s2: "<<s2.rollNumber<<endl;

	cout<<"--------------------------------"<<endl;

	Student *s3 = new Student(21);
	cout<<"Address of s3: "<<s3<<endl;
	cout<<"Roll Number of s3: "<<s3->rollNumber<<endl;

	return 0;
}


/*
Output looks like
------------------------------------

Single paramterized constructor!!
The current address of the object executing is: 0x7ffd0b239298
Address of s1: 0x7ffd0b239298
Roll Number of s1: 20
--------------------------------
Dual paramterized constructor!!
The current address of the object executing is: 0x7ffd0b2392a0
Address of s2: 0x7ffd0b2392a0
Roll Number of s2: 10
--------------------------------
Single paramterized constructor!!
The current address of the object executing is: 0x559490d6b2c0
Address of s3: 0x559490d6b2c0
Roll Number of s3: 21

*/