#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int kth_missing_positive_number(vector<int>&arr, int &n, int &k){
	int lo=0;
	int hi=n-1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		int mnap = arr[mid]-(mid+1); // missing number at that specific index in array
		if(mnap<k){
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}
	return hi+1+k;
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
	int ans = kth_missing_positive_number(arr,n,k);
	cout<<ans<<endl;
	ans = linear_solution(arr,k,n);
	cout<<ans<<endl;
	return 0;
}

