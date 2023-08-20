#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*
	Daimond probelm

			Vechile
		      /\
		     /  \ 
		    /    \
		   /      \
		  /        \
		 Car      Truck
		  \         /
		   \       /
			\     /
			 \   /
			  \ /
			  Bus

In this program we will see the constructor calling and execution
In the above diagram, the constructors are called in the below way
		
		1. Bus ----> Car --->  Vechile
			|
			|
			 -------> Truck ---> Vechile

			1st Vechile constructor is called from Car side
			2nd Car constructor is called
			3rd Vechile constructor called from Truck side
			4th Truck constructor called
			5th Bus constructor called

			6th Bus destructor called
			7th Truck destructor called
			8th Vechile destructor called from Truck side
			9th Car destructor called
			10th Vechile destructor called from Car side.
*/

class Vechile{
private:
	int maxSpeed;
protected:
	string color;
public:
	int numTyres;

	Vechile(){
		cout<<"Vechile default constructor and address: "<<this<<endl;
	}

	~Vechile(){
		cout<<"Vechile destructor and address: "<<this<<endl;
	}

	Vechile(int maxSpeed){
		cout<<"Paramertized constructor called with maxSpeed "<<maxSpeed<<" and address: "<<this<<endl;
		this->maxSpeed = maxSpeed;
		this->color = "Black";
		this->numTyres = 4;
	}

	void print(){
		cout<<"Vechile class print"<<endl;
	}
};

class Car : public Vechile{
public:
	int numGears;

	Car(){
		cout<<"Car Default constructor and address is: "<<this<<endl;
	}

	~Car(){
		cout<<"Car destructor and address is: "<<this<<endl;
	}
};

class Truck : public Vechile{
public:
	int numTankers;

	Truck(){
		cout<<"Truck Default constructor and address is: "<<this<<endl;
	}

	~Truck(){
		cout<<"Truck destructor and address is: "<<this<<endl;
	}
};

class Bus : public Car, public Truck{
public:
	int numSeats;

	Bus(){
		cout<<"Bus Default constructor and address is: "<<this<<endl;
	}

	~Bus(){
		cout<<"Bus destructor and address is: "<<this<<endl;
	}
};

int main(){
	Bus b1;
	return 0;
}

/*

Vechile default constructor and address: 0x7ffd3cd6b180
Car Default constructor and address is: 0x7ffd3cd6b180
Vechile default constructor and address: 0x7ffd3cd6b1b0
Truck Default constructor and address is: 0x7ffd3cd6b1b0
Bus Default constructor and address is: 0x7ffd3cd6b180
Bus destructor and address is: 0x7ffd3cd6b180
Truck destructor and address is: 0x7ffd3cd6b1b0
Vechile destructor and address: 0x7ffd3cd6b1b0
Car destructor and address is: 0x7ffd3cd6b180
Vechile destructor and address: 0x7ffd3cd6b180

*/


