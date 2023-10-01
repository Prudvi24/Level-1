#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

class Stack{
public:
	int *arr;
	int tos;
	int MaxCapacity;

	Stack(int size){
		this->MaxCapacity = size;
		this->arr = new int[this->MaxCapacity];
		this->tos = -1;
	}

	Stack(){
		Stack(10);
	}

	int size(){
		return tos+1;
	}

	void push(int data){
		if(tos==MaxCapacity-1){
			cout<<"Stack overflow"<<endl;
		}
		else{
			arr[++tos] = data;
		}
	}

	int top(){
		if(tos<0){
			cout<<"Stack underflow"<<endl;
			return -1;
		}
		return arr[tos];
	}	

	int pop(){
		if(tos<0){
			cout<<"Stack underflow"<<endl;
			return -1;
		}
		return arr[tos--]; 
	}

	void display(){
		for(int i=tos;i>=0;i--){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
  int n;
  cin >> n;
  Stack st(n);
  string str;
  cin >> str;

  while (str != "quit") {
    if (str == "push") {
      int val;
      cin >> val;
      st.push(val);
    } else if (str == "pop") {
      int val = st.pop();
      if (val != -1) {
        cout << val << endl;
      }
    } else if (str == "top") {
      int val = st.top();
      if (val != -1) {
        cout << val << endl;
      }

    } else if (str == "size") {
      cout << st.size() << endl;
    } else if (str == "display") {
      st.display();
    }
    cin >> str;
  }
	return 0;
}

