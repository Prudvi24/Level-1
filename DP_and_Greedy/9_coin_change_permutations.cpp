#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

int coin_change_permutation(vector<int>&arr, int &n, int &amt){
	vector<int>dp_arr(amt+1, 0);
	dp_arr[0]=1;
	for(int i=1;i<=amt;i++){
		for(int j=0;j<n;j++){
			if(i-arr[j]>=0){
				dp_arr[i] += dp_arr[i-arr[j]];
			}
		}
	}
	display(dp_arr);
	return dp_arr[amt];
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int amt;
	cin>>amt;
	int res = coin_change_permutation(arr,n,amt);
	cout<<res<<endl;
	return 0;
}

