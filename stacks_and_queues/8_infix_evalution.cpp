#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(stack<char>st){
	while(!st.empty()){
		cout<<st.top()<<", ";
		st.pop();
	}
	cout<<endl;
}
void display(stack<int>st){
	while(!st.empty()){
		cout<<st.top()<<", ";
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

int evalution(char ch, int a, int b){
	if(ch=='+'){
		return a+b;
	}
	else if(ch=='-'){
		return a-b;
	}
	else if(ch=='*'){
		return a*b;
	}
	else if(ch=='/'){
		return a/b;
	}
	return 0;
}

int infix_evalution(string &str){
	stack<char>operators;
	stack<int>operands;
	string ans = "";
	for(int i=0;i<str.length();i++){
		char ch = str[i];
		if(str[i]=='('){
			operators.push(str[i]);
		}
		else if(str[i]==')'){
			while(!operators.empty() && operators.top()!='('){
				int op2 = operands.top(); operands.pop();
				int op1 = operands.top(); operands.pop();
				int ans = evalution(operators.top(), op1, op2);
				operators.pop();
				operands.push(ans);
			}
			operators.pop();
		}
		else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
			if(!operators.empty() && precedence(operators.top())>=precedence(str[i])){
				int op2 = operands.top(); operands.pop();
				int op1 = operands.top(); operands.pop();
				int ans = evalution(operators.top(), op1, op2);
				operators.pop();
				operands.push(ans);
			}
			operators.push(str[i]);
		}
		else{
			if(i==0){
				operands.push(str[i]-'0');
			}
			if(str[i-1]-'0'>=0 && str[i-1]-'0'<=9){
				string nwstr = to_string(operands.top())+str[i];
				operands.pop();
				operands.push(stoi(nwstr));
			}
			else{
				operands.push(str[i]-'0');
			}
		}
		
		cout<<"Operator stack: "<<endl;
		display(operators);
		cout<<"Operand stack: "<<endl;
		display(operands);
		cout<<"-------------------------"<<endl;

	}
	while(!operators.empty()){
		int op2 = operands.top(); operands.pop();
		int op1 = operands.top(); operands.pop();
		int ans = evalution(operators.top(), op1, op2);
		operators.pop();
		operands.push(ans);
	}
	return operands.top();
}

int main(){
	string str;
	cin>>str;
	int ans = infix_evalution(str);
	cout<<ans<<endl;
	return 0;
}