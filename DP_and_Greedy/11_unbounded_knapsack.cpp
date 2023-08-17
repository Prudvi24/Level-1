#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&dp_arr){
	for(auto val : dp_arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

int unbounded_knapsack(vector<int>&val, vector<int>&wt, int &n, int &cap){
	vector<int>dp_arr(cap+1,0);
	for(int i=0;i<=cap;i++){
		for(int j=0;j<n;j++){
			if(i==0){
				dp_arr[i] = 0;
			}
			else{
				if(i-wt[j]>=0){
					dp_arr[i] = max(dp_arr[i],dp_arr[i-wt[j]]+val[j]);
				}
			}
		}
	}
	display(dp_arr);
	return dp_arr[cap];
}

int main(){
	int n;
	cin>>n;
	vector<int>val(n,0);
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	vector<int>wt(n,0);
	for(int i=0;i<n;i++){
		cin>>wt[i];
	}
	int cap;
	cin>>cap;
	int maxcap = unbounded_knapsack(val,wt,n,cap);
	cout<<maxcap<<endl;
	return 0;
}

