#include<bits/stdc++.h>
#define endl '\n'

using namespace std;


/*
	Vechile ---> Car ---> HondaCity
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
		cout<<"Vechile default destructor and address: "<<this<<endl;
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

class HondaCity : public Car{
public:
	HondaCity(){
		cout<<"Honda city default constructor and address is: "<<this<<endl;
	}

	~HondaCity(){
		cout<<"Honda city default destructor and address is: "<<this<<endl;
	}
};

int main(){
	Vechile v1;
	//v1.numTyres = 4;

	HondaCity h1;
	return 0;
}

/*

Vechile default constructor and address: 0x7ffdeccd0180
Vechile default constructor and address: 0x7ffdeccd01b0
Car Default constructor and address is: 0x7ffdeccd01b0
Honda city default constructor and address is: 0x7ffdeccd01b0
Honda city default destructor and address is: 0x7ffdeccd01b0
Car destructor and address is: 0x7ffdeccd01b0
Vechile default destructor and address: 0x7ffdeccd01b0
Vechile default destructor and address: 0x7ffdeccd0180

*/