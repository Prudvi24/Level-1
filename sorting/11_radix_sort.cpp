#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

void count_sort(vector<int>&arr, int &n, int &exp){
	// Build freq arr
	vector<int>freq(10,0);
	for(int i=0;i<n;i++){
		int rem = (arr[i]/exp)%10;
		freq[rem] += 1;
	}

	//build prefix sum
	for(int i=0;i<10;i++){
		if(i>0){
			freq[i] += freq[i-1];
		}
	}

	// sort in new array
	vector<int>newarr(n,0);
	for(int i=n-1;i>=0;i--){
		int rem = (arr[i]/exp)%10;
		int idx = freq[rem];
		idx--;
		newarr[idx] = arr[i];
		freq[rem]--;
	}

	//copy in original array
	for(int i=0;i<n;i++){
		arr[i] = newarr[i];
	}
}

void radix_sort(vector<int>&arr, int n){
	int maxe = INT_MIN;
	for(int i=0;i<n;i++){
		maxe = max(maxe, arr[i]);
	}

	//count no of digits
	int num = maxe, count = 0;
	while(num){
		num /= 10;
		count++;
	}
	int exp = 1;
	for(int i=1;i<=count;i++){
		count_sort(arr, n, exp);
		exp *= 10;
	}
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	radix_sort(arr,n);
	display(arr);
	return 0;
}