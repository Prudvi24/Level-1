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

// Recursive solution

int max_sum_non_adj_elements(vector<int>&arr,int idx, int ie){
	if(arr.size()==idx){
		return 0;
	}
	int include = INT_MIN;
	int inc_on_ex = INT_MIN;
	int skip_on_exc = INT_MIN;
	if(ie){
		include = max_sum_non_adj_elements(arr,idx+1,0);
		return include;
	}
	else{
		inc_on_ex = max_sum_non_adj_elements(arr, idx+1, 1);
		skip_on_exc = max_sum_non_adj_elements(arr, idx+1, 0);
		inc_on_ex += arr[idx];
		skip_on_exc += 0;
	}
	return max(skip_on_exc, inc_on_ex);
}

// Recursion to memoization
int max_sum_non_adj_elements_memoization(vector<int>&arr, int idx, int ie, vector<vector<int>>&dp){
	if(arr.size()==idx){
		dp[ie][idx] = 0;
		return 0;
	}

	if(dp[ie][idx]!=-1){
		return dp[ie][idx];
	}

	int include = INT_MIN;
	int inc_on_ex = INT_MIN;
	int skip_on_exc = INT_MIN;

	if(ie){
		include = max_sum_non_adj_elements_memoization(arr,idx+1,0,dp);
		return dp[ie][idx] = include;
	}
	else{
		inc_on_ex = max_sum_non_adj_elements_memoization(arr, idx+1, 1,dp);
		skip_on_exc = max_sum_non_adj_elements_memoization(arr, idx+1, 0,dp);
		inc_on_ex += arr[idx];
		skip_on_exc += 0;		
	}
	return dp[ie][idx] = max(inc_on_ex,skip_on_exc);
}

// memoization to tabulation
int max_sum_non_adj_elements_tabulation(vector<int>&arr){
	int n = arr.size();
	vector<vector<int>>dp(2,vector<int>(n+1,-1));
	dp[0][n] = 0;
	dp[1][n] = 0;

	for(int idx=n-1; idx>=0; idx--){
		for(int ie = 0;ie<2;ie++){
			if(ie){
				dp[1][idx] = dp[0][idx+1]+0;
			}
			else{
				dp[0][idx] = max(dp[1][idx+1]+arr[idx], dp[0][idx+1]);				
			}
		}
	}
	display(dp);
	return dp[0][0];
}

// tabulation to space optimized solution
int max_sum_non_adj_elements_space_optimized(vector<int>&arr){
	int n = arr.size();
	int prev1 = 0;
	int prev2 = 0;
	int curr1 = 0;
	int curr2 = 0;
	for(int idx=n-1;idx>=0;idx--){
		for(int ie=0;ie<2;ie++){
			if(ie){
				curr2 = prev1 + 0;
			}
			else{
				curr1 = max(prev2+arr[idx], prev1);
			}
		}
		prev1 = curr1;
		prev2 = curr2;
	}
	return curr1;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"--------Recursive solution--------"<<endl;
	int ans = max_sum_non_adj_elements(arr,0,0);
	cout<<ans<<endl;
	
	cout<<"--------Recursion to memoization solution--------"<<endl;
	vector<vector<int>>dp(2, vector<int>(n+1, -1));
	ans = max_sum_non_adj_elements_memoization(arr,0,0,dp);
	display(dp);
	cout<<ans<<endl;

	cout<<"--------Memoization to tabulation solution--------"<<endl;
	ans = max_sum_non_adj_elements_tabulation(arr);
	cout<<ans<<endl;

	cout<<"--------Tabulation to space optimized solution--------"<<endl;
	ans = max_sum_non_adj_elements_space_optimized(arr);
	cout<<ans<<endl;
	return 0;
}
/*

6
5 10 10 100 5 6
--------Recursive solution--------
116
--------Recursion to memoization solution--------
116 116 106 106 6 6 0 
-1 106 106 6 6 0 0 
116
--------Memoization to tabulation solution--------
116 116 106 106 6 6 0 
116 106 106 6 6 0 0 
116
--------Tabulation to space optimized solution--------
116

*/