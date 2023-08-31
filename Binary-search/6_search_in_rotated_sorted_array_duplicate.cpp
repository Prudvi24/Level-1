#include<bits/stdc++.h>
#define endl '\n'

using namespace std;


bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int n = arr.size();
    int lo = 0;
	int hi = n-1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		// if the element is found, return 
		if(arr[mid]==k){
			return true;
		}
        //shrink the array
        if(arr[lo]==arr[mid] && arr[mid]==arr[hi]){
            lo++;
            hi--;
            continue;
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
	return false;
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
	bool ans = searchInARotatedSortedArrayII(arr,k);
	if(ans==1){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	return 0;
}

