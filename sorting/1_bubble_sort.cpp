#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&arr){
	for(auto val : arr){
		cout<<val<<" ";
	}
	cout<<endl;
}

/*

    In this algorithm, 

        traverse array from left and compare adjacent elements and the higher one is placed at right side. 
        In this way, the largest element is moved to the rightmost end at first. 
        This process is then continued to find the second largest and place it and so on until the data is sorted.

*/

void bubble_sort(vector<int>&arr, int &n){
	for(int i=n-2;i>=0;i--){  // n-1 iterations (wihich brings the greatest elements to the last
		int flag = true;
		for(int j=0;j<=i;j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag=false;
			}
		}
		if(flag==true){
			break;
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
	bubble_sort(arr,n);
	display(arr);
	return 0;
}

