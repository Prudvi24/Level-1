#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*
	Pure virtual functions : which have no definition.

	eg : virtual void print() = 0;

	If any class exist with pure virtual function then these type of classes are called abstract class.

	We can not create objects for virtual class. 
*/

class Vechile{
public:
	int numGears;

/*
	// Normal virtual function
	virtual void print(){
		cout<<"Vechile class print"<<endl;
	}
*/

	//pure virtual class
	virtual void print() = 0;    // now Vechile class is an abstract class
};

/*

If car class doesn't implement the pure virtual functions of base class
	1. It will also become an abstract class.
	2. Then we can't create object for car class also.

If we impelment all pure virtual functions
	. Then it is a normal class. 

*/

class Car : public Vechile{
public:
	string color;

	void print(){
		cout<<"Car class print"<<endl;  // overriding the function from base class 
	}
};

int main(){

	Car c1;
	Vechile *v1 = &c1;

	v1->print();   
	return 0;
}

/*

Car class print

*/