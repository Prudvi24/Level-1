#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

void sort_01(vector<int>&arr, int n){
	int pivot = 0;
	int i=0, j=0;
	while(j<n){
		if(arr[j]==0){
			swap(arr[i++],arr[j++]);
		}
		else{
			j++;
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
	sort_01(arr,n);
	display(arr);
	return 0;
}