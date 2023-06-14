#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int any_base_to_decimal(long long int n, int b){
	int ans = 0;
	int mul = 1;
	while(n){
		int rem = n%10;
		n /= 10;
		ans+=(rem*mul);
		mul *= b;
	}
	return ans;
}

void solve(long long int n, int b, int k){
	long long int dec = any_base_to_decimal(n,b);
	long long ans = 0, mul=1;
	while(dec){
		int rem = dec%k;
		dec /= k;
		ans += (rem*mul);
		mul *= 10;
	}
	cout<<ans<<endl;
}

int main(){
	long long int n;
	int b,k;
	cin>>n>>b>>k;
	solve(n,b,k);
	return 0;
}

