#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void diagonal_traversal(vector<vector<int>>&arr, int n){
	int i=0,j=0,k=0;
	while(i<n){
		k = i;
		j = 0;
		while(j<n && k<n){
			cout<<arr[j][k]<<" ";
			j++;
			k++;
		}
		i++;
	}
	cout<<endl;
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
	diagonal_traversal(arr,n);
	return 0;
}

