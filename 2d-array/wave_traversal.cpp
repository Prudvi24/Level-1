#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<vector<int>>&arr){
	for(auto vec : arr){
		for(auto val : vec){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}

void wave_traversal(vector<vector<int>>&arr){
	for(int i=0;i<arr[0].size();i++){
		if(i%2==0){
			for(int j=0;j<arr.size();j++){
				cout<<arr[j][i]<<" ";
			}
			cout<<endl;
		}
		else{
			for(int j=arr.size()-1;j>=0;j--){
				cout<<arr[j][i]<<" ";
			}			
			cout<<endl;
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>arr(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	wave_traversal(arr);
	return 0;
}