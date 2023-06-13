#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

*******
 ******
  *****
   ****
    ***
     **
      *
*/

void solve(int n){
	int sp = 0;
	int st = n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sp;j++){
			cout<<" ";
		}
		for(int j=1;j<=st;j++){
			cout<<"*";
		}
		cout<<endl;
		sp++;
		st--;
	}
}

int main(){
	int n;
	cin>>n;
	solve(n);
	return 0;
}

