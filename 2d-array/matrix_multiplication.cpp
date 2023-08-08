#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<vector<int>>&arr){
	for(auto vec : arr){
		for(auto val : vec){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}

void solve(const vector<vector<int>>&arr1, 
	const vector<vector<int>>&arr2){
	if(arr1[0].size()!=arr2.size()){
		cout<<"Not allowed"<<endl;
		return ;
	}
	vector<vector<int>>ans(arr1.size(),vector<int>(arr2[0].size(),0));
	
	for(int i=0;i<arr1.size();i++){
		for(int j=0;j<arr2[0].size();j++){
			int res = 0;
			for(int k=0;k<arr1[0].size();k++){
				res += (arr1[i][k] * arr2[k][j]);
			}
			ans[i][j] = res;
		}
	}
	display(ans);
}

int main(){
	int n1, m1;
	cin>>n1>>m1;
	vector<vector<int>>arr1(n1,vector<int>(m1,0));
	for(int i=0;i<n1;i++){
		for(int j=0;j<m1;j++){
			cin>>arr1[i][j];
		}
	}

	int n2, m2;
	cin>>n2>>m2;
	vector<vector<int>>arr2(n2,vector<int>(m2,0));
	for(int i=0;i<n2;i++){
		for(int j=0;j<m2;j++){
			cin>>arr2[i][j];
		}
	}
	solve(arr1,arr2);
	return 0;
}

