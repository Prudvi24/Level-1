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
		cout<<"Default constructor and address: "<<this<<endl;
	}

	~Vechile(){
		cout<<"Default destructor and address: "<<this<<endl;
	}

	Vechile(int maxSpeed){
		cout<<"Paramertized constructor called and address: "<<this<<endl;
		this->maxSpeed = maxSpeed;
		this->color = "Black";
		this->numTyres = 4;
	}
};

class Car : public Vechile{
public:
	int numGears;

	Car(){
		cout<<"Car vec param const and address is: "<<this<<endl;
	}

	~Car(){
		cout<<"Car destructor and address is: "<<this<<endl;
	}
};

int main(){
	Vechile v1;
	v1.numTyres = 4;

	Car c1;
	return 0;
}

/*

Default constructor and address: 0x7ffcfe4a38c0
Default constructor and address: 0x7ffcfe4a38f0
Car vec param const and address is: 0x7ffcfe4a38f0
Car destructor and address is: 0x7ffcfe4a38f0
Default destructor and address: 0x7ffcfe4a38f0
Default destructor and address: 0x7ffcfe4a38c0

*/