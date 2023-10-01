#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(stack<char>st){
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}

void display(stack<string>st){
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}

int precedence(char ch){
	if(ch=='+'){
		return 1;
	}
	else if(ch=='-'){
		return 1;
	}
	else if(ch=='*'){
		return 2;
	}
	else if(ch=='/'){
		return 2;
	}
	return -1;
}

string evaluation_postfix(char ch, string a, string b){
	return a+b+ch;
}

string evaluation_prefix(char ch, string a, string b){
	return ch+a+b;
}

string infix_conversion_postfix(string exp){
	stack<char>operators;
	stack<string>operands;
	for(int i=0;i<exp.length();i++){
		if(exp[i]=='('){
			operators.push(exp[i]);
		}
		else if(exp[i]==')'){
			while(!operators.empty() && operators.top()!='('){
				string op2 = operands.top(); operands.pop();
				string op1 = operands.top(); operands.pop();
				char ch = operators.top(); operators.pop();
				string res = evaluation_postfix(ch,op1, op2);
				operands.push(res);
			}
			operators.pop();
		}
		else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
			while(!operators.empty() && precedence(operators.top())>=precedence(exp[i])){
				string op2 = operands.top(); operands.pop();
				string op1 = operands.top(); operands.pop();
				char ch = operators.top(); operators.pop();
				string res = evaluation_postfix(ch,op1, op2);
				operands.push(res);
			}
			operators.push(exp[i]);
		}
		else{
			string ans = "";
			ans += exp[i];
			operands.push(ans);
		}
		display(operators);
		display(operands);
		cout<<"-----------------------"<<endl;
	}
	while(!operators.empty()){
		string op2 = operands.top(); operands.pop();
		string op1 = operands.top(); operands.pop();
		char ch = operators.top(); operators.pop();
		string res = evaluation_postfix(ch,op1,op2);
		operands.push(res);
	}
	return operands.top();
}

int main(){
	string exp;
	cin>>exp;
	string postfix = infix_conversion_postfix(exp);
	//string prefix = infix_conversion_prefix(exp);
	cout<<"postfix: "<<postfix<<endl;
	//cout<<"Prefix: "<<prefix<<endl;
	return 0;
}

