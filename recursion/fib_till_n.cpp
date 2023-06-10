#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve_iterative(int n){
	int a = 0;
	int b = 1;
	while(n){
		cout<<a<<endl;
		int c = a;
		a = b;
		b = a+c;
		n--;
	}
}

void solve_recursive(int n,int a,int b){
	if(n==0){
		return ;
	}
	cout<<a<<endl;
	solve_recursive(n-1,b,a+b);
}

int main(){
	int n;
	cin>>n;
	solve_iterative(n);
	cout<<"-----------"<<endl;
	solve_recursive(n,0,1);
	return 0;
}