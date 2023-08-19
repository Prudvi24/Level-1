#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

class Student{
public:
	int age;
	const int rollNumber;
};

int main(){
	Student s1;  // it raises an error because, when s1 calls default constructor
	             // it assign some garbage value to the age and rollNumber is constant and not initialized.
	s1.age = 22;
	s1.rollNumber = 100;  // at this point rollNumber is holding garbage value, now we can't change.
	return 0;
}

/*

ouput:
======================================================
3_initialisation_list_1.cpp: In function ‘int main()’:
3_initialisation_list_1.cpp:13:10: error: use of deleted function ‘Student::Student()’
   13 |  Student s1;
      |          ^~
3_initialisation_list_1.cpp:6:7: note: ‘Student::Student()’ is implicitly deleted because the default definition would be ill-formed:
    6 | class Student{
      |       ^~~~~~~
3_initialisation_list_1.cpp:6:7: error: uninitialized const member in ‘class Student’
3_initialisation_list_1.cpp:9:12: note: ‘const int Student::rollNumber’ should be initialized
    9 |  const int rollNumber;
      |            ^~~~~~~~~~
3_initialisation_list_1.cpp:15:16: error: assignment of read-only member ‘Student::rollNumber’
   15 |  s1.rollNumber = 100;


*/