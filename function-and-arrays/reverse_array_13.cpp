#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void swap_fun(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void solve(vector<int>&arr){
	int i=0;
	int j=arr.size()-1;
	while(i<j){
		swap_fun(&arr[i],&arr[j]);
		i++;
		j--;
	}
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	solve(arr);
	for(auto val : arr){
		cout<<val<<endl;
	}
	return 0;
}

