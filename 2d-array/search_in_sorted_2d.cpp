#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void search_in_sorted_2d(vector<vector<int>>&arr, int &n, int &tar){
	int i=0,j=n-1;
	while(i>=0 && j>=0 && i<n && j<n){
		if(tar==arr[i][j]){
			cout<<i<<" "<<j<<endl;
			return ;
		}
		else if(tar > arr[i][j]){
			i++;
		}
		else if(tar < arr[i][j]){
			j--;
		}
	}
	cout<<"Not found"<<endl;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>>arr(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	int tar;
	cin>>tar;
	search_in_sorted_2d(arr,n,tar);
	return 0;
}

