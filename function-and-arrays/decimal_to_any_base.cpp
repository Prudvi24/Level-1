#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(long long int n, long long int b){
	long long int mul = 1;
	long long int ans = 0;
	while(n){
		int rem = n%b;
		n /= b;
		ans += (rem*mul);
		mul *= 10;
	}
	cout<<ans<<endl;
}

int main(){
	long long int n,b;
	cin>>n>>b;
	solve(n,b);
	return 0;
}

