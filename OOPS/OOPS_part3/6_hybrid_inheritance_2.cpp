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
		
		1. Bus ----> Car --->  Vechile
			|
			|
			 -------> Truck ---> Vechile
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

class Car : virtual public Vechile{
public:
	int numGears;

	Car(){
		cout<<"Car Default constructor and address is: "<<this<<endl;
	}

	~Car(){
		cout<<"Car destructor and address is: "<<this<<endl;
	}
};

class Truck : virtual public Vechile{
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
	/*
		b1 has multiple copies of vechiles
			1. vechile details from car side
			2. vechile details from truck side.

			To remove duplicate or redundancy and resolve the ambiguity to access the print using bus

			By using keyword called "virtual"


			After adding virtual, Bus can directly access the vechile class.
	*/
	//b1.Truck::print();   // printing vechile print from truck side.
	b1.print();
	return 0;
}

/*

Vechile default constructor and address: 0x7ffdcb801670
Car Default constructor and address is: 0x7ffdcb801650
Truck Default constructor and address is: 0x7ffdcb801660
Bus Default constructor and address is: 0x7ffdcb801650
Vechile class print
Bus destructor and address is: 0x7ffdcb801650
Truck destructor and address is: 0x7ffdcb801660
Car destructor and address is: 0x7ffdcb801650
Vechile destructor and address: 0x7ffdcb801670

*/


