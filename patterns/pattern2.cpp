#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*
* * * * * * * 
* * * * * * 
* * * * * 
* * * * 
* * * 
* * 
* 
*/

void solve(int n){
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=i;j++){
			cout<<"* ";
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

