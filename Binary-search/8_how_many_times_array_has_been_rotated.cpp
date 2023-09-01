#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int how_many_times_array_has_been_rotated(vector<int>&arr){
	int lo = 0;
	int hi = arr.size()-1;
	int ans = INT_MAX;
	int idx = 0;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(arr[lo]<=arr[mid]){
			if(arr[lo] <= ans){
				ans = arr[lo];
				idx = lo;
			}
			lo = mid+1;
		}
		else{
			if(arr[mid] <= ans){
				ans = arr[mid];
				idx = mid;
			}
			hi = mid-1;
		}
	}
	return idx;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans = how_many_times_array_has_been_rotated(arr);
	cout<<ans<<endl;
	return 0;
}