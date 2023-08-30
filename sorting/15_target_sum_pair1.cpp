#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void target_sum_pair(vector<int>&arr, int &n, const int &tar){
	sort(arr.begin(),arr.end());
	int i=0, j=n-1;
	while(i<j){
		if(tar == (arr[i]+arr[j])){
			cout<<arr[i]<<", "<<arr[j]<<endl;
			i++;
			j--;
		}
		else if(tar > (arr[i]+arr[j])){
			i++;
		}
		else{
			j--;
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int tar;
	cin>>tar;
	target_sum_pair(arr,n,tar);
	return 0;
}

