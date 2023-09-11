#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int findCelebrity(vector<vector<int>>&arr, int n) {
 	// Write your code here.
	 stack<int>st;
	 for(int i=0;i<n;i++){
		 st.push(i);
	 }
	 while(st.size()>1){
		 int p1 = st.top(); st.pop();
		 int p2 = st.top(); st.pop();
		 if(arr[p1][p2]==1){
			 st.push(p2);
		 }
		 else{
			 st.push(p1);
		 }
	 }
	 int candidate = st.top();
	 for(int i=0;i<n;i++){
		 if(arr[candidate][i]){
			 return -1;
		 }
		 if(i!=candidate && arr[i][candidate]==0){
			 return -1;
		 }
	 }
	 return candidate;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>>arr(n,vector<int>(n,0));

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}

	int ans = findCelebrity(arr, n);
	cout<<ans<<endl;
	return 0;
}

