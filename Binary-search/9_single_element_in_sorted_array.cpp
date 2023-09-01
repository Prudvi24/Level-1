#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int single_element_in_sorted_array(vector<int>&arr){
	int n = arr.size();
	int lo = 1;
	int hi = n-2;
	// if there is only one element
	if(n==1){
		return arr[0];
	}
	// boundary testcase
	if(arr[0]!=arr[1]){
		return arr[0];
	}
	// boundary testcase
	if(arr[n-1]!=arr[n-2]){
		return arr[n-1];
	}
	while(lo<=hi){
		int mid = (lo+hi)/2;

		if(mid%2==0){
			if(arr[mid]==arr[mid-1]){
				hi = mid-1;
			}
			else if(arr[mid]==arr[mid+1]){
				lo = mid+1;
			}
			else{
				return arr[mid];
			}
		}
		else{
			if(arr[mid]==arr[mid-1]){
				lo = mid+1;
			}
			else if(arr[mid]==arr[mid+1]){
				hi = mid-1;
			}
			else{
				return arr[mid];
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
	int ans = single_element_in_sorted_array(arr);
	cout<<ans<<endl;
	return 0;
}

