#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(int b, long long int num1, long long int num2){
	int ans = 0;
	int mul = 1;
	int br = 0;
	while(num1 || num2){
		int rem1 = num1%10;
		int rem2 = num2%10;
		num1 /= 10;
		num2 /= 10;
		rem1 = rem1-br;
		if(rem1>=rem2){
			br = 0;
			ans += ((rem1-rem2)*mul);
		}
		else{
			br = 1;
			ans += ((rem1+b-rem2)*mul);
		}
		mul *= 10;
	}
	cout<<ans<<endl;
}

int main(){
	int b;
	long long num1, num2;
	cin>>b>>num1>>num2;
	solve(b,num2,num1);
	return 0;
}

