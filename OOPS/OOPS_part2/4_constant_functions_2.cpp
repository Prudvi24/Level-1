#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

class Fraction{
private:
	int numerator;
	int denominator;

public:
	Fraction(){

	}

	Fraction(int numerator, int denominator){
		this->numerator = numerator;
		this->denominator = denominator;
	}

	int getNumerator() const{
		return numerator;
	}

	int getDenominator() const{
		return denominator;
	}

	void setNumerator(int n) const{
		numerator = n;
	}

	/*
		Even after making the above function constant, it is raising an error
		Because it is changing the value.
		But constant object are not allowed to do so.

		4_constant_functions_2.cpp: In member function ‘void Fraction::setNumerator(int) const’:
		4_constant_functions_2.cpp:30:13: error: assignment of member ‘Fraction::numerator’ in read-only object
  		 30 |   numerator = n;
  		    |   ~~~~~~~~~~^~~

	*/

	void setDenominator(int d){
		denominator = d;
	}

	void print(){
		cout<<"Fraction is: "<<this->numerator<<" / "<<this->denominator<<endl;
	}
};

int main(){
	Fraction f1(10,2);
	Fraction f2(15,4);

	Fraction const f3;  

	cout<<"Fraction: "<<f3.getNumerator()<<" / "<<f3.getDenominator()<<endl;
	f3.setNumerator(21);
	/*f3 is constant object, it is not allowed call any functions
	  that changes the values of the currne object.

	  Since f3 is a constant object, compiler wont allows to call any functions (even normal functions).

	  constant object are allowed to access only constant functions.

	  constant functions : which doesn't change any property of current object.
	*/ 
	return 0;
}

/*
		4_constant_functions_2.cpp: In member function ‘void Fraction::setNumerator(int) const’:
		4_constant_functions_2.cpp:30:13: error: assignment of member ‘Fraction::numerator’ in read-only object
  		 30 |   numerator = n;
  		    |   ~~~~~~~~~~^~~
*/


