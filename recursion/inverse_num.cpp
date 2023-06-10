#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(int n){
	int ans = 0;
	int count = 1;
	while(n){
		int rem = n%10;
		n /= 10;
		ans += (count * (int)pow(10,rem-1));
		count++;
	}
	cout<<ans<<endl;
}

int main(){
	int n;
	cin>>n;
	solve(n);
	return 0;
}