#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

bool find_saddle(vector<vector<int>>&arr,int mir, int idx, int n){
	int mic = INT_MIN;
	for(int i=0;i<n;i++){
		mic = max(mic,arr[i][idx]);
	}
	return mic==mir;
}

void saddle_point(vector<vector<int>>&arr, int n){
	for(int i=0;i<n;i++){
		int mir = INT_MAX;
		int idx=0;
		for(int j=0;j<n;j++){
			if(arr[i][j]<mir){
				mir = arr[i][j];
				idx = j;
			}
		}
		bool res = find_saddle(arr,mir,idx,n);
		if(res){
			cout<<arr[i][idx]<<endl;
			return ;
		}
	}
	cout<<"Invalid input"<<endl;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>>arr(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	saddle_point(arr,n);
	return 0;
}

