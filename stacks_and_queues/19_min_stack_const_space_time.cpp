#include<iostream>
#include <string>
#include <stack>

using namespace std;


class MinStack {
  stack<int> data;
  int minVal;


public:
  int size() {
    // write your code here
    return data.size();
  }

public:
  void push(int val) {
    // write your code here
    if(data.empty()){
      data.push(val);
      minVal = val;
    }
    else{
      if(val >= minVal){
        data.push(val);
      }
      else{
        data.push(val+val-minVal);
        minVal = val;
      }
    }
  }

public:
  int pop() {
    // write your code here
    if(data.top() < minVal){
      int tmp = minVal;
      minVal = 2*minVal-data.top();
      data.pop();
      return tmp;
    }
    int tmp = data.top();
    data.pop();
    return tmp;
  }

public:
  int top() {
    // write your code here
    if(data.top() < minVal){
      return minVal;
    }
    return data.top();
  }

public:
  int min() {
    // write your code here
    return minVal;
  }

};


int main() {
  MinStack st;

  string str;
  cin >> str;

  while (str != "quit") {

    if (str == "push") {
      int val;
      cin >> val;
      st.push(val);
    }
    else if (str == "pop") {
      int val = st.pop();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "top") {
      int val = st.top();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "size") {
      cout << st.size() << endl;
    }
    else if (str == "min" ) {
      int val = st.min();
      if (val != -1) {
        cout << val << endl;
      }
    }

    cin >> str;

  }

}