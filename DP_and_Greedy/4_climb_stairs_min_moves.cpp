#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

int mst = INT_MAX;

// solving with recursion
void climb_stairs_min_moves(vector<int>&arr, int idx, int minsteps){
	if(idx==arr.size()){
		mst = min(mst,minsteps);
		return ;
	}
	else if(idx > arr.size()){
		return ;
	}
	for(int i=1;i<=arr[idx];i++){
		climb_stairs_min_moves(arr,idx+i,minsteps+1); 
	}
}


//solving with DP approach
int climb_stairs_min_moves_tabulation(vector<int>&arr, int n){
	vector<int>dp_arr(n+1,INT_MAX);
	dp_arr[n] = 0;
	for(int i=n-1;i>=0;i--){
		for(int j=1;j<=arr[i] && i+j<=n; j++){
			dp_arr[i] = min(dp_arr[i],dp_arr[i+j]);
		}
		if(dp_arr[i]!=INT_MAX){
			dp_arr[i] += 1;
		}
	}
	display(dp_arr);
	return dp_arr[0];
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	climb_stairs_min_moves(arr,0,0);
	cout<<mst<<endl;
	cout<<"-------------------------------------"<<endl;
	int ans = climb_stairs_min_moves_tabulation(arr,n);
	cout<<ans<<endl;
	return 0;
}

