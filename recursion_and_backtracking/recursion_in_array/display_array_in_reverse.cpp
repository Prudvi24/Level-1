#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display_array_reverse(vector<int>&arr, int idx){
	if(idx==arr.size()){
		return ;
	}
	display_array_reverse(arr,idx+1);
	cout<<arr[idx]<<endl;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	display_array_reverse(arr,0);
	return 0;
}

