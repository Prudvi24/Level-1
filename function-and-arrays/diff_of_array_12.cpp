#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display_ans(vector<int>&ans){
	for(int i=0;i<ans.size();i++){
		if(i==0 && ans[i]==0){
			continue;
		}
		cout<<ans[i]<<endl;
	}
}

void solve(vector<int>&arr1,vector<int>&arr2,vector<int>&ans){
	int i=arr1.size()-1;
	int j = arr2.size()-1;
	int s = ans.size()-1;
	int br = 0;
	while(i>=0 && j>=0){
		arr2[j] = arr2[j]-br;
		if(arr2[j] < arr1[i]){
			br = 1;
			ans[s--] = arr2[j--]+10-arr1[i--];
		}
		else{
			br = 0;
			ans[s--] = arr2[j--]-arr1[i--];
		}
	}
	while(j>=0){
		arr2[j] = arr2[j]-br;
		if(arr2[j] < 0){
			arr2[j] += 10;
			ans[s--] = arr2[j];
			br = 1;
		}
		else{
			ans[s--] = arr2[j];
		}
		j--;
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
	vector<int>ans(n2,0);
	solve(arr1,arr2,ans);
	return 0;
}

