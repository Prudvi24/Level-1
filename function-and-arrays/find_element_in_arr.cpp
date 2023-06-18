#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve_iterative(const vector<int>&arr, const int &k){
	for(int i=0;i<arr.size();i++){
		if(arr[i]==k){
			cout<<i<<endl;
			return ;
		}
	}
	cout<<-1<<endl;
}

void solve_recursive(vector<int>&arr, int k, int idx){
	if(idx==arr.size()){
		cout<<-1<<endl;
		return ;
	}
	else if(arr[idx]==k){
		cout<<idx<<endl;
		return ;
	}
	solve_recursive(arr,k,idx+1);
}

int main(){
	int n,k;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>k;
	solve_iterative(arr,k);
	solve_recursive(arr,k,0);
	return 0;
}
