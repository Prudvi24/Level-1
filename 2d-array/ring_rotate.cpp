#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display_oned(vector<int>&capshell){
	for(auto val : capshell){
		cout<<val<<" ";
	}
	cout<<endl;
}

void display_twod(vector<vector<int>>&arr){
	for(auto vec:arr){
		for(auto val : vec){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}

void fillarr(vector<vector<int>>&arr, vector<int>&capshell,
	int minrow, int mincol, int maxrow, int maxcol){
	//capture the left most column
	int idx = 0;
	for(int i=minrow,j=mincol;i<=maxrow;i++){
		arr[i][j] = capshell[idx];
		idx++;
	}
	mincol++;
	//capture the bottom row
	for(int i=mincol,j=maxrow;i<=maxcol;i++){
		arr[j][i]=capshell[idx];
		idx++;
	}
	maxrow--;
	//capture the right column
	for(int i=maxrow,j=maxcol;i>=minrow;i--){
		arr[i][j] = capshell[idx];
		idx++;
	}
	maxcol--;
	//capture the top row
	for(int i=maxcol,j=minrow;i>=mincol;i--){
		arr[j][i] = capshell[idx];
		idx++;
	}
	minrow++;
}

void rotate_elements(vector<int>&capshell,int i, int j){
	while(i<j){
		int temp = capshell[i];
		capshell[i] = capshell[j];
		capshell[j] = temp;
		i++;
		j--;
	}
}

void rotate_capshell(vector<int>&capshell, int &r){
	r = r%capshell.size();
	rotate_elements(capshell,0,r-1);
	rotate_elements(capshell,r,capshell.size()-1);
	rotate_elements(capshell,0,capshell.size()-1);
}

void fillcapshell(vector<vector<int>>&arr, vector<int>&capshell,
	int minrow, int mincol, int maxrow, int maxcol){
	//capture the left most column
	for(int i=minrow,j=mincol;i<=maxrow;i++){
		capshell.push_back(arr[i][j]);
	}
	mincol++;
	//capture the bottom row
	for(int i=mincol,j=maxrow;i<=maxcol;i++){
		capshell.push_back(arr[j][i]);
	}
	maxrow--;
	//capture the right column
	for(int i=maxrow,j=maxcol;i>=minrow;i--){
		capshell.push_back(arr[i][j]);
	}
	maxcol--;
	//capture the top row
	for(int i=maxcol,j=minrow;i>=mincol;i--){
		capshell.push_back(arr[j][i]);
	}
	minrow++;
	display_oned(capshell);
}

void ring_rotate(vector<vector<int>>&arr,int &s, int &r){
	int minrow = s-1, mincol = s-1;
	int maxrow = arr.size()-s, maxcol = arr[0].size()-s;
	vector<int>capshell;
	fillcapshell(arr,capshell,minrow,mincol,maxrow,maxcol);
	rotate_capshell(capshell,r);
	display_oned(capshell);
	fillarr(arr,capshell,minrow,mincol,maxrow,maxcol);
	display_twod(arr);
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
	int s,r;
	cin>>s>>r;
	ring_rotate(arr,s,r);
	return 0;
}