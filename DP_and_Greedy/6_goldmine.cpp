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

int goldmine(vector<vector<int>>&gold, int &n, int &m){
	vector<vector<int>>dp_arr(n,vector<int>(m,0));
	for(int i=0,j=m-1; i<n; i++){
		dp_arr[i][j] = gold[i][j];
	}
	for(int j=m-2;j>=0;j--){
		for(int i=0;i<n;i++){
			if(i==0){
				dp_arr[i][j] = max(dp_arr[i][j+1],dp_arr[i+1][j+1])+gold[i][j];
			}
			else if(i==n-1){
				dp_arr[i][j] = max(dp_arr[i][j+1],dp_arr[i-1][j+1])+gold[i][j];
			}
			else{
				dp_arr[i][j] = max(max(dp_arr[i-1][j+1],dp_arr[i][j+1]),dp_arr[i+1][j+1])+gold[i][j];
			}
		}
	}
	//display(dp_arr);
	int mg = INT_MIN;
	for(int i=0,j=0;i<n;i++){
		mg = max(mg,dp_arr[i][j]);
	}	
	return mg;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>mine(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mine[i][j];
		}
	}
	int maxgold = goldmine(mine,n,m);
	cout<<maxgold<<endl;
	return 0;
}

