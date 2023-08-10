#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display_array(vector<int>&arr, int idx){
	if(idx==arr.size()){
		cout<<endl;
		return ;
	}
	cout<<arr[idx]<<" ";
	display_array(arr,idx+1);
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	display_array(arr,0);
	return 0;
}

