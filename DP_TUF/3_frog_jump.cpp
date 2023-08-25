#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&dp){
	for(auto val : dp){
		cout<<val<<" ";
	}
	cout<<endl;
}


// Recursive solution

int frog_jump_recursion1(vector<int>&arr, int idx, int asf){
	if(idx>=arr.size()){
		return INT_MAX;
	}
	else if(idx==arr.size()-1){
		return asf;
	}

	int fm1 = frog_jump_recursion1(arr, idx+1, asf+abs(arr[idx]-arr[idx+1]));
	int fm2 = frog_jump_recursion1(arr, idx+2, asf+abs(arr[idx]-arr[idx+2]));
	//cout<<fm1<<"-->"<<fm2<<endl;
	return min(fm1, fm2);
}

int frog_jump_recursion2(vector<int>&arr, int n){
	if(n==0){
		return 0;
	}
	int jump2 = INT_MAX;
	int jump1 = frog_jump_recursion2(arr,n-1)+abs(arr[n-1]-arr[n]);
	//jump1 += abs(arr[n-1]-arr[n]);
	if(n>1){
		jump2 = frog_jump_recursion2(arr,n-2)+abs(arr[n-2]-arr[n]);
		//jump2 += abs(arr[n-2]-arr[n]);
	}
	//cout<<jump1<<"-->"<<jump2<<endl;
	return min(jump1, jump2);
}

// Solution with DP memoization
int frog_jump_memoization(vector<int>&arr, int n, vector<int>&dp){
	if(n==0){
		return 0;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	int jump2 = INT_MAX;
	int jump1 = frog_jump_memoization(arr,n-1,dp);
	jump1 += abs(arr[n-1]-arr[n]);
	if(n>1){
		jump2 = frog_jump_memoization(arr,n-2,dp);
		jump2 += abs(arr[n-2]-arr[n]);
	}
	//cout<<jump1<<"-->"<<jump2<<endl;
	return dp[n] = min(jump1, jump2);
}

int frog_jump_tabulation(vector<int>&arr, int n){
	vector<int>dp(n+1,-1);
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		int jump2 = INT_MAX;
		int jump1 = dp[i-1];
		jump1 += abs(arr[i-1]-arr[i]);
		if(i>1){
			jump2 = dp[i-2];
			jump2 += abs(arr[i-2]-arr[i]);
		}
		dp[i] = min(jump1, jump2);
	}
	display(dp);
	return dp[n];
}

int frog_jump_space_optimized(vector<int>&arr, int n){
	int a = 0, b = 0;
	int j1 = 0;
	int j2 = INT_MAX;
	for(int i=1;i<n;i++){
		j1 = a + abs(arr[i-1]-arr[i]);
		if(i>1){
			j2 = b + abs(arr[i-2]-arr[i]);
		}
		b = a;
		a = min(j1, j2);
	}
	return a;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"-------Recursion approach 1-----------"<<endl;
	int ans = frog_jump_recursion1(arr,0,0);
	cout<<ans<<endl;
	cout<<"-------Recursion approach 2-----------"<<endl;
	ans = frog_jump_recursion2(arr, n-1);
	cout<<ans<<endl;
	cout<<"------- Memoization ----------"<<endl;
	vector<int>dp(n,-1);
	ans = frog_jump_memoization(arr,n-1,dp);
	display(dp);
	cout<<ans<<endl;
	cout<<"------- DP tabulation --------"<<endl;
	ans = frog_jump_tabulation(arr,n-1);
	cout<<ans<<endl;
	cout<<"------- Space optmized solution --------"<<endl;
	ans = frog_jump_space_optimized(arr,n);
	cout<<ans<<endl;
	return 0;
}
/*

6
30 10 60 10 60 50
-------Recursion approach 1-----------
40
-------Recursion approach 2-----------
40
------- Memoization ----------
-1 20 30 20 30 40 
40
------- DP tabulation --------
0 20 30 20 30 40 
40

*/