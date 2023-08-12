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

void flood_fill(vector<vector<int>>&maze, int sr, int sc, string asf, vector<vector<bool>>&visited){
	if(sr==maze.size()-1 && sc==maze[0].size()-1){
		cout<<asf<<endl;
		return ;
	}
	if(sr<0 || sr>=maze.size() || sc<0 || sc>=maze[0].size() || maze[sr][sc]==1 || visited[sr][sc]==1){
		return ;
	}
	visited[sr][sc]=1;
	flood_fill(maze,sr-1,sc,asf+"t",visited);
	flood_fill(maze,sr,sc-1,asf+"l",visited);
	flood_fill(maze,sr+1,sc,asf+"d",visited);
	flood_fill(maze,sr,sc+1,asf+"r",visited);
	visited[sr][sc]=0;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>arr(n,vector<int>(m,0));
	//display(arr);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	vector<vector<bool>>visited(n,vector<bool>(m,0));
	flood_fill(arr,0,0,"",visited);
	return 0;
}

