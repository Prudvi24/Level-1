#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*
	Hierarchical Inheritance
*/

class Vechile{
private:
	int maxSpeed;
protected:
	int numTyres;
public:
	string color;

	Vechile(){
		cout<<"Vechile default constructor and address is: "<<this<<endl;
	}

	Vechile(int maxSpeed){
		this->maxSpeed = maxSpeed;
		cout<<"Vechile parameterized constructor and address is: "<<this<<endl;
	}

	~Vechile(){
		cout<<"Vechile destructor and address is: "<<this<<endl;
	}
};

class Car : public Vechile{
public:
	int numGears;

	Car(){
		cout<<"Car default constructor and address is: "<<this<<endl;
	}

	Car(int x, int y) : Vechile(x){
		cout<<"Car parameterized constructor and address is: "<<this<<endl;
		this->numGears = y;
	}

	~Car(){
		cout<<"Car destructor called and address is: "<<this<<endl;
	}
};

class Truck : public Vechile{
public:
	int numTankers;

	Truck(){
		cout<<"Truck default constructor and address is: "<<this<<endl;
	}

	~Truck(){
		cout<<"Truck destructor called and address is: "<<this<<endl;
	}
};

int main(){
	Car c1;
	Truck t1;
	return 0;
}

/*

Vechile default constructor and address is: 0x7ffee1ca3460
Car default constructor and address is: 0x7ffee1ca3460
Vechile default constructor and address is: 0x7ffee1ca3490
Truck default constructor and address is: 0x7ffee1ca3490
Truck destructor called and address is: 0x7ffee1ca3490
Vechile destructor and address is: 0x7ffee1ca3490
Car destructor called and address is: 0x7ffee1ca3460
Vechile destructor and address is: 0x7ffee1ca3460

*/