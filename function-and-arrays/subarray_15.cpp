#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(vector<int>&arr){
	int n = arr.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<=j;k++){
				cout<<arr[k]<<" ";
			}
			cout<<endl;
		}
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
	return 0;
}

