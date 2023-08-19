#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

It should be always noted that "inbuilt copy constructor uses shallow copy"

*/

class Student{
private:
	int age;
public:
	char *name;

	Student(int age, char *name){
		this->age = age;
		this->name = name;
	}

	void display(){
		cout<<"Name is: "<<this->name<<" and Age is: "<<this->age<<endl;
	}

/*
	Student(Student s){  //copy constructor
		this->age = s.age;
		//this->name = s.name   // shallow copy

		//Deep copy
		this->name = new char[strlen(s.name)+1];
		strcpy(this->name,s.name);
	}
*/

/*
	In the above defined copy constructor. we have defined deep copy in the copy constructor.

	Let's see the major problem over here

	Student(Student s)    ==>  we know that when it is called, the "paramter Student s" internally copies the main.s

							   Student s = main.s  ------------> copy assignment operator while initalizing Student s

							   Student s(main.s)   ------------> copy constructor is called

							   Now the problem arises

=========================================================================================================================

							   We have defined our own copy constructor, the default copy constructor will disbaled.

							   Our parameter will call the same copy constructor and our copy constructor will the same parameter again and again.

							   Resulting in infinte loop and deadlock. (Shown in the below diagram)


								-------------
								-           -
							    -		   	-
							    -		   \-/
							   Student(Student s)
							    /-\        -
								 -         -
								 -         -
								 -----------

								 To resolve this issue pass the argument by reference

								 "Student(const Student &s)"
*/


	Student(const Student &s){
		this->age = s.age;
		// this->name = s.name;   //shallow copy

		this->name = new char[strlen(s.name)+1];
		strcpy(this->name,s.name);
	}
};

int main(){
	char name[] = "abcd";
	cout<<"Details of s1"<<endl;
	Student s1(23, name);
	s1.display();
	
	cout<<"--------------------"<<endl<<endl;
	cout<<"Details of s1 copied to s2 using copy constructor"<<endl;
	Student s2(s1);
	s2.display();

	cout<<"changed the first character in name in s2 object to 'x' "<<endl;
	s2.name[0]='x';

	cout<<"--------------------"<<endl<<endl;
	cout<<"Details of s1 again: "<<endl;
	s1.display();	

	cout<<"--------------------"<<endl<<endl;
	cout<<"Details of s2 again: "<<endl;
	s2.display();	

	return 0;
}


/*

Output of default copy constructor (using shallow copy)
=======================================================

Details of s1
Name is: abcd and Age is: 23
--------------------

Details of s1 copied to s2 using copy constructor
Name is: abcd and Age is: 23
changed the first character in name in s2 object to 'x' 
--------------------

Details of s1 again: 
Name is: xbcd and Age is: 23
--------------------

Details of s2 again: 
Name is: xbcd and Age is: 23


Output of defined copy constructor (using deep copy)
=======================================================

Details of s1
Name is: abcd and Age is: 23
--------------------

Details of s1 copied to s2 using copy constructor
Name is: abcd and Age is: 23
changed the first character in name in s2 object to 'x' 
--------------------

Details of s1 again: 
Name is: abcd and Age is: 23
--------------------

Details of s2 again: 
Name is: xbcd and Age is: 23

*/