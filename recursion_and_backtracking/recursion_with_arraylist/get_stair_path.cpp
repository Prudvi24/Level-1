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

/*

Draw recursion tree for allowed jumps (in our case the maximum jumps are 3)
So from a step we can take maximum of jump 3 and min jump 1

*/

vector<string>get_stair_path(int n){
	if(n==0){
		vector<string>baseres;
		baseres.push_back("");
		return baseres;
	}
	else if(n<0){
		vector<string>baseres;
		return baseres;
	}
	vector<string>path1 = get_stair_path(n-1);
	vector<string>path2 = get_stair_path(n-2);
	vector<string>path3 = get_stair_path(n-3);
	vector<string>res;
	for(auto val : path1){
		res.push_back("1"+val);
	}
	for(auto val : path2){
		res.push_back("2"+val);
	}
	for(auto val : path3){
		res.push_back("3"+val);
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	vector<string>ans = get_stair_path(n);
	display(ans);
	return 0;
}

