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

vector<string>get_maze_path(int sr, int sc, int dr, int dc){
	if(sr==dr && sc==dc){
		vector<string>res;
		res.push_back("");
		return res;
	}
	else if(sr>dr || sc >dc){
		vector<string>res;
		return res;
	}
	vector<string>ans;
	vector<string>hpath = get_maze_path(sr+1,sc,dr,dc);
	for(auto val : hpath){
		ans.push_back("h"+val);
	}
	vector<string>vpath = get_maze_path(sr,sc+1,dr,dc);
	for(auto val : vpath){
		ans.push_back("v"+val);
	}
	return ans;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<string>ans = get_maze_path(0,0,n-1,m-1);
	display(ans);
	return 0;
}

