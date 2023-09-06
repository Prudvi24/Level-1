#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int kth_smallest_element_in_two_sorted_arrays(vector<int>&arr1, vector<int>&arr2,
												int &n, int &m, int &k){
	if(m<n){
		return kth_smallest_element_in_two_sorted_arrays(arr2,arr1,m,n,k);
	}
	int lo = max(0,k-m);
	int hi = min(n,k);

	while(lo<=hi){
		int mid1 = (lo+hi)/2;
		int mid2 = k-mid1;

		int l1 = mid1-1<0 ? INT_MIN : arr1[mid1-1];
		int l2 = mid2-1<0 ? INT_MIN : arr2[mid2-1];
		int r1 = mid1>=n ? INT_MAX : arr1[mid1];
		int r2 = mid2>=m ? INT_MAX : arr2[mid2];

		if(l1<=r2 && l2<=r1){
			return max(l1,l2);
		}
		else if(l1>r2){
			hi = mid1-1;
		}
		else{
			lo = mid1+1;
		}
	}
	return -1;
}

int main(){
	int n,m;
	cin>>n;
	vector<int>arr1(n,0);
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	cin>>m;
	vector<int>arr2(m,0);
	for(int i=0;i<m;i++){
		cin>>arr2[i];
	}
	int k;
	cin>>k;
	int ans = kth_smallest_element_in_two_sorted_arrays(arr1,arr2,n,m,k);
	cout<<ans<<endl; 
	return 0;
}

