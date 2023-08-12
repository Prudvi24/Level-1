#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void target_subset_sum(vector<int>&arr, int idx, 
	string set_ele, int sos, int tar){
	if(idx==arr.size()){
		if(sos==tar){
			cout<<set_ele+"."<<endl;
		}
		return ;
	}

	target_subset_sum(arr, idx+1,set_ele+to_string(arr[idx])+", ",sos+arr[idx],tar);
	target_subset_sum(arr,idx+1,set_ele,sos,tar);

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
	target_subset_sum(arr,0,"",0,tar);
	return 0;
}

