#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(const vector<int>&arr){
	int maxe = INT_MIN;
	for(auto val : arr){
		if(maxe < val){
			maxe = val;
		}
	}

	for(int i=maxe;i>=1;i--){
		for(int j=0;j<arr.size();j++){
			if(arr[j] >= i){
				cout<<"* ";
			}
			else{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	solve(arr);
	return 0;
}

