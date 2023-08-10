#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int power_log(int x, int n){
	if(n==0){
		return 1;
	}
	//cout<<x<<"-->"<<n<<endl;
	int res = power_log(x, n/2);
	//cout<<res<<endl;
	res *= res;
	if(n%2==1){
		res *= x;
	}
	return res;
}

int main(){
	int n,x;
	cin>>x>>n;
	int ans = power_log(x,n);
	cout<<ans<<endl;
	return 0;
}

