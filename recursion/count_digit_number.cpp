#include<bits/stdc++.h>

using namespace std;

void solve_string(int n){
	string s = to_string(n);
	cout<<s.length()<<endl;
}

void solve_log(int n){
	cout<<floor(log10(n)+1)<<endl;;
}

void solve_recursive1(int n, int ans){
	if(n==0){
		cout<<ans<<endl;
		return ;
	}
	solve_recursive1(n/10, ans+1);
}

int solve_recursive2(int n){
	if(n/10==0){
		return 1;
	}
	int res = solve_recursive2(n/10);
	return res+1;
}

void solve_iterative(int n){
	int count = 0;
	while(n){
		n /= 10;
		count++;
	}
	cout<<count<<endl;
}

int main(){

	int n;
	cin>>n;
	solve_iterative(n);
	solve_recursive1(n,0);
	solve_log(n);
	solve_string(n);
	cout<<solve_recursive2(n)<<endl;
	return 0;
}