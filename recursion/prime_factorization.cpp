#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve_iterative(int n){
	int i = 2;
	while(n!=1){
		while(n%i==0){
			cout<<i<<" ";
			n /= i;
		}
		i++;
	}
	cout<<endl;
}

void solve_recursive(int n, int k){
	if(n==1){
		return ;
	}
	if(n%k==0){
		cout<<k<<" ";
		solve_recursive(n/k,k);
	}
	else{
		solve_recursive(n,k+1);
	}
}

int main(){
	int n;
	cin>>n;
	solve_iterative(n);
	solve_recursive(n,2);
	return 0;
}

