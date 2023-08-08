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

void swap_ele(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void rotate_90_deg(vector<vector<int>>&arr){
	//transpose a the matrix
	int n=arr.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i<j){
				swap_ele(&arr[i][j],&arr[j][i]);
			}
		}
	}
	cout<<"--------------------"<<endl;
	display(arr);
	cout<<"--------------------"<<endl;
	//swap till middle columns
	for(int i=0;i<n;i++){
		for(int j=0;j<n/2;j++){
			swap_ele(&arr[i][j],&arr[i][n-1-j]);
		}
	}
	display(arr);
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
	rotate_90_deg(arr);
	return 0;
}

