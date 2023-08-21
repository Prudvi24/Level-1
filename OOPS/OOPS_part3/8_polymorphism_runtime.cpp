#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*
	Polymorphism means many forms

	Runtime polymorphism : taking decisions at run time.

	To achieve runtime polymorphism we have to use "virtual functions"

	Virtual functions are those function which are present in a base class and they are overridden in child class

	If the child class doesn't have function, then it will print parent class function.
*/

class Vechile{
public:
	int numGears;

	virtual void print(){
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
	
	v1->print();
	v2->print();   
	return 0;
}

/*

Vechile class print
Car class print
====================================
Vechile class print
Car class print

*/