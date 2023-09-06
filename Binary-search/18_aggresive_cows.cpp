#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int cows_arrange(vector<int>&stalls, int &mid){
	int total_cows = 1;
	int prev = stalls[0];
	for(int i=1;i<stalls.size();i++){
		if(stalls[i]-prev>=mid){
			total_cows++;
			prev = stalls[i];
		}
	}
	return total_cows;
}

int aggresive_cows(vector<int>&stalls, int &k){
	int n = stalls.size();
	sort(stalls.begin(), stalls.end());
	if(n==2){
		return stalls[1]-stalls[0];
	}
	int lo = 1;
	int hi = stalls[n-1]-stalls[0];
	int ans = -1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		int check = cows_arrange(stalls,mid);
		cout<<lo<<"-->"<<hi<<"-->"<<mid<<"-->"<<check<<endl;
		if(check>=k){
			ans = mid;
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}
	return ans;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans = aggresive_cows(arr,k);
	cout<<ans<<endl;
	return 0;
}

