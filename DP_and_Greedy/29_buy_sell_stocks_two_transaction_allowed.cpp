#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&dp){
	for(auto val : dp){
		cout<<val<<" ";
	}
	cout<<endl;
}

int buy_sell_stocks_two_trans_allowed(vector<int>&prices, int n){
	vector<int>ptd(n,0);
	vector<int>pad(n,0);

	int lafn = prices[0];
	ptd[0] = 0;
	for(int i=1;i<n;i++){
		if(prices[i] < lafn){
			lafn = prices[i];
		}
		int profit = prices[i]-lafn;

		if(profit > ptd[i-1]){
			ptd[i] = profit;
		}
		else{
			ptd[i] = ptd[i-1];
		}
	}

	int laftn = prices[n-1];
	pad[n-1] = 0;
	for(int i=n-2;i>=0;i--){
		if(prices[i] > laftn){
			laftn = prices[i];
		}

		int profit = laftn-prices[i];
		
		if(profit > pad[i+1]){
			pad[i] = profit;
		}
		else{
			pad[i] = pad[i+1];
		}
	}

	int overall_prf = INT_MIN;
	for(int i=0;i<n;i++){
		if(pad[i]+ptd[i] > overall_prf){
			overall_prf = pad[i]+ptd[i];
		}
	}
	return overall_prf;
}

int main(){
	int n;
	cin>>n;
	vector<int>prices(n,0);
	for(int i=0;i<n;i++){
		cin>>prices[i];
	}
	int ans = buy_sell_stocks_two_trans_allowed(prices,n);
	cout<<ans<<endl;
	return 0;
}

