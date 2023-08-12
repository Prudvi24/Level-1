#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void stair_path(int n, string ans){
	if(n==0){
		cout<<ans<<endl;
		return ;
	}
	if(n<0){
		return ;
	}
	stair_path(n-1,ans+"1");
	stair_path(n-2,ans+"2");
	stair_path(n-3,ans+"3");
}

int main(){
	int n;
	cin>>n;
	stair_path(n,"");
	return 0;
}