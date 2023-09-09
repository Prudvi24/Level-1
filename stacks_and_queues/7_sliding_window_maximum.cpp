#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&res){
	for(auto val : res){
		cout<<val<<" ";
	}
	cout<<endl;
}

vector<int>greater_element_to_right(vector<int>&arr, int &n){
	stack<int>st;
	st.push(n);
	vector<int>res(n,0);
	for(int i=n-1;i>=0;i--){
		while(st.top()!=n && arr[st.top()]<arr[i]){
			st.pop();
		}
		res[i] = st.top();
		st.push(i);
	}
	cout<<"res vector elements: "<<endl;
	display(res);
	return res;
}

vector<int>sliding_window_maximum(vector<int>&arr, int &n, int &k){
	vector<int>getr = greater_element_to_right(arr,n);
	vector<int>swm(n-k+1,0);
	for(int i=0;i<swm.size();i++){
		int pos = i;
		if(getr[pos]-i>k-1){
			swm[i] = arr[i];
			continue;
		}
		while(pos!=n && getr[pos]-i<=k-1){
			cout<<pos<<"-->"<<getr[pos]<<endl;
			swm[i] = arr[getr[pos]];
			pos = getr[pos];
		}
	}
	cout<<"swm vector elements: "<<endl;
	return swm;
}

int main(){
	int n,k;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>k;
	vector<int>res = sliding_window_maximum(arr,n,k);
	display(res);
	return 0;
}

