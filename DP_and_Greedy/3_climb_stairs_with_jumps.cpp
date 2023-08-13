#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*  

Hints for DP tabulation

	1. Storage and Meaning : After declaring a table to get the answer, 
	we should know what is purpose of each cell in table.


	2. Direction : After knowing storage and meaning, we must know which is large and smaller problem.
				   We always solve smaller problems first and put together the smaller problems to solve larger problems.
				   The direction is always from smaller problems to bigger problems.
				   Hence we get the direction.
				   Eg : 1d matrix : direction may be from left to right
				   		2d array the direction may be from top to bottom


	3. Travel and solve : Try solving the problems in the defined direction. 

*/

int climb_stairs_with_jumps_tabulation(vector<int>&arr,int n){
	vector<int>dp_array(n+1,0);
	dp_array[n]=1;
	for(int i=n-1;i>=0;i--){
		for(int j=1;j<=arr[i] && i+j<=n;j++){
			dp_array[i] += dp_array[i+j];
		}
	}
	return dp_array[0];
}

int climb_stairs_with_jumps(vector<int>&arr, int idx,string asf){
	if(idx==arr.size()){
		cout<<asf<<endl;
		return 1;
	}
	else if(idx > arr.size()){
		return 0;
	}
	else if(arr[idx]==0){
		return 0;
	}
	int ans = 0;
	for(int i=1;i<=arr[idx];i++){
		ans += climb_stairs_with_jumps(arr,idx+i,asf+to_string(i)+" ");
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int res = climb_stairs_with_jumps(arr,0,"");
	cout<<res<<endl;
	cout<<"-----------------------------"<<endl;
	int res1 = climb_stairs_with_jumps_tabulation(arr,n);
	cout<<res1<<endl;
	return 0;
}

