#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

bool search_in_2d_array2(vector<vector<int>>&arr, int &target){
	int row = 0;
	int col = arr[0].size()-1;

	while(row<arr.size() && col>=0){
		if(arr[row][col]==target){
			return true;
		}
		else if(arr[row][col]>target){
			col--;
		}
		else{
			row++;
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
	bool ans = search_in_2d_array2(arr,tar);
	cout<<ans<<endl;
	return 0;
}

