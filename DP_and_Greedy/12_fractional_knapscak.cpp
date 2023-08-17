#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

class Pair{
	public:
		int val;
		int wt;
		float vpw;

		Pair(int val, int wt, int vpw){
			this->val = val;
			this->wt = wt;
			this->vpw = vpw;
		}

		Pair(){

		}
};

static bool sortByThird(Pair *p1, Pair *p2){
	float val1 = p1->vpw;
	float val2 = p2->vpw;
	return val1 > val2;
}

void display(vector<Pair*>&pair_arr){
	for(auto pp : pair_arr){
		cout<<pp->val<<"-->"<<pp->wt<<"-->"<<pp->vpw<<endl;
	}
}

int fractional_knapsack(vector<int>&val, vector<int>&wt, int &n, int &cap){
	vector<Pair*>pair_arr;
	for(int i=0;i<n;i++){
		float vpm= val[i]/wt[i];
		Pair *p = new Pair(val[i],wt[i],vpm);
		pair_arr.push_back(p);
	}
	sort(pair_arr.begin(), pair_arr.end(), sortByThird);
	//display(pair_arr);
	int i=0;
	float mcp = 0;
	while(i<n && cap > pair_arr[i]->wt){
		mcp += pair_arr[i]->val;
		cap -= pair_arr[i]->wt;
		i++;
	}
	if(cap > 0){
		mcp += (float(cap)/float(pair_arr[i]->wt))*float(pair_arr[i]->val);
	}
	return mcp;
}

int main(){
	int n;
	cin>>n;
	vector<int>val(n,0);
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	vector<int>wt(n,0);
	for(int i=0;i<n;i++){
		cin>>wt[i];
	}
	int cap;
	cin>>cap;
	float maxcap = fractional_knapsack(val,wt,n,cap);
	cout<<maxcap<<endl;
	return 0;
}