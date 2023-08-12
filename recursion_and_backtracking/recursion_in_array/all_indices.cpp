#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void all_indices(vector<int>&arr, int idx, int x){
	if(arr.size()==idx){
		return ;
	}
	if(arr[idx]==x){
		cout<<idx<<endl;
	}
	all_indices(arr,idx+1,x);
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
	all_indices(arr,0,x);
	return 0;
}

