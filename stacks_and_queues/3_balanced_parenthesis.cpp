#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

bool isValidParenthesis(string &str){
	stack<char>st;
	for(int i=0;i<str.length();i++){
		if(str[i]=='(' || str[i]=='{' || str[i]=='['){
			st.push(str[i]);
		}
		else if(str[i]==')' || str[i]=='}' || str[i]==']'){
			if(st.empty()){
				return false;
			}
			if(str[i]==')' && st.top()!='('){
				return false;
			}
			else if(str[i]==']' && st.top()!='['){
				return false;
			}
			else if(str[i]=='}' && st.top()!='{'){
				return false;
			}
			else{
				st.pop();
			}
		}
	}
	return true;
}

int main(){
	string str;
	cin>>str;
	string nstr = "";
	for(int i=0;i<str.length();i++){

	}
	bool ans = isValidParenthesis(str);
	if(ans){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	return 0;
}

