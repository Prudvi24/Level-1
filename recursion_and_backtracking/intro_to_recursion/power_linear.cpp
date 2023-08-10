#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int power_linear(int x, int n){
	if(n==0){
		return 1;
	}
	int res = power_linear(x, n-1);
	return x*res;
}

int main(){
	int n,x;
	cin>>x>>n;
	int ans = power_linear(x,n);
	cout<<ans<<endl;
	return 0;
}

