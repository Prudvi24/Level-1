#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(vector<int>&arr){
	int n = arr.size();
	for(int i=0;i<n;i++){
		arr[arr[i]%n] = arr[arr[i]%n]+(i*n);
	}
	for(auto val : arr){
		cout<<val/n<<" ";
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
	solve(arr);
	return 0;
}

