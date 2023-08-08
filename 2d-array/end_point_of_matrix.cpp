#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void end_point_of_matrix(vector<vector<int>>&arr){
	int i=0,j=0;
	int dir = 0;
	cout<<"Enter the loop"<<endl;
	while(i>=0 && j>=0 && i<arr.size() && j<arr[0].size()){
		if(arr[i][j]==1){
			dir++;
		}

		if(dir%4==0){
			j++;
		}
		else if(dir%4==1){
			i++;
		}
		else if(dir%4==2){
			j--;
		}
		else if(dir%4==3){
			i--;
		}
	}

	if(i<0){
		cout<<"("<<i+1<<","<<j<<")"<<endl;
	}
	else if(i>=arr.size()){
		cout<<"("<<i-1<<","<<j<<")"<<endl;
	}
	else if(j<0){
		cout<<"("<<i<<","<<j+1<<")"<<endl;
	}
	else if(j>=arr[0].size()){
		cout<<"("<<i<<","<<j-1<<")"<<endl;
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>arr(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	end_point_of_matrix(arr);
	return 0;
}

