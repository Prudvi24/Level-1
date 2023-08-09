#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void diff_tow_consecutive_chars(string &str){
	string ans="";
	for(int i=0;i<str.length()-1;i++){
		int diff = str[i+1] - str[i];
		ans += (str[i]+to_string(diff));
		if(i+1==str.length()-1){
			ans += str[i+1];
		}
	}

	cout<<ans<<endl;
}

int main(){
	string str;
	cin>>str;
	diff_tow_consecutive_chars(str);
	return 0;
}

