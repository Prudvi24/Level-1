#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(vector<int>&arr,int tar){
	int i=0;
	int j = arr.size()-1;
	//find the lower index
	int last_idx = -1;
	while(i<=j){
		int mid = (i+j)/2;
		if(tar < arr[mid]){
			j = mid-1;
		}
		else if(tar > arr[mid]){
			i = mid+1;
		}
		else{
			last_idx = mid;
			i = mid+1;
		}
	}

	i=0;
	j=arr.size()-1;
	int first_idx = -1;
	while(i<=j){
		int mid = (i+j)/2;
		if(tar < arr[mid]){
			j = mid-1;
		}
		else if(tar > arr[mid]){
			i = mid+1;
		}
		else{
			first_idx = mid;
			j = mid-1;
		}
	}

	cout<<first_idx<<" "<<last_idx<<endl;	
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int tar;
	cin>>tar;
	solve(arr,tar);
	return 0;
}

