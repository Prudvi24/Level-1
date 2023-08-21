#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

If we want to add two fractions using + operator. We have overload + operator for our class
This method is know as operator overloading.

Our idea to perform
f3 = f1 + f2   instead of f1.add(f2)

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

	bool operator== (const Fraction &f2){
		if(this->numerator==f2.numerator && this->denominator==f2.denominator){
			return true;
		}
		else{
			return false;
		}
	}
};

int main(){
	cout<<"Fraction 1: "<<endl;
	Fraction f1(10,2);
	f1.print();
	cout<<"-----------------------"<<endl<<endl;

	cout<<"Fraction 2: "<<endl;
	Fraction f2(8,4);
	f2.print();
	cout<<"-----------------------"<<endl<<endl;

	cout<<"Result of addition"<<endl;
	Fraction f3 = f1+f2;
	f3.print();
	cout<<"-----------------------"<<endl<<endl;

	cout<<"Result of multiplication"<<endl;
	Fraction f4 = f1*f2;
	f4.print();

	cout<<"-----------------------"<<endl<<endl;

	cout<<"Check equality of fraction f1 and f2"<<endl;
	if(f1==f2){
		cout<<"Equal"<<endl;
	}
	else{
		cout<<"Not equal"<<endl;
	}

	cout<<"-----------------------"<<endl<<endl;
	cout<<"Fraction 5: "<<endl;
	Fraction f5(10,2);
	f1.print();
	cout<<"-----------------------"<<endl<<endl;

	cout<<"Fraction 6: "<<endl;
	Fraction f6(10,2);
	f2.print();
	
	cout<<"-----------------------"<<endl<<endl;
	cout<<"Check equality of fraction f5 and f6"<<endl;
	if(f5==f6){
		cout<<"Equal"<<endl;
	}
	else{
		cout<<"Not equal"<<endl;
	}

	return 0;
}

/*

Fraction 1: 
Fraction is: 10 / 2
-----------------------

Fraction 2: 
Fraction is: 8 / 4
-----------------------

Result of addition
Fraction is: 7 / 1
-----------------------

Result of multiplication
Fraction is: 10 / 1
-----------------------

Check equality of fraction f1 and f2
Not equal
-----------------------

Fraction 5: 
Fraction is: 10 / 2
-----------------------

Fraction 6: 
Fraction is: 8 / 4
-----------------------

Check equality of fraction f5 and f6
Equal

*/