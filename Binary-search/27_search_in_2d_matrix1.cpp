#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

bool search_in_2d_array1(vector<vector<int>>&arr, int &target){
	int n = arr.size();
	int m = arr[0].size();

	int lo = 0;
	int hi = n*m-1;

	while(lo<=hi){
		int mid = (lo+hi)/2;
		int row = mid/m;
		int col = mid%m;
		if(arr[row][col]==target){
			return true;
		}
		else if(arr[row][col] > target){
			hi = mid-1;
		}
		else{
			lo = mid+1;
		}
	}
	return false;
}

int main(){
	int n,m,tar;
	cin>>n>>m>>tar;
	vector<vector<int>>arr(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	bool ans = search_in_2d_array1(arr,tar);
	ans==true ? cout<<"true" : cout<<"false" ;
	return 0;
}

