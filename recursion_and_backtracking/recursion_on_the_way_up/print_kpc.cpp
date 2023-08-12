#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<string>keypad = {".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

void print_kpc(string str, string ans){
	if(str.empty()){
		cout<<ans<<endl;
		return ;
	}
	int idx = str[0]-'0';
	string ks = keypad[idx];
	string ss = str.substr(1);
	for(int i=0;i<ks.length();i++){
		print_kpc(ss,ans+ks[i]);
	}
}

int main(){
	string str;
	cin>>str;
	print_kpc(str,"");
	return 0;
}