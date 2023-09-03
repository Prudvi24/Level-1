#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int find_root_place(int mid, int n, int m){
	long int res = 1;
	for(int i=1;i<=n;i++){
		res = res*mid;
		if(res>m){
			return 1;
		}
	}
	if(res==m){
		return 2;
	}
	return 3;
}

int Nth_root_of_m(int n, int m){
	int lo = 1;
	int hi = m/2;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		int ans = find_root_place(mid,n,m);
		if(ans==2){
			return mid;
		}
		else if(ans==3){
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}
	return -1;
}

int main(){
	int n,m;
	cin>>n>>m;
	int ans = Nth_root_of_m(n,m);
	cout<<ans<<endl;
	return 0;
}

