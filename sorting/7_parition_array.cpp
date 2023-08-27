#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

void swap_ele(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void partition_array(vector<int>&arr, int &n, int pivot){
	int i=0;
	int j=0;
	while(j<n){
		if(arr[j] > pivot){
			j++;
		}
		else{
			swap_ele(arr[i],arr[j]);
			i++;
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
	int pivot;
	cin>>pivot;
	partition_array(arr,n, pivot);
	display(arr);
	return 0;
}

