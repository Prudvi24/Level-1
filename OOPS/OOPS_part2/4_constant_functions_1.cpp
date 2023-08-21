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

	int getNumerator(){
		return numerator;
	}

	int getDenominator(){
		return denominator;
	}

	void setNumerator(int n){
		numerator = n;
	}

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

	//f3.setNumerator(10);
	//f3.setDenominator(2); 

	cout<<"Fraction: "<<f3.getNumerator()<<" / "<<f3.getDenominator()<<endl;
	/*f3 is constant object, it is not allowed call any functions
	  that changes the values of the currne object.

	  Since f3 is a constant object, compiler wont allows to call any functions (even normal functions).

	  constant object are allowed to access only constant functions.

	  constant functions : which doesn't change any property of current object.
	*/ 
	return 0;
}

/*

4_constant_functions_1.cpp: In function ‘int main()’:
4_constant_functions_1.cpp:51:38: error: passing ‘const Fraction’ as ‘this’ argument discards qualifiers [-fpermissive]
   51 |  cout<<"Fraction: "<<f3.getNumerator()<<" / "<<f3.getDenominator()<<endl;
      |                                      ^
4_constant_functions_1.cpp:21:6: note:   in call to ‘int Fraction::getNumerator()’
   21 |  int getNumerator(){
      |      ^~~~~~~~~~~~
4_constant_functions_1.cpp:51:66: error: passing ‘const Fraction’ as ‘this’ argument discards qualifiers [-fpermissive]
   51 |  cout<<"Fraction: "<<f3.getNumerator()<<" / "<<f3.getDenominator()<<endl;
      |                                                                  ^
4_constant_functions_1.cpp:25:6: note:   in call to ‘int Fraction::getDenominator()’
   25 |  int getDenominator(){
      |      ^~~~~~~~~~~~~~

*/