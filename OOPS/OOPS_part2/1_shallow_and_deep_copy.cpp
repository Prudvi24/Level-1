#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

class Student{
public:
	int age;
	char *name;

public:
	Student(int age, char *name){
		this->age = age;
		//this->name = name;  // Shallow copy

		//Deep copy
		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
	}

	void display(){
		cout<<"Name: "<<this->name<<" and age: "<<this->age<<endl;
	}
};

int main(){
	char name[] = "marcin";
	Student s1(20,name);
	cout<<"student s1 details: "<<endl;
	s1.display();
	cout<<"---------------------"<<endl;
	name[2] = 'g';
	Student s2(22, name);
	cout<<"student s2 details: "<<endl;
	s2.display();
	cout<<"---------------------"<<endl;
	cout<<"Again student s1 details: "<<endl;   
	s1.display();                       // It prints magcin even with s1 object, this is because of shallow copy 

	/*

	There is change in the output when we print s1 details for the second time.

	Because the student s1 and s2 objects are pointing to the same character array.

	Rather than copying entire array for each object it took the address of that array and copied the address of arr.

	This is  called "shallow copying".


	To avoid this issue of shallow copying, we use a technique called "deep copy"

	In deep copy instead of copying the location, we copy enitre array to new array
	*/


	return 0;
}

/*

Output of shallow copy
===============================

student s1 details: 
Name: marcin and age: 20
---------------------
student s2 details: 
Name: magcin and age: 22
---------------------
Again student s1 details: 
Name: magcin and age: 20


Output of deep copy
===============================

student s1 details: 
Name: marcin and age: 20
---------------------
student s2 details: 
Name: magcin and age: 22
---------------------
Again student s1 details: 
Name: marcin and age: 20

*/