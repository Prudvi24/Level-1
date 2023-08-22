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

int parition_into_subsets(int &n, int &k){
	vector<vector<int>>dp(k+1,vector<int>(n+1,0));
	for(int i=0; i<=k; i++){
		for(int j=0; j<=n; j++){
			if(i==0 || j==0){
				dp[i][j] = 0;
			}
			else if(i==1){
				dp[i][j] = 1;
			}
			else{
				if(j<i){
					dp[i][j] = 0;
				}
				else{
					dp[i][j] = dp[i][j-1] * i + dp[i-1][j-1]; 
				}
			}
		}
	}
	display(dp);
	return dp[k][n];
}

int main(){
	int n,k;
	cin>>n>>k;
	int ans = parition_into_subsets(n,k);
	cout<<ans<<endl;
	return 0;
}

/*

4
3
0 0 0 0 0 
0 1 1 1 1 
0 0 1 3 7 
0 0 0 1 6 
6

*/

