#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void subsequence(string str, string ans){
	if(str.empty()){
		cout<<ans<<endl;
		return ;
	}
	char ch = str[0];
	string ss = str.substr(1);
	subsequence(ss,ans+ch);
	subsequence(ss,ans);
}

int main(){
	string str;
	cin>>str;
	subsequence(str,"");
	return 0;
}

