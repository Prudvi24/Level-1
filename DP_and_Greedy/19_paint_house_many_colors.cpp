#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<vector<int>>&dp){
	for(auto vec : dp){
		for(auto val : vec){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}

int getMin(vector<vector<int>>&dp, int i, int j){
	int rmin = INT_MAX;
	int row = j;
	int col = i-1;
	for(int a=0;a<dp.size();a++){
		if(a!=row){
			rmin = min(rmin,dp[a][col]);
		}
	}
	return rmin;
}

int paint_house_many_color(vector<vector<int>>&arr, int &n, int &k){
	vector<vector<int>>dp(k,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			if(i==0){
				dp[j][i] = arr[i][j];
			}
			else{
				int mpph = getMin(dp,i,j);
				dp[j][i] = mpph + arr[i][j];
			}
		}
	}
	display(dp);
	return getMin(dp,n,k);
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<vector<int>>arr(n,vector<int>(k,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			cin>>arr[i][j];
		}
	}
	int res = paint_house_many_color(arr,n,k);
	cout<<res<<endl;
	return 0;
}

/*

4 3
1 5 7
5 8 4
3 2 9
1 2 4
-----------
1 10 8 8 
5 9 7 10 
7 5 18 11 
8


*/

