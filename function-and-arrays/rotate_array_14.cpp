#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int modulus_default(int a, int n){
	return (a - n * floor(a/n));
}

void reverse_arr(vector<int>&arr, int i, int j){
	while(i<j){
		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
		i++;
		j--;
	}
}

void solve(vector<int>&arr, int k){
	k = modulus_default(k,arr.size());
	cout<<"Modulus k = "<<k<<endl;
	if(k<0){

		k = k+arr.size();
	}
	reverse_arr(arr,0,k-1);
	reverse_arr(arr,k,arr.size()-1);
	reverse_arr(arr,0,arr.size()-1);

	for(auto val : arr){
		cout<<val<<endl;
	}
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	solve(arr,k);
	return 0;
}

