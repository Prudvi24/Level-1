#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display_ans(const vector<int>&ans){
	for(int i=0;i<ans.size();i++){
		if(i==0 && ans[i]==0){
			continue;
		}
		cout<<ans[i]<<endl;
	}
	cout<<endl;
}

void solve(const vector<int>&arr1, const vector<int>&arr2){
	int i = arr1.size()-1;
	int j = arr2.size()-1;
	int s = (arr1.size() > arr2.size()) ? arr1.size() : arr2.size();
	vector<int>ans(s+1,0);
	int carry = 0;
	while(i>=0 && j>=0){
		int pa = arr1[i]+arr2[j]+carry;
		carry = pa/10;
		ans[s] = pa%10;
		i--;
		j--;
		s--;
	}
	while(i>=0){
		int pa = arr1[i]+carry;
		carry = pa/10;
		ans[s] = pa%10;
		i--;
		s--;
	}
	while(j>=0){
		int pa = arr2[j]+carry;
		carry = pa/10;
		ans[s] = pa%10;
		j--;
		s--;
	}
	if(carry){
		ans[s] = carry;
	}
	display_ans(ans);
}

int main(){
	int n1,n2;
	cin>>n1;
	vector<int>arr1(n1,0);
	for(int i=0;i<n1;i++){
		cin>>arr1[i];
	}
	cin>>n2;
	vector<int>arr2(n2,0);
	for(int i=0;i<n2;i++){
		cin>>arr2[i];
	}
	solve(arr1,arr2);
	return 0;
}

