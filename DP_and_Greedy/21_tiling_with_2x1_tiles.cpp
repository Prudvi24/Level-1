#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&dp){
	for(auto val : dp){
		cout<<val<<" ";
	}
	cout<<endl;
}

int tiling_with_2x1_tiles_recursion(int n){
	if(n==0 || n==1 || n==2){
		return n;
	}
	// vertical tiling
	int lst = tiling_with_2x1_tiles_recursion(n-1);

	// horizontal tiling
	int rst = tiling_with_2x1_tiles_recursion(n-2);

	return lst+rst;
}

int tiling_with_2x1_tiles_tabulation(int &n){
	vector<int>dp(n+1, 0);
	dp[1] = 1;
	dp[2] = 2;

	for(int i=3;i<=n;i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	display(dp);
	return dp[n];
}

int tiling_with_2x1_tiles_eff(int &n){
	int a = 1;
	int b = 2;
	int tmp = 0;
	for(int i=3;i<=n;i++){
		tmp = a+b;
		a = b;
		b = tmp;
	}
	return tmp;
}

int main(){
	int n;
	cin>>n;
	int res = tiling_with_2x1_tiles_recursion(n);
	cout<<res<<endl;
	cout<<"---------------"<<endl;

	int ans = tiling_with_2x1_tiles_tabulation(n);
	cout<<ans<<endl;
	cout<<"---------------"<<endl;

	ans = tiling_with_2x1_tiles_eff(n);
	cout<<ans<<endl;

	return 0;
}

/*

8
34
---------------
0 1 2 3 5 8 13 21 34 
34
---------------
34

*/
