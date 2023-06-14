#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(int n, int k){
	int count=0;
	while(n){
		int rem = n%10;
		n /= 10;
		if(rem==k){
			count++;
		}
	}
	cout<<count<<endl;
}

int main(){
	long long int n,k;
	cin>>n>>k;
	solve(n,k);
	return 0;
}

