#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

int coin_change_combination(vector<int>&arr, int &n, int &amt){
	vector<int>dp_arr(amt+1,0);
	dp_arr[0] = 1;
	for(int i=0;i<n;i++){
		for(int j=1;j<=amt;j++){
			if(j-arr[i]>=0){
				dp_arr[j] += dp_arr[j-arr[i]]; 
			}
		}
	}
	//display(dp_arr);
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
	int res = coin_change_combination(arr,n,amt);
	cout<<res<<endl;
	return 0;
}

