#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

string postfix_to_infix(string exp){
	stack<string>st;
	for(int i=0;i<exp.length();i++){
		if(exp[i]>='0' && exp[i]<='9'){
			string res = "";
			res += exp[i];
			st.push(res);
		}
		else{
			string op2 = st.top(); st.pop();
			string op1 = st.top(); st.pop();
			string res = '('+op1+exp[i]+op2+')';
			st.push(res);
		}
	}
	return st.top();
}

string postfix_to_prefix(string exp){
	stack<string>st;
	for(int i=0;i<exp.length();i++){
		if(exp[i]>='0' && exp[i]<='9'){
			string res = "";
			res += exp[i];
			st.push(res);
		}
		else{
			string op2 = st.top(); st.pop();
			string op1 = st.top(); st.pop();
			string res = exp[i]+op1+op2;
			st.push(res);
		}
	}
	return st.top();
}

int main(){
	string exp;
	getline(cin,exp);
	string infix = postfix_to_infix(exp);
	string prefix = postfix_to_prefix(exp);
	cout<<"Infix of the expression: "<<infix<<endl;
	cout<<"Prefix of the expression; "<<prefix<<endl;
	return 0;
}

