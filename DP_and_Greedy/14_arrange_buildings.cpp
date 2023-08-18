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

int arrange_buildings_tabulation(int n){
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
	cout<<"For one arrangement on oneside of the road, there will be n arrangements on other side of the road"<<endl;
	display(dp_arr);
	int res = dp_arr[0][n]+dp_arr[1][n];
	return res*res;
}

int arrange_buildings_variables(int n){
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
	int ans = a+b;
	return ans*ans;
}



int main(){
	int n;
	cin>>n;
	int nowab = arrange_buildings_tabulation(n);
	cout<<nowab<<endl;
	cout<<"---------------------"<<endl;
	nowab = arrange_buildings_variables(n);
	cout<<nowab<<endl;
	return 0;
}

