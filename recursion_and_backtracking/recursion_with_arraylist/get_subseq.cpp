#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<string>&res){
	for(int i=0;i<res.size();i++){
		if(i==0){
			cout<<"[";
		}
		cout<<res[i];
		if(i!=res.size()-1){
			cout<<", ";
		}
		else{
			cout<<"]"<<endl;
		}
	}
}

vector<string> get_subsequence(string str){
	if(str.empty()){
		vector<string>res;
		res.push_back("");
		return res;
	}
	char ch = str[0];
	string nstr = str.substr(1);
	vector<string>la = get_subsequence(nstr);
	vector<string>ans;
	for(auto val : la){
		ans.push_back(val);
	}
	for(auto val : la){
		ans.push_back(ch+val);
	}
	return ans;
}

int main(){
	string str;
	cin>>str;
	vector<string>res = get_subsequence(str);
	display(res);
	return 0;
}

