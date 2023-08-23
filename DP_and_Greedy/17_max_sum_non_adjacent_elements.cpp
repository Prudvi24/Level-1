#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<vector<int>>&arr){
	for(auto vec : arr){
		for(auto val : vec){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}

int maxsum = INT_MIN;

void max_sum_non_adj_elements_recursion(vector<int>&arr, int asf, int idx, int ie, string sos){
	if(arr.size()==idx){
		if(maxsum < asf){
			cout<<sos<<endl;
			maxsum = asf;
		}
		return ;
	}

	if(ie==1){
		max_sum_non_adj_elements_recursion(arr,asf,idx+1,0,sos);
	}
	else{
		max_sum_non_adj_elements_recursion(arr,asf+arr[idx],idx+1,1,sos+to_string(arr[idx])+", ");
		max_sum_non_adj_elements_recursion(arr,asf,idx+1,0,sos);
	}
}

int max_sum_non_adj_elements_tabulation(vector<int>&arr){
	int n = arr.size();
	vector<vector<int>>dp(2,vector<int>(n,0));
	dp[0][0]=arr[0];
	dp[0][1]=0;
	for(int j=1;j<n;j++){
		for(int i=0;i<2;i++){
			if(i==0){
				dp[i][j] = dp[i+1][j-1]+arr[j];
			}
			else{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j-1]);
			}
		}
	}
	display(dp);
	return max(dp[0][n-1],dp[1][n-1]);
}

int max_sum_non_adj_elements_efficient(vector<int>&arr){
	int n = arr.size();
	int a = 0, b = 0;
	for(int i=0;i<n;i++){
		int tmp = a;
		a = b+arr[i];
		b = max(tmp,b);
	}
	return max(a,b);
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	max_sum_non_adj_elements_recursion(arr,0,0,0,"");
	cout<<"Answer using recursion: "<<maxsum<<endl;
	
	cout<<"====================================="<<endl;
	
	int ans = max_sum_non_adj_elements_tabulation(arr);
	cout<<"Answer using tabulation: "<<ans<<endl;
	
	cout<<"====================================="<<endl;
	ans = max_sum_non_adj_elements_efficient(arr);
	cout<<"Answer using fficient way: "<<ans<<endl;
	return 0;
}

