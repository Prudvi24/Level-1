#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int search_in_rotated_sorted_array(vector<int>&arr, int n, int k){
	int lo = 0;
	int hi = n-1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		// if the element is found, return 
		if(arr[mid]==k){
			return mid;
		}

		//left half is sorted
		if(arr[lo] <= arr[mid]){
			// check the element is present in sorted half
			if(arr[lo]<=k && k<=arr[mid]){
				hi = mid-1;
			}
			// if the target is not present in left half then move to right half
			else{
				lo = mid+1;
			}
		}
		//right is sorted
		else{
			// check target is present in the right half
			if(arr[mid]<=k && k<=arr[hi]){
				lo = mid+1;
			}
			// if the element is not present in the sorted right, then move left
			else{
				hi = mid-1;
			}
		}
	}
	return -1;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	int ans = search_in_rotated_sorted_array(arr, n, k);
	cout<<ans<<endl;
	return 0;
}

