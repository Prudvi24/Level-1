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

int prev_trans_max(vector<int>&prices, vector<vector<int>>&dp, int &i, int &j){
	int maxi = INT_MIN;
	for(int x=i-1,y=j-1;y>=0;y--){
		maxi = max(maxi, dp[x][y]+prices[j]-prices[y]);
	}
	return maxi;
}

int buy_sell_stocks_k_trans_allowed(vector<int>&prices, int &n, int &k){
	vector<vector<int>>dp(k+1,vector<int>(n,0));

	for(int i=0;i<=k;i++){
		for(int j=0;j<n;j++){
			if(i==0 || j==0){
				dp[i][j] = 0;
			}
			else{
				int maxi = dp[i][j-1];
				maxi = max(maxi, prev_trans_max(prices,dp,i,j));
				dp[i][j] = maxi;
			}
		}
	}
	display(dp);
	return dp[k][n-1];
}

int main(){
	int n;
	cin>>n;
	vector<int>prices(n,0);
	for(int i=0;i<n;i++){
		cin>>prices[i];
	}
	int k;
	cin>>k;
	int res = buy_sell_stocks_k_trans_allowed(prices, n, k);
	cout<<res<<endl;
	return 0;
}

/*

6
9 6 7 6 3 8
3
0 0 0 0 0 0 
0 0 1 1 1 5 
0 0 1 1 1 6 
0 0 1 1 1 6 
6

*/