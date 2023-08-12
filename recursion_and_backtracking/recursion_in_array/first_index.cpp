#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int first_index(vector<int>arr, int x, int idx){
	if(idx==arr.size()){
		return -1;
	}
	if(arr[idx]==x){
		return idx;
	}
	int res_idx = first_index(arr,x,idx+1);
	return res_idx;
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
	int idx = first_index(arr,x,0);
	cout<<idx<<endl;
	return 0;
}

