#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void print_maze_path_with_jumps(int sr, int sc, int dr, int dc, string ans){
	if(sr==dr && sc==dc){
		cout<<ans<<endl;
		return ;
	}
	else if(sr>dr || sc>dc){
		return ;
	}
	// Horizontal path
	for(int i=1;i<=dc-sc;i++){
		print_maze_path_with_jumps(sr,sc+i,dr,dc,ans+"h"+to_string(i));
	}

	// Vertical path
	for(int i=1;i<=dr-sr;i++){
		print_maze_path_with_jumps(sr+i,sc,dr,dc,ans+"v"+to_string(i));
	}

	// Diagonal path
	for(int i=1, j=1; i<=dr-sr && j<=dc-sc; i++,j++){
		print_maze_path_with_jumps(sr+i,sc+j,dr,dc,ans+"d"+to_string(i));
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	print_maze_path_with_jumps(1,1,n,m,"");
	return 0;
}

