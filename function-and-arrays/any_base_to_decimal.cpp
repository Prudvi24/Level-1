#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(long long int n, long long int k){
	long long int ans = 0;
	long long int mul = 1;
	while(n){
		int rem = n%10;
		n /= 10;
		ans += (rem*mul);
		mul *= k;
	}
	cout<<ans<<endl;
}

int main(){
	long long n,k;
	cin>>n>>k;
	solve(n,k);
	return 0;
}

