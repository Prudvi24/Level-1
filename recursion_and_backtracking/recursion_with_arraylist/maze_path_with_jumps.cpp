#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<string>&ans){
	cout<<"[";
	for(int i=0;i<ans.size();i++){
		if(i!=ans.size()-1){
			cout<<ans[i]<<", ";
		}
		else{
			cout<<ans[i];
		}
	}
	cout<<"]"<<endl;
}

vector<string>get_maze_path_with_jumps(int sr, int sc, int dr, int dc){
	if(sc==dc && sr==dr){
		vector<string>bres;
		bres.push_back("");
		return bres;
	}
	else if(sr>dr || sc>dc){
		vector<string>bres;
		return bres;
	}

	vector<string>respath;
	// Horizontal path
	vector<string>hpath;
	for(int i=1;i<=dc-sc;i++){
		hpath = get_maze_path_with_jumps(sr,sc+i,dr,dc);
		for(auto val : hpath){
			respath.push_back("h"+to_string(i)+val);
		}
	}
	// Vertical path
	vector<string>vpath;
	for(int i=1;i<=dr-sr;i++){
		vpath = get_maze_path_with_jumps(sr+i,sc,dr,dc);
		for(auto val : vpath){
			respath.push_back("v"+to_string(i)+val);
		}
	}
	// Diagonal path
	vector<string>dpath;
	for(int i=1,j=1;i<=dr-sr && j<=dc-sc; i++,j++){
		dpath = get_maze_path_with_jumps(sr+i,sc+j,dr,dc);
		for(auto val : dpath){
			respath.push_back("d"+to_string(i)+val);
		}
	}
	return respath;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<string>ans = get_maze_path_with_jumps(1,1,n,m);
	display(ans);
	return 0;
}

