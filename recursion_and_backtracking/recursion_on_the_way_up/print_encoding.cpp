#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void print_encoding(string str, string ans){
	if(str.empty()){
		cout<<ans<<endl;
		return ;
	}
	else if(str.length()==1){
		if(str[0]=='0'){
			return ;
		}
		int n1 = str[0]-'0';
		string rs = str.substr(1);
		char ch = 'a'+n1-1;
		print_encoding(rs,ans+ch+"");
	}
	else{
		if(str[0]=='0'){
			return ;
		}
		int n1 = str[0]-'0';
		int n2 = stoi(str.substr(0,2));
		char ch1 = 'a'+n1-1;
		string rs1 = str.substr(1);
		print_encoding(rs1,ans+ch1+"");
		if(n2<=26){
			char ch2 = 'a'+n2-1;
			string rs2 = str.substr(2);
			print_encoding(rs2,ans+ch2+"");
		}
	}
}

int main(){
	string str;
	cin>>str;
	print_encoding(str,"");
	return 0;
}

