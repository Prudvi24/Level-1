#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

bool check_palindrome(string &ss){
	int i=0,j=ss.length()-1;
	while(i<j){
		if(ss[i]!=ss[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}

void palindromic_substring(string &str){
	for(int i=0;i<str.length();i++){
		for(int j=1;j<=str.length()-i;j++){
			string ss = str.substr(i,j);
			bool check = check_palindrome(ss);
			if(check){
				cout<<ss<<endl;
			}
		}
	}
}

int main(){
	string str;
	cin>>str;
	palindromic_substring(str);
	return 0;
}

