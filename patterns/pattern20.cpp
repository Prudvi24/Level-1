#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

*				*	
*				*	
*		*		*	
*	*		*	*	
*				*	

*/

void solve(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i<=n/2){
				if(j==1 || j==n){
					cout<<"* ";
				}
				else{
					cout<<"  ";
				}				
			}
			else if(i>=n/2+1){
				if(j==1 || j==n|| i==j || i+j==n+1){
					cout<<"* ";
				}
				else{
					cout<<"  ";
				}
			}
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

