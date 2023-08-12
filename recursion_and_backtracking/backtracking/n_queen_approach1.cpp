#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

bool isPlacement(vector<vector<int>>&chess, int row, int col){
	// check the column
	for(int i=row-1, j=col; i>=0; i--){
		if(chess[i][j]==1){
			return false;
		}
	}

	//check the right diagonal
	for(int i=row-1, j=col+1; i>=0 && j<chess.size(); i--,j++){
		if(chess[i][j]==1){
			return false;
		}
	}

	//check the left diagonal
	for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
		if(chess[i][j]==1){
			return false;
		}
	}
	return true;
}

void  nQueen(vector<vector<int>>&chess,string asf,int row){
	//cout<<asf<<endl;
	if(row==chess.size()){
		cout<<asf<<endl;
		return ;
	}
	for(int col=0;col<chess.size();col++){
		if(chess[row][col]==0){
			chess[row][col]=1;
			if(isPlacement(chess,row,col)==true){
				nQueen(chess,asf+to_string(row)+"-"+to_string(col)+", ",row+1);
			}
			chess[row][col]=0;
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

