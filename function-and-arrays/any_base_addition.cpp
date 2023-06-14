#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(int b, long long int num1, long long int num2){
	int ans = 0;
	int carry = 0;
	int mul = 1;
	while(num1 || num2){
		int pa = carry+(num1%10)+(num2%10);
		carry = pa/b;
		int ds = pa%b;
		ans += (ds*mul);
		mul *= 10;
		num1 /= 10;
		num2 /= 10;
	}
	if(carry){
		ans += (carry*mul);
	}
	cout<<ans<<endl;
}

int main(){
	int b;
	long long int num1, num2;
	cin>>b>>num1>>num2;
	solve(b,num1,num2);
	return 0;
}

