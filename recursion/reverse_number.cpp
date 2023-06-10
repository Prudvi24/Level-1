#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve_recursion(int n){
	if(n==0){
		return ;
	}
	cout<<n%10<<endl;
	solve_recursion(n/10);
}

void solve_iterative(int n){
	while(n){
		int rem = n%10;
		n /= 10;
		cout<<rem<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	solve_recursion(n);
	cout<<"-----------"<<endl;
	solve_iterative(n);
	return 0;
}