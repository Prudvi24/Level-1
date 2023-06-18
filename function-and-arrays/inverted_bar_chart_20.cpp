#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(vector<int>&arr){
	int maxe = INT_MIN;
	for(int i=0;i<arr.size();i++){
		if(maxe < arr[i]){
			maxe = arr[i];
		}
	}

	for(int i=0;i<maxe;i++){
		for(int j=0;j<arr.size();j++){
			if(arr[j] > i){
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

