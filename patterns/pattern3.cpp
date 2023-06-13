#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve1(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i+j > n){
				cout<<"* ";
			}
			else{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
}

void solve2(int n){
	int sp = n-1;
	int st = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sp;j++){
			cout<<"  ";
		}
		for(int k=1;k<=st;k++){
			cout<<"* ";
		}
		sp--;
		st++;
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	//solve1(n);
	solve2(n);
	return 0;
}

