#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int possible_painters(vector<int>&boards, int &mid){
	int tp = 1; //total_painters
	int pp = 0;
	for(auto val : boards){
		if(pp+val<=mid){
			pp += val;
		}
		else{
			tp++;
			pp = val;
		}
	}
	return tp;
}

int painter_parition_problem(vector<int>&boards, int k){
	int n = boards.size();
	if(n<k){
		return -1;
	}
	int lo = INT_MIN;
	int hi = 0;
	for(auto val : boards){
		lo = max(lo, val);
		hi += val;
	}
	int ans = -1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		int pp = possible_painters(boards,mid);
		cout<<lo<<"-->"<<hi<<"-->"<<mid<<"-->"<<pp<<endl;
		if(pp<=k){
			ans=mid;
			hi = mid-1;
		}
		else{
			lo = mid+1;
		}
	}
	return ans;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>boards(n,0);
	for(int i=0;i<n;i++){
		cin>>boards[i];
	}
	int ans = painter_parition_problem(boards, k);
	cout<<ans<<endl;
	return 0;
}

