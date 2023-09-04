#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int possible_students(vector<int>&arr, int &mid){
	int pcap = 0; //page capacity
	int ts = 1; 
	for(int i=0;i<arr.size();i++){
		if(pcap+arr[i]<=mid){
			pcap += arr[i];
		}
		else{
			ts++;
			pcap = arr[i];
		}
	}
	return ts;
}

int books_allocation_problem(vector<int>&arr, int &n, int &m){
	// Books are less than student
	if(n<m){
		return -1;
	}

	int lo = INT_MIN;
	int hi = 0;
	for(int i=0;i<n;i++){
		lo = max(lo,arr[i]);
		hi += arr[i];
	}
	int ans = -1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		int ps = possible_students(arr, mid);
		//cout<<lo<<"-->"<<hi<<"-->"<<mid<<"-->"<<ps<<endl;
		if(ps<=m){
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
	int n,m;
	cin>>n>>m;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans = books_allocation_problem(arr, n, m);
	cout<<ans<<endl;
	return 0;
}

