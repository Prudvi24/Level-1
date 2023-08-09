#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int possible_permutations(int &n){
	int res = 1;
	for(int i=n;i>=1;i--){
		res *= i;
	}
	return res;
}

void all_premutations(string &str){
	int n = str.length();
	int tnp = possible_permutations(n);
	for(int i=0;i<tnp;i++){
		string ps = str;
		int j = ps.length();
		int num = i;
		string ans = "";
		while(j){
			int rem = num%j;
			num /= j;
			ans += ps[rem];
			ps.erase(rem,1);
			j--;
		}
		cout<<ans<<endl;
	}
}

int main(){
	string str;
	cin>>str;
	all_premutations(str);
	return 0;
}

