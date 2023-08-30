#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

Selection sort is a simple and efficient sorting algorithm that works by 
repeatedly selecting the smallest (or largest) element from the unsorted portion of the list
and moving it to the sorted portion of the list. 

*/

void display(vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

void selection_sort(vector<int>&arr, int n){
	for(int i=0;i<=n-2;i++){
		int minele = i;
		for(int j = i+1;j<n;j++){
			if(arr[minele] > arr[j]){
				minele = j;
			}
		}
		if(minele!=i){
			int tmp = arr[minele];
			arr[minele] = arr[i];
			arr[i] = tmp;
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
	selection_sort(arr, n);
	display(arr);
	return 0;
}