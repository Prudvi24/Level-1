#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void block_placements(vector<vector<int>>&chess, int row, int col){
	//block the column
	for(int i=row;i<chess.size();i++){
		if(chess[i][col]==0){
			chess[i][col] = 1;
		}
	}
	//block the right diagonal
	for(int i=row,j=col;i<chess.size()&&j<chess.size(); i++,j++){
		if(chess[i][j]==0){
			chess[i][j] = 1;
		}
	}
	//block the left daigonal
	for(int i=row, j=col; i<chess.size()&&j>=0 ;i++,j--){
		if(chess[i][j]==0){
			chess[i][j] = 1;
		}
	}
}

void unblock_placements(vector<vector<int>>&chess, int row, int col){
	//block the column
	for(int i=row;i<chess.size();i++){
		chess[i][col] = 0;
	}
	//block the right diagonal
	for(int i=row,j=col;i<chess.size()&&j<chess.size(); i++,j++){
		chess[i][j] = 0;
	}
	//block the left daigonal
	for(int i=row, j=col;i<chess.size()&&j>=0 ;i++,j--){
		chess[i][j] = 0;
	}
}

void  nQueen(vector<vector<int>>&chess,string asf,int row){
	//cout<<asf<<endl;
	if(row==chess.size()){
		cout<<asf<<endl;
		return ;
	}
	for(int col=0;col<chess.size();col++){
		if(chess[row][col]==0){
			block_placements(chess,row,col);
			nQueen(chess,asf+to_string(row)+"-"+to_string(col)+", ",row+1);
			unblock_placements(chess,row,col);
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>>chess(n,vector<int>(n,0));
	nQueen(chess,"",0);
	return 0;
}

