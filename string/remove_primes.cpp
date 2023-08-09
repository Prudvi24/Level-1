#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

bool check_prime(int &n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

void remove_primes(vector<int>&arr, int &n){
	string ans = "[";
	for(int i=0;i<n;i++){
		bool cp = check_prime(arr[i]);
		if(cp){
			ans+=(to_string(arr[i])+", ");
		}
	}
	if(ans.length()!=1){
		ans.erase(ans.length()-2,2);
	}
	ans += "]";
	cout<<ans<<endl;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	remove_primes(arr,n);
	return 0;
}

