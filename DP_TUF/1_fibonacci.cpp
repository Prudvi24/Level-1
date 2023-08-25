#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

// Recursive solution
int fibonacci(int n){
	if(n==0 || n==1){
		return n;
	}

	int fm1 = fibonacci(n-1);
	int fm2 = fibonacci(n-2);

	return fm1+fm2;
}

// Recursion to DP memoization
int fibonacci_memoization(int n, vector<int>&dp){
	if(n==0 || n==1){
		dp[n] = n;
	}
	if(dp[n]!=-1){
		return dp[n];
	}

	int fm1 = fibonacci_memoization(n-1,dp);
	int fm2 = fibonacci_memoization(n-2,dp);

	return dp[n]=fm1+fm2;
}

// Memoization to tabulation
int fibonacci_tabulation(int n){
	vector<int>dp(n+1,1);
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		int fm1 = dp[i-1];
		int fm2 = dp[i-2];
		dp[i] = fm1+fm2;
	}
	return dp[n];
}

// Tabulation to space optimized solution
int fibonacci_space_optimized(int n){
	int a=0;
	int b=1;
	for(int i=2;i<=n;i++){
		int fm1 = a;
		int fm2 = b;
		int temp = fm1+fm2;
		a = b;
		b = temp;
	}
	return b;
}

int main(){
	int n;
	cin>>n;
	cout<<"------Recursive solution------"<<endl;
	int ans = fibonacci(n);
	cout<<ans<<endl;

	cout<<"------DP memoization------"<<endl;
	vector<int>dp(n+1, -1);
	ans = fibonacci_memoization(n,dp);
	cout<<ans<<endl;

	cout<<"------DP tabulation------"<<endl;
	ans = fibonacci_tabulation(n);
	cout<<ans<<endl;

	cout<<"------Space Optimization------"<<endl;
	ans = fibonacci_space_optimized(n);
	cout<<ans<<endl;
	return 0;
}

/*

8
------Recursive solution------
21
------DP memoization------
21
------DP tabulation------
21
------Space Optimization------
21

*/

