#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(const vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

vector<int> merge_two_sorted_arrays(vector<int>&arr1, vector<int>&arr2){
	int n = arr1.size();
	int m = arr2.size();
	vector<int>res(n+m, 0);
	int i=0;
	int j=0;
	int k=0;
	while(i<n && j<m){
		if(arr1[i]<arr2[j]){
			res[k++] = arr1[i++];
		}
		else{
			res[k++] = arr2[j++];
		}
	}
	while(i<n){
		res[k++] = arr1[i++];
	}
	while(j<m){
		res[k++] = arr2[j++];
	}
	return res;
}

int main(){
	int n,m;
	cin>>n;
	vector<int>arr1(n,0);
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	cin>>m;
	vector<int>arr2(m,0);
	for(int i=0;i<m;i++){
		cin>>arr2[i];
	}
	vector<int>ans = merge_two_sorted_arrays(arr1,arr2);
	display(ans);
	return 0;
}

