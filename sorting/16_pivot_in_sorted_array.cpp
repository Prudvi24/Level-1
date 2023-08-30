#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int pivot_in_sorted_array(vector<int>&arr, int n){
	int lo = 0;
	int hi = n-1;
	while(lo < hi){
		int mid = (lo+hi)/2;
		if(arr[mid] < arr[hi]){
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	return arr[hi];
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans = pivot_in_sorted_array(arr, n);
	cout<<ans<<endl;
	return 0;
}

