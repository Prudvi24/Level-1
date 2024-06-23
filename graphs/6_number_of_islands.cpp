#include <bits/stdc++.h>

using namespace std;

int no_of_island(vector<vector<int>>&graph, vector<vector<bool>>&visited, 
								int row, int col){
	if(row<0 || row>=graph.size() || col<0 || col>=graph[0].size()){
		return 0;
	}
	if(visited[row][col]==1 || graph[row][col]){
		return 0;
	}
	visited[row][col]=1;
	no_of_island(graph, visited, row-1, col);
	no_of_island(graph, visited, row, col+1);
	no_of_island(graph, visited, row+1, col);
	no_of_island(graph, visited, row, col-1);
	return 1;
}

int main(){
	int m,n;
	cin>>m>>n;
	vector<vector<int>>graph(m, vector<int>(n,0));
	for(int i=0;i<m;i<i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
		}
	}
	vector<vector<bool>>visited(m,vector<bool>(n,0));
	int islands = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(visited[i][j]==0 || graph[i][j]==0){
				islands += no_of_island(graph, visited, i, j);
			}
		}
	}
	cout<<"Number of islands: "<<islands<<endl;
}
/*
input
----------------
8 8
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1 
1 1 1 1 1 1 1 0 
1 1 0 0 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
*/