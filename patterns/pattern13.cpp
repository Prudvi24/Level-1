#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 

*/

int fact(int n){
	if(n<=1){
		return 1;
	}
	int ans = fact(n-1);
	return n*ans;
}

void solve(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			int ans = fact(i)/((fact(i-j)*(fact(j))));
			cout<<ans<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	solve(n);
	return 0;
}

