#include<bits/stdc++.h>

using namespace std;

class Vechile{
private:
	int maxSpeed;
public:
	string color;
protected:
	int numTyres;
};

/*

When we inherit a class using protected
	1. private properties are never inherited.
	2. protected properties are inherited as private.
	3. public properties are inherited as private.

*/

class Car : private Vechile{
public:
	int numGears;

	Car(string color, int numTyres, int numGears){
		this->color = color;
		this->numTyres = numTyres;
		this->numGears = numGears;
	}

	void display(){
		//cout<<"Max speed is: "<<maxSpeed<<endl;
		cout<<"Color is: "<<color<<endl;
		cout<<"Num tyres are: "<< numTyres<<endl;
		cout<<"Num gears are: "<<numGears<<endl;
	}
};

int main(){
	Car c1("Black",4,5);
	c1.display();
	return 0;
}