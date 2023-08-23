#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int buy_sell_stocks_infinite_trans_with_cooldown(vector<int>&price, int &n){
	int bsp = -price[0];
	int ssp = 0;
	int csp = 0;

	for(int i=1;i<n;i++){
		int nbsp = 0;
		int nssp = 0;
		int ncsp = 0;
		if(csp-price[i] > bsp){
			nbsp = csp-price[i];
		}
		else{
			nbsp = bsp;
		}

		if(bsp+price[i] > ssp){
			nssp = bsp+price[i];
		}
		else{
			nssp = ssp;
		}

		if(ssp > csp){
			ncsp = ssp;
		}
		else{
			ncsp = csp;
		}

		bsp = nbsp;
		ssp = nssp;
		csp = ncsp;
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
	int ans = buy_sell_stocks_infinite_trans_with_cooldown(price,n);
	cout<<ans<<endl;
	return 0;
}

