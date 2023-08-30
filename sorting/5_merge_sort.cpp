#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(const vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

void merge_two_sorted_array(vector<int>&arr, int p, int q, int r){
	int n = q-p+1;
	int m = r-q;
	vector<int>left_array(n,0);
	vector<int>right_array(m,0);
	for(int i=0;i<n;i++){
		left_array[i] = arr[p+i];
	}
	for(int j=0;j<m;j++){
		right_array[j] = arr[q+1+j];
	}
	int i=0;
	int j=0;
	int k=p;
	while(i<n && j<m){
		if(left_array[i] < right_array[j]){
			arr[k++] = left_array[i++];
		}
		else{
			arr[k++] = right_array[j++];
		}
	}

	while(i<n){
		arr[k++]=left_array[i++];
	}
	while(j<m){
		arr[k++]=right_array[j++];
	}
}

void merge_sort_algo(vector<int>&arr,int l, int r){
	if(l>=r){
		return ;
	}
	int mid = (r+l)/2;
	merge_sort_algo(arr,l,mid);
	merge_sort_algo(arr,mid+1,r);
	merge_two_sorted_array(arr,l,mid,r);
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	merge_sort_algo(arr,0,n-1);
	display(arr);
	return 0;
}

