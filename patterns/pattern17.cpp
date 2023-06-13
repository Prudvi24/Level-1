#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

		*	
		*	*	
*	*	*	*	*	
		*	*	
		*	

*/

void solve(int n){
	int sp = n/2;
	int st = 1;
	for(int i=1;i<=n;i++){
		if(i!=n/2+1){
			for(int j=1;j<=sp;j++){
				cout<<" ";
			}
		}
		else{
			for(int j=1;j<=sp;j++){
				cout<<"*";
			}
		}
		for(int j=1;j<=st;j++){
			cout<<"*";
		}
		if(i>=n/2+1){
			st--;
		}
		else{
			st++;
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

