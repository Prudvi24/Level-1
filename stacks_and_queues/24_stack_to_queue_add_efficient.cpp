#include <iostream>
#include <exception>
#include <stack>
using namespace std;

class StackToQueueAdapter {
public:
  stack<int> mainS;
  stack<int> helperS;

  int size() {
    // write your code here
    return mainS.size();
  }

  void add(int data) {
    // write your code here
    mainS.push(data);
  }

  int peek() {
    // write your code here
    if(mainS.size()==0){
      cout<<"Queue underflow"<<endl;
      return -1;
    }

    //mains to helpers
    while(!mainS.empty()){
      helperS.push(mainS.top());
      mainS.pop();
    }
    int ele = helperS.top();
    mainS.push(ele);
    helperS.pop();
    //helpers to mains
    while(!helperS.empty()){
      mainS.push(helperS.top());
      helperS.pop();
    }
    return ele;
  }

  int remove() {
    // write your code here
    if(mainS.size()==0){
      cout<<"Queue underflow"<<endl;
      return -1;
    }

    //mains to helpers
    while(!mainS.empty()){
      helperS.push(mainS.top());
      mainS.pop();
    }
    int ele = helperS.top();
    helperS.pop();
    //helpers to mains
    while(!helperS.empty()){
      mainS.push(helperS.top());
      helperS.pop();
    }
    return ele;
  }
};

int main() {
  StackToQueueAdapter q;
  string str;
  cin >> str;

  while (str != "quit") {
    if (str == "add") {
      int val;
      cin >> val;
      q.add(val);
    }
    else if (str == "remove") {
      int val = q.remove();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "peek") {
      int val = q.peek();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "size") {
      cout << q.size() << endl;
    }
    cin >> str;
  }
  return 0;
}