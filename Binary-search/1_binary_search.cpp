#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int solve(vector<int>&nums, int lo, int hi, int target){
	if(lo>hi){
		return -1;
	}
	int mid=(lo+hi)/2;

	if(nums[mid]==target){
		return mid;
	}
	else if(nums[mid]<target){
		return solve(nums, mid+1, hi, target);
	}
	else{
		return solve(nums, lo, mid-1, target);
	}
}

int binary_search_recursive(vector<int>&nums, int target){
	return solve(nums, 0, nums.size()-1, target);
}

int binary_search_iterative(vector<int>&nums, int target){
	int lo = 0;
	int hi = nums.size()-1;
	while(lo<=hi){
		int mid = (lo+hi)/2;

		if(nums[mid]==target){
			return mid;
		}
		else if(nums[mid] < target){
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}
	return -1;
}

int main(){
	int n;
	cin>>n;
	vector<int>nums(n,0);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	int target;
	cin>>target;
	int ans = binary_search_iterative(nums,target);
	cout<<"Iterative binary search answer: "<<ans<<endl;
	ans = binary_search_recursive(nums, target);
	cout<<"Recursive binary search answer: "<<ans<<endl;
	return 0;
}

