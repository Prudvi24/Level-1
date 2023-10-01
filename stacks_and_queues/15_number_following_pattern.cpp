#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

string number_following_pattern(string &s){
	stack<int>d;
	stack<int>i;
	int count = 1;
	string ans="";
	if(s[0]=='D'){
		d.push(count);
	}
	else{
		i.push(count);
	}
	for(int x=0;x<s.length();x++){
		if(s[x]=='D'){
			count++;
			d.push(count);
		}
		else{
			while(!d.empty()){
				ans += to_string(d.top());
				d.pop();
			}
			while(!i.empty()){
				ans += to_string(i.top());
				i.pop();
			}
			count++;
			i.push(count);
		}
	}
	while(!d.empty()){
		ans += to_string(d.top());
		d.pop();
	}
	while(!i.empty()){
		ans += to_string(i.top());
		i.pop();
	}
	return ans;
}

int main(){
	string str;
	cin>>str;
	string ans = number_following_pattern(str);
	cout<<ans<<endl;
	return 0;
}

