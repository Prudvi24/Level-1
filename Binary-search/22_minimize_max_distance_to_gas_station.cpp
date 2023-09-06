#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

long double min_max_distance_to_gas_station(vector<int>&arr, int &k){
	int n = arr.size();
	priority_queue<pair<long double, int>>pq;
	for(int i=0;i<n-1;i++){
		pq.push({arr[i+1]-arr[i],i});
	}
	vector<int>gsp(n-1,0); //gas station placement
	for(int gs=1;gs<=k;gs++){
		pair<long double, int> tp = pq.top();
		pq.pop();
		int gspai = tp.second; // gas station placed after index
		long double dbgs = arr[gspai+1]-arr[gspai]; // difference between the gas station
		gsp[gspai]++;
		long double newdiff = dbgs / (long double)(gsp[gspai]+1);
		pq.push({newdiff, gspai});
	}
	return pq.top().first;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	long double ans = min_max_distance_to_gas_station(arr,k);
	cout<<ans<<endl;
	return 0;
}

