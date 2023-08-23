#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<vector<bool>>&dp_arr){
	for(auto vec : dp_arr){
		for(auto val : vec){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}

bool subset_sum(vector<int>&arr, int n, int tar){
	vector<vector<bool>>dp_arr(n+1, vector<bool>(tar+1,0));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=tar;j++){
			if(j==0){
				dp_arr[i][j] = 1;
			}
			else if(i==0){
				dp_arr[i][j] = 0;
			}
			else{
				if(j-arr[i-1]<0){
					dp_arr[i][j] = dp_arr[i-1][j];
				}
				else{
					dp_arr[i][j] = (dp_arr[i-1][j] || dp_arr[i-1][j-arr[i-1]]);
				}
			}
		}
	}
	//display(dp_arr);
	return dp_arr[n][tar];
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int tar;
	cin>>tar;
	bool ss = subset_sum(arr,n,tar);
	if(ss==1){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	return 0;
}

