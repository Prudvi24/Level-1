#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void spiral_traversal(vector<vector<int>>&arr){
	int i=0, j=0;
	int y=arr.size()-1, x=arr[0].size()-1;
	int tne = arr.size()*arr[0].size();
	int count=0;
	while(count<tne){
		// row downwards
		if(count<tne){
			for(int a=i,b=j;a<=y;a++){
				cout<<arr[a][b]<<" ";
				count++;
			}
			j++;
		}
		//rightwards column
		if(count<tne){
			for(int a=j,b=y;a<=x;a++){
				cout<<arr[b][a]<<" ";
				count++;
			}
			y--;
		}
		//row upwards
		if(count<tne){
			for(int a=y,b=x;a>=i;a--){
				cout<<arr[a][b]<<" ";
				count++;
			}
			x--;
		}
		//columns leftwards
		if(count<tne){
			for(int a=x,b=i;a>=j;a--){
				cout<<arr[b][a]<<" ";
				count++;
			}
			i++;
		}
	}
	cout<<endl;
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
	spiral_traversal(arr);
	return 0;
}

