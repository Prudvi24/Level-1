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
	2. protected properties are inherited as protected.
	3. public properties are inherited as protected.

*/

class Car : protected Vechile{
public:
	int numGears;


	Car(string color, int numTyres){
		this->color = color;
		this->numTyres = numTyres;
	}

	void display(){
		//cout<<"Max speed is: "<<maxSpeed<<endl;
		cout<<"Color is: "<<color<<endl;
		cout<<"Num tyres are: "<< numTyres<<endl;
		cout<<"Num gears are: "<<numGears<<endl;
	}
};

int main(){
	Car c1("Black",4);
	c1.numGears = 5;
	c1.display();
	return 0;
}