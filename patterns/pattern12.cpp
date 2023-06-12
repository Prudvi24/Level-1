#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

0 
1 1 
2 3 5 
8 13 21 34 
55 89 144 233 377 

*/

void solve(int n){
	int a = 0;
	int b = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<a<<" ";
			int t = a;
			a = b;
			b = a+t;
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

