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

int paint_house_tabulation(vector<vector<int>>&arr){
	int r=0, b=0, g=0;
	for(int i=0;i<arr.size();i++){
		cout<<r<<"-->"<<b<<"-->"<<g<<endl;
		int rtmp, btmp, gtmp;
		for(int j=0;j<arr[0].size();j++){
			if(j==0){
				rtmp = min(b,g)+arr[i][j];
			}
			else if(j==1){
				btmp = min(r,g)+arr[i][j];
			}
			else{
				gtmp = min(r,b)+arr[i][j];
			}
		}
		r=rtmp;
		b=btmp;
		g=gtmp;
	}
	cout<<r<<"-->"<<b<<"-->"<<g<<endl;
	return min(r,min(g,b));
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>>arr(n, vector<int>(3,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<arr[0].size();j++){
			cin>>arr[i][j];
		}
	}
	int ans = paint_house_tabulation(arr);
	cout<<ans<<endl;
	return 0;
}

