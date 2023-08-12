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

void knights_tour(vector<vector<int>>&arr, int r, int c, int umove){
	if(r>=arr.size() || r<0 || c<0 || c>=arr.size() || arr[r][c]!=0){
		return ;
	}
	if(umove==(arr.size()*arr.size())){
		arr[r][c]=umove;
		display(arr);
		arr[r][c]=0;
		cout<<"------------------"<<endl;
		return ;
	}		
	arr[r][c] = umove;
	knights_tour(arr,r-2,c+1,umove+1);
	knights_tour(arr,r-1,c+2,umove+1);
	knights_tour(arr,r+1,c+2,umove+1);
	knights_tour(arr,r+2,c+1,umove+1);
	
	knights_tour(arr,r+2,c-1,umove+1);
	knights_tour(arr,r+1,c-2,umove+1);
	knights_tour(arr,r-1,c-2,umove+1);
	knights_tour(arr,r-2,c-1,umove+1);
	arr[r][c]=0;
}

int main(){
	int n,row,col;
	cin>>n>>row>>col;
	vector<vector<int>>arr(n,vector<int>(n,0));
	knights_tour(arr,row,col,1);
	return 0;
}

