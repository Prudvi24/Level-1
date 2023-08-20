#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

class Vechile{
private:
	int maxSpeed;
protected:
	int numTyres;
public:
	string color;
};

/*

When we inherit a class using public
	1. private properties are never inherited.
	2. protected properties are inherited as protected.
	3. public properties are inherited as public.

*/

class Car : public Vechile{
public:
	int numGears;

	void display(){
		//cout<<"Max speed is: "<<maxSpeed<<endl; //since this variable is not inherited because of it private property
		cout<<"Color is: "<<color<<endl;
		cout<<"Num tyres are: "<< numTyres<<endl;
		cout<<"Num gears are: "<<numGears<<endl;
	}
};

int main(){
	Car c1;
	c1.color = "Black";
	c1.numGears = 5;
	c1.display();
	return 0;
}

/*

Color is: Black
Num tyres are: 32767
Num gears are: 5

*/