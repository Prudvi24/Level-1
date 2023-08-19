#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<vector<int>>&dp){
	for(auto vec : dp){
		for(auto val : vec){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}

int aibjck_subsquence_tabulation(string &str){
	int n = str.length();
	vector<vector<int>>dp(3,vector<int>(n+1,0));
	for(int j=0;j<=n;j++){
		for(int i=0;i<3;i++){
			if(j==0){
				dp[i][j] = 0;
			}
			else{
				if(i==0 && str[j-1]=='a'){
					dp[i][j] = dp[i][j-1]*2 + 1;
					dp[i+1][j] = dp[i+1][j-1];
					dp[i+2][j] = dp[i+2][j-1];
					break;
				}
				else if(i==1 && str[j-1]=='b'){
					dp[i-1][j] = dp[i-1][j-1];
					dp[i][j] = dp[i][j-1]*2 + dp[i-1][j-1];
					dp[i+1][j] = dp[i+1][j-1];
					break;
				}
				else if(i==2 && str[j-1]=='c'){
					dp[i-2][j] = dp[i-2][j-1];
					dp[i-1][j] = dp[i-1][j-1];
					dp[i][j] = dp[i][j-1]*2 + dp[i-1][j-1];
					break;
				}
			}
		}
	}
	display(dp);
	return dp[2][n];
}

int aibjck_subsquence(string str){
	int a=0, b=0, c=0;
	for(int i=0;i<str.length();i++){
		if(str[i]=='a'){
			a = 2*a+1;
		}
		else if(str[i]=='b'){
			b = 2*b+a;
		}
		else{
			c = 2*c+b;
		}
	}
	return c;
}

int main(){
	string str;
	cin>>str;
	int ans = aibjck_subsquence_tabulation(str);
	cout<<ans<<endl;
	cout<<"--------------------------------"<<endl;
	int res = aibjck_subsquence(str);
	cout<<res<<endl;
	return 0;
}