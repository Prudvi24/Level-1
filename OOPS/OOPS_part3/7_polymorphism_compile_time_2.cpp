#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*
	Polymorphism means many forms

	Compile time polymorphism : taking decision at compile time
======================================================================

	1. "Function overloading"
	
	2. "Operator overloading"

	3. "Function overriding". This can be achieved using Inheritance.

	Lets say we have a function display() in base class

	We inherit the class in child class but here also we delcare function display().

	It overwrites the function in base class , This is called as "function overriding"

*/

class Vechile{
public:
	int numGears;

	void print(){
		cout<<"Vechile class print"<<endl;
	}
};

class Car : public Vechile{
public:
	string color;

	void print(){
		cout<<"Car class print"<<endl;  // overriding the function from base class 
	}
};

int main(){
	Vechile v;

	Car c;

	v.print();
	c.print();

	cout<<"===================================="<<endl;
	
	Vechile *v1 = new Vechile;

	Vechile *v2;

	v2 = &c;   
	//Base class pointer can point to child class object but vice versa is not allowed

	// v2 can access only the properties present in vechile class

	v1->print();
	v2->print();   // Decision is taking at compile time
	return 0;
}

/*

Vechile class print
Car class print
====================================
Vechile class print
Vechile class print

*/