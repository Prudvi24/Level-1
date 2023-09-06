#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int first_occurence(vector<int>&arr, int n, int k){
	int lo = 0;
	int hi = n-1;
	int ans = -1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(arr[mid]==k){
			ans = mid;
			hi = mid-1;
		}
		else if(arr[mid] < k){
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}
	return ans;
}

int last_occurence(vector<int>&arr, int n, int k){
	int lo = 0;
	int hi = n-1;
	int ans = -1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(arr[mid]==k){
			ans = mid;
			lo = mid+1;
		}
		else if(arr[mid] < k){
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}
	return ans;
}

pair<int,int> first_and_last_occurence(vector<int>&arr, int n, int k){
	int foa = first_occurence(arr,n,k);
	int loa = last_occurence(arr,n,k);
	pair<int,int>ans(foa, loa);
	return ans;
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
	pair<int,int>ans = first_and_last_occurence(arr,n,k);
	cout<<ans.first<<" "<<ans.second<<endl;
	return 0;
}
/*

13
2 4 4 4 4 6 6 6 8 11 11 13 14
12
-1 -1

*/