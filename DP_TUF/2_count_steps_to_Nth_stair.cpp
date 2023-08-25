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
int count_steps_to_Nth_stair(int n){
	if(n==0){
		return 1;
	}

	int s1 = count_steps_to_Nth_stair(n-1);
	int s2 = 0;
	if(n>1){
		s2 = count_steps_to_Nth_stair(n-2);
	}
	return s1+s2;
}

// Recursive to memoization
int count_steps_to_Nth_stair_memoization(int n, vector<int>&dp){
	if(n==0){
		return 1;
	}
	if(dp[n]!=-1){
		return dp[n];
	}

	int s1 = count_steps_to_Nth_stair_memoization(n-1, dp);
	int s2 = 0;
	if(n>1){
		s2 = count_steps_to_Nth_stair_memoization(n-2, dp);
	}

	return dp[n]=s1+s2;
}

// memoization to tabulation
int count_steps_to_Nth_stair_tabulation(int n){
	vector<int>dp(n+1, 0);
	dp[0] = 1;
	for(int i=1;i<=n;i++){
		int s1 = dp[i-1];
		int s2 = 0;
		if(i>1){
			s2 = dp[i-2];
		}
		dp[i] = s1+s2;
	}
	display(dp);
	return dp[n];
}

// tabulation to space optimization
int count_steps_to_Nth_stair_space_optimization(int n){
	int a = 1;
	int b = 0;
	for(int i=1;i<=n;i++){
		int s1 = a;
		int s2 = 0;
		if(i>1){
			s2 = b;
		}
		b = a;
		a = s1+s2;
	}
	return a;
}

int main(){
	int n;
	cin>>n;
	cout<<"--------Recursive solution--------"<<endl;
	int ans = count_steps_to_Nth_stair(n);
	cout<<ans<<endl;

	cout<<"--------DP memoization solution--------"<<endl;
	vector<int>dp(n+1,-1);
	ans = count_steps_to_Nth_stair_memoization(n,dp);
	display(dp);
	cout<<ans<<endl;

	cout<<"--------DP tabulation solution--------"<<endl;
	ans = count_steps_to_Nth_stair_tabulation(n);
	cout<<ans<<endl;

	cout<<"--------Tabulation to space optimization--------"<<endl;
	ans = count_steps_to_Nth_stair_space_optimization(n);
	cout<<ans<<endl;
	return 0;
}
/*

5
--------Recursive solution--------
8
--------DP memoization solution--------
-1 1 2 3 5 8 
8
--------DP tabulation solution--------
1 1 2 3 5 8 
8
--------Tabulation to space optimization--------
8

*/
