#include<bits/stdc++.h>

using namespace std;

class MinStack {
private:
  stack<int> allData;
  stack<int> minData;

public:
  int size() {
    // write your code here
    return allData.size();
  }

public:
  void push(int val) {
    if(allData.empty()){
      allData.push(val);
      minData.push(val);
    }
    else{
      int tp = minData.top();
      allData.push(val);
      minData.push(std::min(tp,val));
    }
  }

public:
  int pop() {
    // write your code here
    int data = allData.top();
    allData.pop();
    minData.pop();
    return data;
  }

public:
  int top() {
    // write your code here
    return allData.top();
  }

public:
  int min() {
    // write your code here
    return minData.top();
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