#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

Problem Statement: You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.

If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.

lower bound : Smallest index such that arr[idx] >= x

*/

int lower_bound(vector<int>&arr, int n, int x){
	int lo = 0;
	int hi = n-1;
	int ans = n;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(arr[mid] >= x){
			ans = mid;
			hi = mid-1;
		}
		else{
			lo = mid+1;
		}
	}
	return ans;
}

int lower_bound_other_approach(vector<int>&arr, int n, int x){
	return lower_bound(arr.begin(),arr.end(),x)-arr.begin();
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int x;
	cin>>x;
	int ans = lower_bound(arr, n, x);
	cout<<ans<<endl;
	ans = lower_bound_other_approach(arr,n,x);
	cout<<"Lower bound using c++ STL: "<<ans<<endl;
	return 0;
}
/*

11
1 2 3 3 7 7 8 9 9 9 11
10
10
Lower bound using c++ STL: 10

*/