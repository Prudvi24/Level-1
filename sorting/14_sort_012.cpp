#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

void sort_012(vector<int>&arr, int n){
	int i=0;
	int j=0;
	int k=n-1;

	while(j<k){
		if(arr[j]==1){
			j++;
		}
		else if(arr[j]==0){
			swap(arr[i++],arr[j++]);
		}
		else{
			if(arr[k]==2){
				k--;
			}
			else{
				swap(arr[j],arr[k--]);
			}
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
	sort_012(arr,n);
	display(arr);
	return 0;
}

