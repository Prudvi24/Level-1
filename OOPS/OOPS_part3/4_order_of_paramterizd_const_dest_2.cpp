#include<bits/stdc++.h>
#define endl '\n'

using namespace std;


/*
	Vechile --> Car
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
};

class Car : public Vechile{
public:
	int numGears;

	Car(int x) : Vechile(x){
		cout<<"Car vec param const and address is: "<<this<<endl;
	}

	Car(){
		cout<<"Car Default constructor and address is: "<<this<<endl;
	}

	~Car(){
		cout<<"Car destructor and address is: "<<this<<endl;
	}
};

int main(){
	Vechile v1;
	v1.numTyres = 4;

	Car c1(100);
	return 0;
}

/*

Vechile default constructor and address: 0x7ffe727b20e0
Paramertized constructor called with maxSpeed 100 and address: 0x7ffe727b2110
Car vec param const and address is: 0x7ffe727b2110
Car destructor and address is: 0x7ffe727b2110
Vechile destructor and address: 0x7ffe727b2110

*/