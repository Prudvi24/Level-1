#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int max_1s_in_2d_matrix(vector<vector<int>>&arr, int &n, int &m){
	int no1s = m;
	int idx = -1; //possible index
	for(int i=0;i<n;i++){
		int lo = 0;
		int hi = m-1;
		int ans = INT_MAX;
		while(lo<=hi){
			int mid = (lo+hi)/2;
			if(arr[i][mid]==1){
				ans = mid;
				hi = mid-1;
			}
			else{
				lo = mid+1;
			}
		}
		if(ans < no1s){
			no1s = ans;
			idx = i;
		}
	}
	return idx;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>arr(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	int ans = max_1s_in_2d_matrix(arr,n,m);
	cout<<ans<<endl;
	return 0;
}

