#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

long long int check_total_hrs(vector<int>&v, long int mid){
	long long int cv = 0;
	for(int i=0;i<v.size();i++){
		cv += ceil((double)v[i]/(double)mid);
	}
	return cv;
}

int minimumRateToEatBananas(vector<int>&v, int h) {
    // Write Your Code Here
    int hi = INT_MIN;
    long int lo=1;
    for(int i=0;i<v.size();i++){
    	hi = max(hi,v[i]);
    }
    long int ans = hi;
    while(lo<=hi){
    	int mid = (lo+hi)/2;
    	long long int res = check_total_hrs(v,mid);
    	if(res<=h){
    		ans = mid;
    		hi = mid-1;
    	}
    	else{
    		lo = mid+1;
    	}
    }
    return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int h;
	cin>>h;
	int ans = minimumRateToEatBananas(arr, h);
	cout<<ans<<endl;
	return 0;
}