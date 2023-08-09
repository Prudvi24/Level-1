#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void string_compression(string &str){
	int i=0;
	int count = 0;
	string ans = "";
	while(i<str.length()){
		char ch = str[i];
		count = 0;
		while(i<str.length() && str[i]==ch){
			count++;
			i++;
		}
		ans += (ch+to_string(count));
	}
	cout<<ans<<endl;
}

int main(){
	string str;
	cin>>str;
	string_compression(str);
	return 0;
}

