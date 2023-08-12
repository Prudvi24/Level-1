#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int max_in_array(vector<int>&arr, int idx){
	if(arr.size()==idx){
		return INT_MIN;
	}
	int res = max_in_array(arr,idx+1);
	if(arr[idx] > res){
		res = arr[idx];
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans = max_in_array(arr,0);
	cout<<ans<<endl;
	return 0;
}

