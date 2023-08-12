#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int last_index(vector<int>&arr,int idx, int x){
	if(idx==arr.size()){
		return -1;
	}
	int res = last_index(arr,idx+1,x);
	if(res==-1){
		if(arr[idx]==x){
			res = idx;
		}
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
	int x;
	cin>>x;
	int pos = last_index(arr,0,x);
	cout<<pos<<endl;
	return 0;
}