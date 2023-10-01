#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(stack<int>st){
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}

int eval(char ch, int a, int b){
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
    return -1;
}
int evaluatePostfix(string &exp) {
    // Write your code here.
    stack<int>st;
    for(int i=0;i<exp.length();i++){
        if(exp[i]>='0' && exp[i]<='9'){
        	if(i==0){
        		st.push(exp[i]-'0');
        	}
        	else{
        		if(exp[i-1]>='0' && exp[i-1]<='9'){
        			string res = to_string(st.top())+exp[i];
        			st.pop();
        			st.push(stoi(res));
        		}
        		else{
        			st.push(exp[i]-'0');
        		}
        	}
        }
        else{
        	if(exp[i]==' '){
        		continue;
        	}
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            int res = eval(exp[i], op1, op2);
            st.push(res);
        }
        display(st);
    }
    return st.top();
}


int main(){
	string exp;
	getline(cin,exp);
	int ans = evaluatePostfix(exp);
	cout<<ans<<endl;
	return 0;
}

