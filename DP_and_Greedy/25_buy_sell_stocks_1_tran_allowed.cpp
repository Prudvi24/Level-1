#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int buy_sell_stocks_one_transaction_allowed_1(vector<int>&price, int &n){
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

int buy_sell_stocks_one_transaction_allowed_2(vector<int>&price, int &n){
	int lsf = INT_MAX;
	int op = 0;
	int pist = 0;

	for(int i=0;i<n;i++){
		if(price[i] < lsf){
			lsf = price[i];
		}

		pist = price[i]-lsf;

		if(pist > op){
			op = pist;
		}
	}
	return op;
}

int main(){
	int n;
	cin>>n;
	vector<int>price(n,0);
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
	int max_profit = buy_sell_stocks_one_transaction_allowed_1(price,n);
	cout<<max_profit<<endl;
	cout<<"------------------------"<<endl;
	max_profit = buy_sell_stocks_one_transaction_allowed_2(price,n);
	cout<<max_profit<<endl;
	return 0;
}

