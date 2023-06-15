#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int add_any_base(long long num1, long long int num2, int b){
	int mul = 1;
	long long add_ans = 0;
	int carry = 0;
	while(num1 || num2){
		int rem1 = num1%10;
		int rem2 = num2%10;
		int pa = rem1+rem2+carry;
		carry = pa/b;
		add_ans += (pa%b)*mul;
		mul *= 10;
		num1 /= 10;
		num2 /= 10;
	}
	if(carry){
		add_ans += (carry*mul);
	}
	return add_ans;
}

void solve(int b, long long int num1, long long int num2){
	long long int ans = 0;
	int mul = 1;
	while(num1){
		long long int pa = 0;
		int rem1 = num1%10;
		int carry = 0;
		int intermul = 1;
		long long num2_temp = num2;
		while(num2_temp){
			int rem2 = num2_temp%10;
			int diga = rem2 *rem1 + carry;
			carry = diga / b;
			pa += (diga%b)*intermul;
			intermul *= 10;
			num2_temp /= 10;
		}
		if(carry){
			pa += (carry*intermul);
		}
		pa *= mul;
		ans = add_any_base(ans,pa, b);
		mul *= 10;
		num1 /= 10;
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

