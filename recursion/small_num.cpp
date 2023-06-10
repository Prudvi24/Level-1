#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

static int sm = INT_MAX;

void solve(string ns, string ks, int idx, string asf){
	if(idx == ns.length()){
		if(asf.length()==0){
			return ;
		}
		int ans = stoi(asf);
		int k = stoi(ks);
		if(ans > k && ans < sm){
			sm = ans;
		}
		return ;
	}
	cout<<asf<<" --> "<<idx<<endl;
	solve(ns,ks,idx+1,asf+ns[idx]);
	solve(ns,ks,idx+1,asf);
}

int main(){
	int n,k;
	cin>>n>>k; // 65354 11
	string ns = to_string(n);
	string ks = to_string(k);
	solve(ns,ks,0,"");
	cout<<sm<<endl;
	return 0;
}