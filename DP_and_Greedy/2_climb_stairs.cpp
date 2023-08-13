#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&backup){
	for(auto val : backup){
		cout<<val<<" ";
	}
	cout<<endl;
}


/*

when we draw the recursion tree for the climb stairs problem we observe the following points
1. Recursion tree is solved from top to bottom.
2. There are suboptimal sub-problems (same problem is solved again and again).

*/

int climb_stair_dp_tabulation(int n){
	vector<int>dp_arr(n+1,0);
	dp_arr[0]=1;

	for(int i=1;i<=n;i++){
		if(i==1){
			dp_arr[i] += dp_arr[i-1];
		}
		else if(i==2){
			dp_arr[i] += dp_arr[i-1] + dp_arr[i-2];
		}
		else{
			dp_arr[i] += dp_arr[i-1] + dp_arr[i-2] + dp_arr[i-3];
		}
	}
	display(dp_arr);
	return dp_arr[n];
}

int climb_stair_dp_memoization(int n, vector<int>&backup){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	if(backup[n]!=0){
		return backup[n];
	}

	int p1 = climb_stair_dp_memoization(n-1,backup);
	int p2 = climb_stair_dp_memoization(n-2,backup);
	int p3 = climb_stair_dp_memoization(n-3,backup);

	int total_paths = p1+p2+p3;
	backup[n]=total_paths;
	return total_paths;
}

int main(){
	int n;
	cin>>n;
	vector<int>backup(n+1,0);
	int ans = climb_stair_dp_memoization(n,backup);
	display(backup);
	cout<<ans<<endl;
	cout<<"-------------------"<<endl;
	int res = climb_stair_dp_tabulation(n);
	cout<<res<<endl;
	return 0;
}

