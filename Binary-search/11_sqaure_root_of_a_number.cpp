#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

long int sqaure_root_of_a_number(long int n){
	long int lo = 1;
	long int hi = (1+n)/2;

	while(lo<=hi){
		long int mid = (lo+hi)/2;
		long int res = mid*mid;
		if(res==n){
			return mid;
		}
		else if(res > n){
			hi = mid-1;
		}
		else{
			lo = mid+1;
		}
	}
	return hi;
}

int main(){
	long int n;
	cin>>n;
	long int ans = sqaure_root_of_a_number(n);
	cout<<ans<<endl;
	return 0;
}

