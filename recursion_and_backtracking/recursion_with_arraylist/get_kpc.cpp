#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<string> keypad = {".;","abc","def","ghi","jkl","mno","pqrs",
							"tu","vwx","yz"};

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

vector<string> get_kpc(string &str){
	if(str.empty()){
		vector<string>res;
		res.push_back("");
		return res;
	}
	char ch = str[0];
	string nstr = str.substr(1);
	vector<string>res = get_kpc(nstr);
	int idx = ch-'0';
	string kps = keypad[idx];
	vector<string>ans;
	for(int i=0;i<kps.length();i++){
		for(auto val : res){
			ans.push_back(kps[i]+val);
		}
	}
	if(ans.empty()){
		return res;
	}
	return ans;
}

int main(){
	string str;
	cin>>str;
	vector<string>ans = get_kpc(str);
	display(ans);
	return 0;
}

