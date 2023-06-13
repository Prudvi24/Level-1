#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

1       1
12     21
123   321
1234 4321
123454321

*/

void solve(int n){
	int col = 2*n-1;
	int sp = col-2;
	for(int i=1;i<=n;i++){
		int num=1;
		for(int j=1;j<=i;j++){
			cout<<num;
			num++;
		}
		for(int j=1;j<=sp;j++){
			cout<<" ";
		}
		int idx=i;
		if(i==n){
			idx--;
			num--;
		}
		for(int j=1;j<=idx;j++){
			num--;
			cout<<num;
		}
		sp-=2;
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	solve(n);
	return 0;
}

