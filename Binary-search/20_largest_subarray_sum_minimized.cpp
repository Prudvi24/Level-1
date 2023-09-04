#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int possible_subarrays(vector<int>&arr, int &mid){
	int sas = 0; // subarray sum
	int ts = 1; // total subarray
	for(auto val : arr){
		if(val+sas<=mid){
			sas += val;
		}
		else{
			ts++;
			sas = val;
		}
	}
	return ts;
}

int largest_subarray_sum_minimized(vector<int>&arr, int &k){
	int n = arr.size();
	if(n<k){
		return -1;
	}
	int lo=INT_MIN;
	int hi = 0;
	for(auto val : arr){
		lo = max(lo,val);
		hi += val;
	}
	int ans = -1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		int psub = possible_subarrays(arr,mid);
		//cout<<lo<<"-->"<<hi<<"-->"<<mid<<"-->"<<psub<<endl;
		if(psub<=k){
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
	int n,k;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>k;
	int ans = largest_subarray_sum_minimized(arr,k);
	cout<<ans<<endl;
	return 0;
}

