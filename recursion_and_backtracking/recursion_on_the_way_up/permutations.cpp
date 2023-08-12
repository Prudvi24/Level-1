#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void permutations(string str, string asf){
	if(str.empty()){
		cout<<asf<<endl;
		return ;
	}
	for(int i=0;i<str.length();i++){
		char ch = str[i];
		string left_str = str.substr(0,i);
		string right_str = str.substr(i+1);
		string res = left_str+right_str;
		permutations(res,asf+ch);
	}
}

int main(){
	string str;
	cin>>str;
	permutations(str,"");
	return 0;
}