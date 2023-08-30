#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<long int>&dates){
	for(auto val : dates){
		cout<<val<<" ";
	}
	cout<<endl;
}

void count_sort(vector<long int>&arr, int div, int mod, int range){
	int n = arr.size();
	
	// build freq array
	vector<int>freq(range,0);
	for(int i=0;i<n;i++){
		int idx = (arr[i]/div)%mod;
		freq[idx]++;
	}

	//prefix sum of freq array
	for(int i=0;i<range;i++){
		if(i!=0){
			freq[i] += freq[i-1];
		}
	}

	//sort on new array
	vector<long int>newarr(n,0);
	for(int i=n-1;i>=0;i--){
		int pos = (arr[i]/div)%mod;
		int idx = --freq[pos];
		newarr[idx] = arr[i];
	}

	//copy to the original array
	for(int i=0;i<n;i++){
		arr[i] = newarr[i];
 	}

}

void sort_dates(vector<long int>&arr, int &n){
	count_sort(arr,1000000,100,32);  //count sort on dates
	count_sort(arr,10000, 100, 13);  //count sort on months
	count_sort(arr, 1, 10000, 2501); //count sort on years
}

int main(){
	int n;
	cin>>n;
	vector<long int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort_dates(arr,n);
	display(arr);
	return 0;
}

