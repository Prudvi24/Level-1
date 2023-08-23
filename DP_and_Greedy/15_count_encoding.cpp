#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&dp){
	for(auto val : dp){
		cout<<val<<" ";
	}
	cout<<endl;
}

int count_encoding(string &str){
	int n = str.length();
	vector<int>dp(n,0);
	if(str[0]=='0'){
		dp[0] = 0;
	}
	else{
		dp[0] = 1;
	}
	for(int i=1;i<n;i++){
		if(str[i-1]=='0' && str[i]=='0'){      // if both are zero
			dp[i] = 0;
		}
		else if(str[i-1]=='0' && str[i]!='0'){    // zero and not zero
			dp[i] = dp[i-1];
		}
		else if(str[i-1]!='0' && str[i]=='0'){   // not zero and zero
			int num = stoi(str.substr(i-1,2));
			if(i>=2 && num<=26){
				dp[i] = dp[i-2];
			}
			else{
				if(num<=26){
					dp[i]=1;
				}
				else{
					dp[i]=0;
				}
			}
		}
		else{
			int num = stoi(str.substr(i-1,2));   // not zero and not zero
			if(i>=2 && num<=26){
				dp[i] = dp[i-1]+dp[i-2];
			}
			else{
				if(num<=26){
					dp[i] = dp[i-1]+1;
				}
				else{
					dp[i] = dp[i-1];
				}
			}
		}
	}
	display(dp);
	return dp[n-1];
}

int main(){
	string str;
	cin>>str;
	int res = count_encoding(str);
	cout<<res<<endl;
	return 0;
}

