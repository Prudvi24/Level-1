#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

void count_sort(vector<int>&arr, int n){
	// find min and max
	int min_ele = INT_MAX;
	int max_ele = INT_MIN;
	for(int i=0;i<n;i++){
		min_ele = min(min_ele, arr[i]);
		max_ele = max(max_ele, arr[i]);
	}

	//build the frequency arr
	int nf = max_ele - min_ele + 1;
	vector<int>freq(nf, 0);
	for(int i=0;i<n;i++){
		freq[arr[i]-min_ele] += 1; 
	}

	// prefix sum
	for(int i=0;i<nf;i++){
		if(i!=0){
			freq[i] += freq[i-1];
		}
	}
	
	//display(freq);
	//sort the array in new array space
	vector<int>newarr(n,0);
	for(int i=n-1;i>=0;i--){
		int idx = freq[arr[i]-min_ele];
		idx--;
		newarr[idx] = arr[i];
		freq[arr[i]-min_ele] -= 1; 
	}

	//fill the original array
	for(int i=0;i<n;i++){
		arr[i] = newarr[i];
	}
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	count_sort(arr,n);
	display(arr);
	return 0;
}

