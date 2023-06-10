#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(int n){
	for(int i=1;i*i<=n;i++){
		cout<<i*i<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	solve(n);
	return 0;
}

