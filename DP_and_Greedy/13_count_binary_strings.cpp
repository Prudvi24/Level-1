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

int count_binary_strings_tabulation(int &n){
	vector<vector<int>>dp_arr(2,vector<int>(n+1,0));
	for(int j=0;j<=n;j++){  //column traverse
		for(int i=0;i<2;i++){ //row traverse
			if(j==0 || j==1){
				dp_arr[i][j] = j;
			}
			else{
				if(i==0){
					dp_arr[i][j] = dp_arr[i+1][j-1];
				}
				else{
					dp_arr[i][j] = dp_arr[i-1][j-1] + dp_arr[i][j-1];
				}
			}
		}
	}
	display(dp_arr);
	return dp_arr[0][n]+dp_arr[1][n];
}

int count_binary_strings_variables(int n){
	int a=0,b=0;
	for(int i=1;i<=n;i++){
		if(i==1){
			a=b=1;
		}
		else{
			int tmp = a;
			a = b;
			b = tmp+b;
		}
	}
	return a+b;
}

int main(){
	int n;
	cin>>n;
	int cbs = count_binary_strings_tabulation(n);
	cout<<cbs<<endl;
	cout<<"--------------------------"<<endl;
	cbs = count_binary_strings_variables(n);
	cout<<cbs<<endl;
	return 0;
}

