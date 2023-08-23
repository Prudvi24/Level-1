#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&backup){
	for(auto val : backup){
		cout<<val<<" ";
	}
	cout<<endl;
}

int fibanocii_without_dp(int n){
	if(n==0 || n==1){
		return n;
	}
	int fib1 = fibanocii_without_dp(n-1);
	int fib2 = fibanocii_without_dp(n-2);
	int fib = fib1+fib2;
	return fib;
}

int fibanocii_with_dp(int n, vector<int>&backup){
	if(n==0 || n==1){
		return n;
	}
	if(backup[n]!=0){
		return backup[n];
	}
	int fib1 = fibanocii_with_dp(n-1,backup);
	int fib2 = fibanocii_with_dp(n-2,backup);
	int fib = fib1+fib2;
	backup[n] = fib;
	return fib;
}


int main(){
	int n;
	cin>>n;
	vector<int>backup(n+1,0);
	int res = fibanocii_without_dp(n);
	int ans = fibanocii_with_dp(n,backup);
	cout<<ans<<endl;
	display(backup);
	cout<<res<<endl;
	return 0;
}

