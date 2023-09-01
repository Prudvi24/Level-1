#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int min_in_rotated_sorted_array(vector<int>&arr, int &n){
	int lo = 0;
	int hi = n-1;
	int ans = INT_MAX;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		//check the sorted array part

		// if the left half is sorted, then pick the minimum and shrink
		//the search space
		if(arr[lo] <= arr[mid]){
			ans = min(ans,arr[lo]);
			lo = mid+1;
		}
		// if the right half is sorted then pick the minimum and restirct
		//the search space
		else{
			ans = min(ans,arr[mid]);
			hi = mid-1;
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
	int ans = min_in_rotated_sorted_array(arr,n);
	cout<<ans<<endl;
	return 0;
}

