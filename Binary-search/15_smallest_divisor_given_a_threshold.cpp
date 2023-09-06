#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int smallest_divisor_possible(vector<int>&arr, int mid){
	int limit_count = 0;
	for(int i=0;i<arr.size();i++){
		limit_count += ceil((double)arr[i]/(double)mid);
	}
	return limit_count;
}

int smallest_divisor_given_a_threshold(vector<int>&arr, int &limit){
	int n = arr.size();
	int lo = 0;
	int hi = INT_MIN;
	for(int i=0;i<n;i++){
		hi = max(hi,arr[i]);
	}
	int ans = -1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		int sdp = smallest_divisor_possible(arr,mid);
		if(sdp <= limit){
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
	int limit;
	cin>>limit;
	int ans = smallest_divisor_given_a_threshold(arr,limit);
	cout<<ans<<endl;
	return 0;
}

