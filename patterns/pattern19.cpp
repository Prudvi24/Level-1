#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

****  *
   *  *
   *  *
*******
*  *   
*  *   
*  ****

*/

void solve(int n){
	for(int i=1;i<=n;i++){
		//upper pattern
		if(i==1){
			for(int j=1;j<=n;j++){
				if(j<=n/2+1 || j==n){
					cout<<"*";
				}
				else{
					cout<<" ";
				}
			}
		}
		// above middle pattern
		else if(i<=n/2){
			for(int j=1;j<=n;j++){
				if(j==n/2+1 || j==n){
					cout<<"*";
				}
				else{
					cout<<" ";
				}
			}
		}
		// exactly middle pattern
		else if(i==n/2+1){
			for(int j=1;j<=n;j++){
				cout<<"*";
			}
		}
		// last but one pattern
		else if(i==n){
			for(int j=1;j<=n;j++){
				if(j==1 || j>=n/2+1){
					cout<<"*";
				}
				else{
					cout<<" ";
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				if(j==1 || j==n/2+1){
					cout<<"*";
				}
				else{
					cout<<" ";
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

