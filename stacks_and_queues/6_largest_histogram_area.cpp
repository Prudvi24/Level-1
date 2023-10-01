#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<int>&vec){
	for(auto val : vec){
		cout<<val<<" ";
	}
	cout<<endl;
}

vector<int> smallest_element_on_left(vector<int>&arr, int &n){
	stack<int>st;
	st.push(-1);
	vector<int>sel(n,0);
	for(int i=0;i<n;i++){
		while(st.top()!=-1 && arr[st.top()]>=arr[i]){
			st.pop();
		}
		sel[i] = st.top();
		st.push(i);
	}
	return sel;
}

vector<int> smallest_element_on_right(vector<int>&arr, int &n){
	stack<int>st;
	st.push(n);
	vector<int>ser(n,0);
	for(int i=n-1;i>=0;i--){
		while(st.top()!=n && arr[st.top()]>=arr[i]){
			st.pop();
		}
		ser[i] = st.top();
		st.push(i);
	}
	return ser;
}

int largest_histogram_area(vector<int>&arr, int &n){
	vector<int>sel = smallest_element_on_left(arr,n);
	vector<int>ser = smallest_element_on_right(arr,n);
	display(sel);
	display(ser);
	int max_area = 0;
	for(int i=0;i<n;i++){
		int area = ((i-sel[i]) + (ser[i]-i-1)) * arr[i];
		if(area > max_area){
			max_area = area;
		}
	}
	return max_area;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans = largest_histogram_area(arr,n);
	cout<<ans<<endl;
	return 0;
}

