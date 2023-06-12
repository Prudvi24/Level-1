#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

		*	
	*		*	
*				*	
	*		*	
		*	
*/

void solve1(int n){
	int osp = n/2;
	int isp = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=osp;j++){
			cout<<" ";
		}
		if(i==1 || i==n){
			cout<<"*";
			osp--;
			cout<<endl;
			continue;
		}
		else{
			cout<<"*";
		}
		for(int j=1;j<=isp;j++){
			cout<<" ";
		}
		cout<<"*";
		for(int j=1;j<=osp;j++){
			cout<<" ";
		}

		if(i>=n/2+1){
			osp++;
			isp-=2;
		}
		else{
			osp--;
			isp+=2;
		}
		cout<<endl;
	}
}

void solve2(int n){
	int os=n/2;
	int is=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=os;j++){
			cout<<" ";
		}
		cout<<"*";
		for(int j=1;j<=is;j++){
			cout<<" ";
		}
		if(i>1 && i<n){
			cout<<"*";
		}
		if(i<=n/2){
			os--;
			is+=2;
		}
		else{
			os++;
			is-=2;
		}
	}
}

int main(){
	int n;
	cin>>n;
	solve(n);
	return 0;
}

