#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

lower bound : Smallest index such that arr[idx] >= x

upper bound : Smallest index such that arr[idx] > x

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

int upper_bound(vector<int>&arr, int n, int x){
	int lo = 0;
	int hi = n-1;
	int ans = n;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(arr[mid] > x){
			ans = mid;
			hi = mid-1;
		}
		else{
			lo = mid+1;
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
	int x;
	cin>>x;
	int ans = lower_bound(arr, n, x);
	cout<<"Lower bound index: "<<ans<<endl;
	ans = upper_bound(arr, n, x);
	cout<<"Upper bound index: "<<ans<<endl;
	return 0;
}
/*

11
1 2 3 3 7 7 8 9 9 9 11
3
Lower bound index: 2
Upper bound index: 4

*/