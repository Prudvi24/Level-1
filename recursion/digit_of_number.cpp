#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(int n){
	if(n==0){
		return ;
	}
	int rem = n%10;
	solve(n/10);
	cout<<rem<<endl;
}

int main(){
	int n;
	cin>>n;
	solve(n);
	return 0;
}