#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int possible_bouquets(vector<int>&arr, int mid, int &k){
	int oab = 0; // overall available bouquets
	int cab = 0; // current available bouquets
	for(int i=0;i<arr.size();i++){
		if(arr[i]<=mid){
			cab++;
		}
		else{
			oab += floor((double)cab/(double)k);
			cab = 0;
		}
	}
	oab += floor((double)cab/(double)k);
	return oab;
}

int min_days_to_make_bouquets(vector<int>&arr, int &k, int &m){
	if(arr.size()<(m*k)){
		return -1;
	}
	int lo=INT_MAX;
	int hi=INT_MIN;
	for(int i=0;i<arr.size();i++){
		lo = min(lo,arr[i]);
		hi = max(hi,arr[i]);
	}
	int ans = hi;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		int res = possible_bouquets(arr,mid,k);
		if(res>=m){
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
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k,m;
	cin>>k>>m;
	int ans = min_days_to_make_bouquets(arr,k,m);
	cout<<ans<<endl;
	return 0;
}

