#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(int n, int k){
	int nod = 0;
	int temp = n;
	while(temp){
		temp /= 10;
		nod++;
	}
	int div = 1;
	int mul = 1;
	for(int i=1;i<=nod;i++){
		if(i<=k){
			div *= 10;
		}
		else{
			mul *= 10;
		}
	}
	int rem = n%div;
	int ans = (rem*mul)+(n/div);
	cout<<ans<<endl;
}

int main(){
	int n,k;
	cin>>n>>k;
	solve(n,k);
	return 0;
}