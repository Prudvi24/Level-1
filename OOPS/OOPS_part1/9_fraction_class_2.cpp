#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

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
/*
	// To add two fractions
	void add(Fraction f2){
		int lcm = this->denominator * f2.denominator;
		int x = lcm/this->denominator;
		int y = lcm/f2.denominator;

		int num = x*(this->numerator) + y*(f2.numerator);

		this->numerator = num;
		this->denominator = lcm;
		cout<<"Result before simplication: "<<this->numerator<<" / "<<this->denominator<<endl;
		this->simplify();
	}
*/

/*	
	The above code snippet. void add(Fraction 2)

	Internally it is initialzed in the below way

	Fraction f2 = main.f2
	   --> a new object f2 is created   "waste of memeory, it is the issue"
	   --> since we are using copy assignment operator when we defined the class.
	   --> copy constructor is called.
	somehow we need to avoid copy and reduce the wastage of the memory
	To avoid we can create a references.

*/  


	void add(const Fraction &f2){   // we can avoid constructor and we are adding const because we are not changing the value of f2 data members.
		int lcm = this->denominator * f2.denominator;
		int x = lcm/this->denominator;
		int y = lcm/f2.denominator;

		int num = x*(this->numerator) + y*(f2.numerator);

		this->numerator = num;
		this->denominator = lcm;
		cout<<"Result before simplication: "<<this->numerator<<" / "<<this->denominator<<endl;
		this->simplify();
	}

	void multiply(const Fraction &f2){
		this->numerator *= f2.numerator;
		this->denominator *= f2.denominator;
		cout<<"Result before simplication: "<<this->numerator<<" / "<<this->denominator<<endl;
		this->simplify();
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
	f1.add(f2);
	f1.print();
	cout<<"-----------------------"<<endl<<endl;

	cout<<"Result of multiplication"<<endl;
	f1.multiply(f2);
	f1.print();
	return 0;
}