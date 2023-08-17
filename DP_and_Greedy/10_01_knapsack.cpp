#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<vector<int>>&dp_arr){
	for(auto vec : dp_arr){
		for(auto val : vec){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}

int zero_one_knapscak(vector<int>&value, vector<int>&wt, int n, int cap){
	vector<vector<int>>dp_arr(n+1,vector<int>(cap+1, 0));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=cap;j++){
			if(i==0 || j==0){
				dp_arr[i][j] = 0;
			}
			else{
				if(j-wt[i-1] >= 0){
					dp_arr[i][j] = max(dp_arr[i-1][j], dp_arr[i-1][j-wt[i-1]]+value[i-1]);
				}
				else{
					dp_arr[i][j] = dp_arr[i-1][j];
				}
			}
		}
	}
	display(dp_arr);
	return dp_arr[n][cap];
}

int main(){
	int n;
	cin>>n;
	vector<int>value(n,0);
	vector<int>wt(n,0);
	for(int i=0;i<n;i++){
		cin>>value[i];
	}
	for(int i=0;i<n;i++){
		cin>>wt[i];
	}
	int cap;
	cin>>cap;
	int maxcap = zero_one_knapscak(value,wt,n,cap);
	cout<<maxcap<<endl;
	return 0;
}

