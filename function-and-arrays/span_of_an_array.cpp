#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(const vector<int>&arr){
	int maxe = INT_MIN;
	int mine = INT_MAX;
	for(auto val : arr){
		if(val < mine){
			mine = val;
		}
		if(val > maxe){
			maxe = val;
		}
	}
	cout<<maxe-mine<<endl;
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

