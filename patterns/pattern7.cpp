#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

*
 *
  *
   *
    *
     *

*/

void solve(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(i==j){
				cout<<"*";
			}
			else{
				cout<<" ";
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

