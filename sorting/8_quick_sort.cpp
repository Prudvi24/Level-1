#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

    QuickSort is a sorting algorithm based on the Divide and Conquer algorithm that picks an element as a pivot 
    and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.

*/

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

int partition_array(vector<int>&arr, int lo, int hi, int pivot){
	int i=0;
	int j=0;
	while(j<=hi){
		if(arr[j] <= pivot){
			swap_ele(arr[i],arr[j]);
			i++;
			j++;
		}
		else{
			j++;
		}
	}
	return i-1;
}

void quick_sort(vector<int>&arr, int lo, int hi){
	if(lo>=hi){
		return ;
	}
	int pidx = partition_array(arr, lo, hi, arr[hi]);
	quick_sort(arr, lo, pidx-1);
	quick_sort(arr, pidx+1, hi);
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	quick_sort(arr,0,n-1);
	display(arr);
	return 0;
}