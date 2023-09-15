#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<vector<int>>&intervals){
	for(auto vec : intervals){
		for(auto val : vec){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}

static bool sortByFirst(vector<int>&a, vector<int>&b){
	return a[0] < b[0];
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
	sort(intervals.begin(), intervals.end(), sortByFirst);
	stack<vector<int>>st;
	st.push(intervals[0]);
	for(auto vec : intervals){
		vector<int>tp = st.top();
		if(tp[1] >= vec[0]){
			st.pop();
			if(vec[1] > tp[1]){
				tp[1] = vec[1];
			}
			st.push(tp);
		}
		else{
			st.push(vec);
		}
	}
	vector<vector<int>>ans(st.size(),vector<int>(2,0));
	int count = st.size();
	while(!st.empty()){
		ans[count-1] = st.top();
		count--;
		st.pop();
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>>arr(n,vector<int>(2,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cin>>arr[i][j];
		}
	}
	vector<vector<int>>ans = mergeIntervals(arr);
	cout<<"----------"<<endl;
	display(ans);
	return 0;
}