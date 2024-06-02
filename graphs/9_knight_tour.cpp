#include<bits/stdc++.h>

using namespace std;

void display_chess(vector<vector<int>>&chess){
	for(auto vec : chess){
		for(auto val : vec){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}

void knight_tour(vector<vector<int>>&chess, int r, int c, int count){
	if(r<0 || r>=chess.size() || c<0 || c>=chess.size() || chess[r][c]!=0){
		return ;
	}

	if(count==chess.size()*chess.size()){
		chess[r][c]=count;
		display_chess(chess);
		cout<<endl;
		chess[r][c]=0;
		return ;
	}
	chess[r][c]=count;
	knight_tour(chess, r-2, c+1, count+1);
	knight_tour(chess, r-1, c+2, count+1);
	knight_tour(chess, r+1, c+2, count+1);
	knight_tour(chess, r+2, c+1, count+1);
	knight_tour(chess, r+2, c-1, count+1);
	knight_tour(chess, r+1, c-2, count+1);
	knight_tour(chess, r-1, c-2, count+1);
	knight_tour(chess, r-2, c-1, count+1);
	chess[r][c]=0;
}

int main(){
	int n,r,c;
	cin>>n;
	cin>>r>>c;
	vector<vector<int>>chess(n,vector<int>(n,0));
	knight_tour(chess, r, c, 1);
	return 0;
}