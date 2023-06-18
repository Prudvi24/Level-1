#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(vector<int>&arr, int k){
	int i=0, j=arr.size()-1;
	while(i<=j){
		int mid = (i+j)/2;
		if(k < arr[mid]){
			j = mid-1;
		}
		else if(k > arr[mid]){
			i = mid+1;
		}
		else{
			cout<<arr[mid]<<endl;
			return ;
		}
	}
	if(j<0){
		cout<<arr[i]<<endl;
	}
	else if(i>=arr.size()){
		cout<<arr[j]<<endl;
	}
	else{
		cout<<arr[i]<<" "<<arr[j]<<endl;
	}
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
	solve(arr,k);
	return 0;
}

