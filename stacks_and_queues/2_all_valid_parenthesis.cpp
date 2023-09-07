#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<string>balancedall(int n,string asf,int open, int close){
    if(open+close==n){
    	vector<string>bres;
    	bres.push_back(asf);
    	return bres;
    }
    else if(open+close>n){
    	vector<string>bres;
    	return bres;
    }
    vector<string>res;
    vector<string>vpfl;
    if(open < n/2){
    	vpfl = balancedall(n, asf+'(',open+1,close);
    }
    vector<string>vpfr;
    if(open > close){
     	vpfr = balancedall(n, asf+')',open,close+1);
    }
    for(auto val : vpfl){
        res.push_back(val);
    }
    for(auto val : vpfr){
        res.push_back(val);
    }
    return res;
}

vector<string> balancedParantheses(int n)
{
    // Write Your Code here.
    return balancedall(2*n, "",0,0);
}


int main(){
	int n;
	cin>>n;
	vector<string>ans = balancedParantheses(n);
	for(auto val : ans){
		cout<<val<<endl;
	}
	return 0;
}

