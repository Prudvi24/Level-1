#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int factorial(int n){
	if(n==0){
		return 1;
	}
	int res = factorial(n-1);
	return res*n;
}

int main(){
	int n;
	cin>>n;
	int ans = factorial(n);
	cout<<ans<<endl;
	return 0;
}

