#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int find_peak_element(vector<int>&arr){
	int n =arr.size();
	int lo = 1;
	int hi = n-2;

	if(n==1){
		return 0;
	}

	//check for the 1st element pivot
	if(arr[0] > arr[1]){
		return 0;
	}

	//check for the last element pivot
	if(arr[n-1] > arr[n-2]){
		return n-1;
	}

	while(lo<=hi){
		//if the peak is found return
		int mid = (lo+hi)/2;
		if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
			return mid;
		}
		else if(arr[mid] > arr[mid+1]){
			hi = mid-1;
		}
		else if(arr[mid] > arr[mid-1]){
			lo = mid+1;
		}
		else{
			lo = mid+1;
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
	int ans = find_peak_element(arr);
	cout<<ans<<endl;
	return 0;
}

