#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void toggle_case(string &str){
	string ans = "";
	for(int i=0;i<str.length();i++){
		if(str[i]>='a' && str[i]<='z'){
			ans += ('A'-'a'+str[i]);
		}
		else{
			ans += (str[i]-'A'+'a');
		}
		
	}
	cout<<ans<<endl;
}

int main(){
	string str;
	cin>>str;
	toggle_case(str);
	return 0;
}
