#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int possible_capacity(vector<int>&weights, int &mid){
	int td = 0; 
	int cap = 0;
	for(int i=0;i<weights.size();i++){
		if(cap+weights[i] <= mid){
			cap += weights[i];
		}
		else{
			td++;
			cap = weights[i];
		}
	}
	td++;
	return td;
}

int capacity_of_ship_packages_within_d_days(vector<int>&weights, int &d){
	int lo = INT_MIN;
	int hi = 0;
	for(int i=0;i<weights.size();i++){
		lo = max(lo, weights[i]);
		hi += weights[i];
	}
	int ans = -1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		int pd = possible_capacity(weights, mid);
		cout<<lo<<"-->"<<hi<<"-->"<<mid<<"-->"<<pd<<endl;
		if(pd<=d){
			ans = mid;
			hi = mid-1;
		}
		else{
			lo = mid+1;
		}
	}
	return ans;
}

int main(){
	int n,d;
	cin>>n>>d;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans = capacity_of_ship_packages_within_d_days(arr,d);
	cout<<ans<<endl;
	return 0;
}

