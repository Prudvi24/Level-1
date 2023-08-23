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

int min_cost_maze_traversal(vector<vector<int>>&maze, int &n, int &m){
	vector<vector<int>>dp_arr(n,vector<int>(m,0));
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(i==n-1 && j==m-1){
				dp_arr[i][j] = maze[i][j];
			}
			else if(i==n-1){
				dp_arr[i][j] = dp_arr[i][j+1] + maze[i][j];
			}
			else if(j==m-1){
				dp_arr[i][j] = dp_arr[i+1][j] + maze[i][j];
			}
			else{
				dp_arr[i][j] = min(dp_arr[i+1][j],dp_arr[i][j+1])+maze[i][j];
			}
		}
	}
	//display(dp_arr);
	return dp_arr[0][0];
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
	int mcmt = min_cost_maze_traversal(arr,n,m);
	cout<<mcmt<<endl;
	return 0;
}

