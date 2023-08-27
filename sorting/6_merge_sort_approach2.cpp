#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&ans){
	for(auto val : ans){
		cout<<val<<" ";
	}
	cout<<endl;
}

vector<int> merge_two_sorted_arrays(vector<int>&larr, vector<int>rarr){
	int n = larr.size();
	int m = rarr.size();
	vector<int>res(n+m,0);
	int i=0, j=0, k=0;
	while(i<n && j<m){
		if(larr[i] < rarr[j]){
			res[k++] = larr[i++];
		}
		else{
			res[k++] = rarr[j++];
		}
	}
	while(i<n){
		res[k++] = larr[i++];
	}
	while(j<m){
		res[k++] = rarr[j++];
	}
	return res;
}

vector<int> merge_sort_algo(vector<int>&arr, int l, int r){
	if(l==r){
		vector<int>bres;
		bres.push_back(arr[l]);
		return bres;
	}
	else if(r<l){
		vector<int>bres;
		return bres;
	}

	int mid = (r+l)/2;

	vector<int>left_arr = merge_sort_algo(arr,l,mid);
	vector<int>right_arr = merge_sort_algo(arr,mid+1,r);
	vector<int>merged = merge_two_sorted_arrays(left_arr,right_arr);
	return merged;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int>ans = merge_sort_algo(arr,0,n-1);
	display(ans);
	return 0;
}

