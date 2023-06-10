#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

//euclidean algorithm
int solve_gcd(int x, int y){
	if(y==0){
		return x;
	}
	int ans=solve_gcd(y,x%y);
	return ans;
}

void solve_recursive(int x, int y){
	int gcd = solve_gcd(x,y);
	int lcm = (x*y)/gcd;
	cout<<"GCD: "<<gcd<<endl;
	cout<<"LCM: "<<lcm<<endl;
}

void solve_iterative(int x, int y){
	int tx = x, ty = y;
	while(x > 0 && y > 0){
		if(x > y){
			x = x%y;
		}
		else{
			y = y%x;
		}
	}
	int gcd;
	if(x==0){
		gcd = y;
	}
	if(y==0){
		gcd = x;
	}
	int lcm = (tx*ty)/gcd;
	cout<<"GCD : "<<gcd<<endl;
	cout<<"LCM : "<<lcm<<endl;
}

int main(){
	int x,y;
	cin>>x>>y;
	solve_recursive(x,y);
	solve_iterative(x,y);
	return 0;
}