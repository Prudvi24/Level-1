#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int buy_sell_stocks_one_transaction_allowed(vector<int>&price, int &n){
	int lptd = price[0];
	int max_profit = 0;

	for(int i=0;i<n;i++){
		if(price[i] >= lptd){
			max_profit = max(max_profit, price[i]-lptd);
		}
		else{
			lptd = price[i];
		}
	}
	return max_profit;
}

int main(){
	int n;
	cin>>n;
	vector<int>price(n,0);
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
	int max_profit = buy_sell_stocks_one_transaction_allowed(price,n);
	cout<<max_profit<<endl;
	return 0;
}

