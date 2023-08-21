#include<bits/stdc++.h>
#define endl '\n'

using namespace std

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

int test(int a, int b){

}

int test(int a){

}

int test(){

}

/*
 
void test(){
	
}
we can't a function using return type, hence compiler raises an error
due to ambiguity

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

	/*
		Operator overloding
	*/

	int a = 4+5; //(integer addition)

	float b = 4.5 + 5.6 // (floating addition)

	double c = 5.678+9.99  // double addition
}