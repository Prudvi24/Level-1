#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void print_maze_path(int sr, int sc, int dr, int dc, string ans){
	if(sr==dr && sc==dc){
		cout<<ans<<endl;
		return ;
	}
	else if(sr>dr || sc>dc){
		return ;
	}
	print_maze_path(sr,sc+1,dr,dc,ans+"h");
	print_maze_path(sr+1,sc,dr,dc,ans+"v");
}

int main(){
	int n,m;
	cin>>n>>m;
	print_maze_path(0,0,n-1,m-1,"");
	return 0;
}

