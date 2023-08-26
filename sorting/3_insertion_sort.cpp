#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

void insertion_sort(vector<int>&arr, int n){
	for(int i=1;i<=n-1;i++){
		for(int j=i;j>=0;j--){
			if(arr[j-1] > arr[j]){
				int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
			else{
				break;
			}
		}
	}
}


void insertionSort(vector<int>&arr, int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	insertion_sort(arr, n);
	display(arr);
	cout<<"--------------"<<endl;
	insertionSort(arr,n);
	display(arr);
	return 0;
}

