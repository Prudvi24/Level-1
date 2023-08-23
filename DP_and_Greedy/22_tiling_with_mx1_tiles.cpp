#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

int tiling_with_mx1_tiles_recursion(int n, int m){
	if(n<=0 || m<=0){
		return 0;
	}
	else if(n<m){  // if the length of the room is less than width only one possible tiling
		return 1;  // Vertical tiling only
	}
	else if(n==m){ // if the length and with are same, then place all tiles horizontal or vertical
		return 2;  // 2 possibilities
	}

	int vertical_plac = tiling_with_mx1_tiles_recursion(n-1,m);
	int horizontal_plac = tiling_with_mx1_tiles_recursion(n-m,m);
	int res = vertical_plac + horizontal_plac;
	return res;
}

int tiling_with_mx1_tiles_tabulation(int &n, int &m){
	vector<int>dp(n+1,0);
	dp[1] = 1;

	for(int i=2;i<=n;i++){
		if(i<m){
			dp[i]=1;
		}
		else if(i==m){
			dp[i] = 2;
 		}
 		else{
 			dp[i] = dp[i-1] + dp[i-m];
 		}
	}
	display(dp);
	return dp[n];
}

int main(){
	int n,m;
	cin>>n>>m;
	int res = tiling_with_mx1_tiles_recursion(n,m);
	cout<<res<<endl;

	cout<<"--------------------------"<<endl;
	res = tiling_with_mx1_tiles_tabulation(n,m);
	cout<<res<<endl;
	return 0;
}

/*

39
16
61
--------------------------
0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 19 22 26 31 37 44 52 61 
61

*/