#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(vector<int>&arr){
	int n = arr.size();
	int ss = (int)pow(2,n);
	for(int i=0;i<ss;i++){
		int num = i;
		string ans = "";
		int t = n;
		while(t--){
			int rem = num%2;
			num /= 2;
			if(rem==0){
				ans = "- "+ans;
			}
			else{
				ans = to_string(arr[t])+" "+ans;
			}
		}
		cout<<ans<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	solve(arr);
	return 0;
}

