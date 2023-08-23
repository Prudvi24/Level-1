#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&dp){
	for(auto val : dp){
		cout<<val<<" ";
	}
	cout<<endl;
}

int friends_pairing_recursion(int n){
	if(n==0 || n==1 || n==2){
		return n;
	}
	else if(n<0){
		return 0;
	}

	int alone = friends_pairing_recursion(n-1);
	int frnd_pair = (n-1) * friends_pairing_recursion(n-2);

	int ans = alone + frnd_pair;
	return ans;
}

int friends_pairing(int &n){
	vector<int>dp(n+1,0);
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<=n;i++){
		dp[i] = dp[i-1] + (i-1)*dp[i-2];
	}
	display(dp);
	return dp[n];
}

int main(){
	int n;
	cin>>n;
	int ans = friends_pairing(n);
	cout<<ans<<endl;
	cout<<"---------------------"<<endl;
	ans = friends_pairing_recursion(n);
	cout<<ans<<endl;
	return 0;
}

