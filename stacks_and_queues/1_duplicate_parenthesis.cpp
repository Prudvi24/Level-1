#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

bool duplicate_parenthesis(string &str){
	stack<int>st;
	for(int i=0;i<str.length();i++){
		if(str[i]!=' '){
			if(str[i]==')'){
				char ch = st.top();
				if(ch=='('){
					return true;
				}
				else{
					while(!st.empty() && st.top()!='('){
						st.pop();
					}
					st.pop();
				}
			}
			else{
				st.push(str[i]);
			}
		}
	}
	return false;
}

int main(){
	string str;
	cin>>str;
	bool ans = duplicate_parenthesis(str);
	cout<<ans<<endl;
	return 0;
}

