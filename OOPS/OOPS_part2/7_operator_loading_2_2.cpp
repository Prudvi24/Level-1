#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

If we want to add two fractions using + operator. We have overload + operator for our class
This method is know as operator overloading.

==================================================
Our idea to perform (7_operator_loading_1.cpp)
1. f3 = f1 + f2   instead of f1.add(f2)
2. f3 = f1 * f2   
3. f1==f2

=====================================================
In 7_operator_overloading_2.cpp we will discuss

4. pre incremenet operator
	4.1 ==> ++f1
	4.2 ==> f3 = ++f1 (Overloding in this program)

*/

class Fraction{
private:
	int numerator;
	int denominator;

public:
	Fraction(int numerator, int denominator){
		this->numerator = numerator;
		this->denominator = denominator;
	}

	Fraction(){

	}

	void simplify(){
		int gcd = 1;
		int j = min(this->numerator, this->denominator);
		for(int i=1;i<=j;i++){
			if(this->numerator%i==0 && this->denominator%i==0){
				gcd = i;
			}
		}
		this->numerator /= gcd;
		this->denominator /= gcd;
	}

	void print(){
		cout<<"Fraction is: "<<this->numerator<<" / "<<this->denominator<<endl;
	}

    // "+" operator overloading
	Fraction operator+ (const Fraction &f2){
		int lcm = this->denominator * f2.denominator;
		int x = lcm/this->denominator;
		int y = lcm/f2.denominator;

		int num = x*(this->numerator) + y*(f2.numerator);

		Fraction fnew(num,lcm);
		fnew.simplify();
		return fnew;
	}

	// "*" operator overloading
 	Fraction operator* (const Fraction &f2){
		int n = this->numerator * f2.numerator;
		int d = this->denominator * f2.denominator;
		Fraction fnew(n,d);
		fnew.simplify();
		return fnew;
	}

	// "==" operator overloading
	bool operator== (const Fraction &f2){
		if(this->numerator==f2.numerator && this->denominator==f2.denominator){
			return true;
		}
		else{
			return false;
		}
	}

	//"++" pre-increment operator overloading
	Fraction operator++(){
		this->numerator += this->denominator;
		this->simplify();
		return *this;   // return the current object.
	}
	 
};

int main(){
	cout<<"Fraction 1: "<<endl;
	Fraction f1(10,2);
	f1.print();
	cout<<"-----------------------"<<endl<<endl;

	cout<<"Pre-incremenet of f1: "<<endl;
	Fraction f3 = ++f1;
	f1.print();
	cout<<"-----------------------"<<endl<<endl;

	cout<<"Fraction 3: "<<endl;
	f3.print();

	// We can pre-increment twice but it wont return the correct result
	cout<<"Fraction 2: "<<endl;
	Fraction f2(8,4);
	f2.print();
	cout<<"-----------------------"<<endl<<endl;

	cout<<"pre-increment twice on f2"<<endl;
	++(++f2);
	f2.print();   // printing 3/1 instead of 4/1 ("wrong answer") it is resolved in 7_operator_overloading_2_3.cpp
	return 0;
}
/*

Fraction 1: 
Fraction is: 10 / 2
-----------------------

Pre-incremenet of f1: 
Fraction is: 6 / 1
-----------------------

Fraction 3: 
Fraction is: 6 / 1
Fraction 2: 
Fraction is: 8 / 4
-----------------------

pre-increment twice on f2
Fraction is: 3 / 1

*/