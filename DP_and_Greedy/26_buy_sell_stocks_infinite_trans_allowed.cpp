#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int buy_sell_stocks_infinite_trans_allowed(vector<int>&price, int n){
	int sell_date = 0;
	int buy_date = 0;
	int max_profit = 0;

	for(int i=1;i<n;i++){
		if(price[i-1]<price[i]){
			sell_date++;
		}
		else{
			max_profit += (price[sell_date]-price[buy_date]);
			sell_date = i;
			buy_date = i;
		}
	}
	max_profit += price[sell_date]-price[buy_date];
	return max_profit;
}

int main(){
	int n;
	cin>>n;
	vector<int>price(n,0);
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
	int max_profit = buy_sell_stocks_infinite_trans_allowed(price, n);
	cout<<max_profit<<endl;
	return 0;
}

