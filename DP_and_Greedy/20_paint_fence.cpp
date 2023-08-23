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

int paint_fence_tabulation(int &n, int &k){
	vector<vector<int>>dp(2,vector<int>(n+1,0));
	dp[0][2] = k*1;
	dp[1][2] = k*(k-1);
	int total = dp[0][2]+dp[1][2];
	
	for(int j=3;j<=n;j++){
		dp[0][j] = dp[1][j-1];
		dp[1][j] = total * (k-1);
		total = dp[0][j]+dp[1][j];
	}
	display(dp);
	int res = dp[0][n]+dp[1][n];
	return res;
}

int paint_fence_efficient(int &n, int &k){
	int same_ii = k*1;
	int diff_ij = k * (k-1);
	int total_pos = same_ii+diff_ij;

	for(int i=3;i<=n;i++){
		same_ii = diff_ij;
		diff_ij = total_pos * (k-1);
		total_pos = same_ii + diff_ij;
	}
	return total_pos;
}

int main(){
	int n,k;
	cin>>n>>k;
	int res = paint_fence_tabulation(n,k);
	cout<<res<<endl;
	cout<<"--------------------"<<endl;
	int ans = paint_fence_efficient(n,k);
	cout<<ans<<endl;
	return 0;
}

/*

8
3
0 0 3 6 18 48 132 360 984 
0 0 6 18 48 132 360 984 2688 
3672
--------------------
3672

*/

