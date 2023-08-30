#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

1. You are given an array(arr) of integers.
2. You have to find the k-th smallest element in the given array using the quick-select algorithm.

*/

void display(vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int partition_array(vector<int>&arr, int lo, int hi, int pivot){
	int i=lo;
	int j=lo;
	while(j<=hi){
		if(arr[j] > pivot){
			j++;
		}
		else{
			swap(arr[i],arr[j]);
			i++;
			j++;
		}
	}
	//display(arr);
	return i-1;
}

int quick_select(vector<int>&arr, int lo, int hi, int tar){
	if(lo>hi){
		return -1;
	}
	int pid = partition_array(arr,lo,hi,arr[hi]);
	
	if(tar==pid){
		return arr[pid];
	}
	else if(tar > pid){
		return quick_select(arr, pid+1,hi,tar);
	}
	else{
		return quick_select(arr,lo,pid-1,tar);
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
	int res = quick_select(arr,0,n-1,tar-1);
	cout<<res<<endl;
	return 0;
}

