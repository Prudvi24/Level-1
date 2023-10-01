#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&res){
	for(auto val : res){
		cout<<val<<" ";
	}
	cout<<endl;
}

vector<int>stock_span(vector<int>&arr, int &n){
	stack<int>st;
	st.push(-1);
	vector<int>res(n,0);
	for(int i=0;i<n;i++){
		while(st.top()!=-1 && arr[st.top()] < arr[i]){
			st.pop();
		}
		res[i] = i-st.top();
		st.push(i);
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int>res = stock_span(arr, n);
	display(res);
	return 0;
}
/*

7
100 80 60 70 60 75 85
1 1 1 2 1 4 6 

5
10 10 10 10 10
1 1 1 1 1 

*/