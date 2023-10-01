#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&res){
	for(auto val : res){
		cout<<val<<" ";
	}
	cout<<endl;
}

vector<int> next_greater_element_to_right(vector<int>&arr, int &n){
	stack<int>st;
	vector<int>res(n,-1);
	for(int i=n-1;i>=0;i--){
		while(!st.empty() && st.top()<=arr[i]){
			st.pop();
		}
		if(st.empty()){
			res[i] = -1;
		}
		else{
			res[i] = st.top();
		}
		st.push(arr[i]);
	}
	return res;
}

int main(){
	int n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int>res = next_greater_element_to_right(arr,n);
	display(res);
	return 0;
}