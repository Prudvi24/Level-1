#include<bits/stdc++.h>

using namespace std;

/*
	Friend functions : with the helop of which we can somehow access the,

						1. private and protected properties of some class

						2. Friend functions don't have this pointer

						3. Friend functions can be placed or added in any access modifier.
*/

class Bus{
private:
	int numSeats;
public:
	void print();
};

void test();

class Truck{
public:
	int numGears;

	void print1();
	void print2();
	void print3();
};

class Vechile{
private:
	int x;
public:
	int y;

	friend class Truck;     // Now whole truck class becomes friend of Vechile, 
							// so any function of truck can access private and protected properties
	
	friend void Bus :: print();  // Only print() function of bus is friend of Bus class, so it can only access private and protected properties
	
	friend void test();  // Global test function becomes friend of Vechile class, now test function can access the private and protected properties. 
};

void Bus :: print(){
	Vechile v1;
	v1.x = 20;
	v1.y = 30;

	cout<<"Value of x and y is: "<<v1.x<<" "<<v1.y<<endl;
}

void Truck :: print1(){
	Vechile v1;
	v1.x = 30;
	v1.y = 40;

	cout<<"Value of x and y is: "<<v1.x<<" "<<v1.y<<endl;
}

void Truck :: print2(){
	Vechile v1;
	v1.x = 50;
	v1.y = 60;

	cout<<"Value of x and y is: "<<v1.x<<" "<<v1.y<<endl;
}

void Truck :: print3(){
	Vechile v1;
	v1.x = 70;
	v1.y = 80;

	cout<<"Value of x and y is: "<<v1.x<<" "<<v1.y<<endl;
}

void test(){
	Vechile v1;
	v1.x = 100;
	v1.y = 110;

	cout<<"Value of x and y is: "<<v1.x<<" "<<v1.y<<endl;
}

int main(){
	Bus b1;
	b1.print();
	Truck t1;
	t1.print1();
	t1.print2();
	t1.print3();
	test();
	return 0;
}

/*

Value of x and y is: 20 30
Value of x and y is: 30 40
Value of x and y is: 50 60
Value of x and y is: 70 80
Value of x and y is: 100 110

*/