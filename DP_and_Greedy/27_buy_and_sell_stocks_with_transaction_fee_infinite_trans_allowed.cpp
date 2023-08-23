#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int stocks_with_fee_infinite_tran_allowed(vector<int>&price, int &n, int &fee){
	int bsp = -1*price[0];
	int ssp = 0;
	for(int i=1;i<n;i++){
		int nbsp = 0;
		int nssp = 0;
		if(ssp-price[i] > bsp){
			nbsp = ssp-price[i];
		}
		else{
			nbsp = bsp;
		}

		if(bsp+price[i]-fee > ssp){
			nssp = bsp+price[i]-fee;
		}
		else{
			nssp = ssp;
		}
		bsp = nbsp;
		ssp = nssp;
	}
	return ssp;
}

int main(){
	int n;
	cin>>n;
	vector<int>price(n,0);
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
	int fee;
	cin>>fee;
	int ans = stocks_with_fee_infinite_tran_allowed(price,n,fee);
	cout<<ans<<endl;
	return 0;
}