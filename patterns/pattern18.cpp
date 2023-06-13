#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

*	*	*	*	*	*	*	
	*				*	
		*		*	
			*	
		*	*	*	
	*	*	*	*	*	
*	*	*	*	*	*	*	

*/

void solve(int n){
	int sp = 0;
	int st = n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sp;j++){
			cout<<" ";
		}
		for(int j=1;j<=st;j++){
			if(i>1 && i<=n/2){
				if(j==1 || j==st){
					cout<<"*";
				}
				else{
					cout<<" ";
				}
			}
			else{
				cout<<"*";
			}
		}
		for(int j=1;j<=sp;j++){
			cout<<" ";
		}
		if(i>=n/2+1){
			st+=2;
			sp--;
		}
		else{
			st-=2;
			sp++;
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

