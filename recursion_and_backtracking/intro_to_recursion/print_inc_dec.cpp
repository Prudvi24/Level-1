#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void print_inc_dec(int n){
	if(n==0){
		return ;
	}
	cout<<n<<endl;
	print_inc_dec(n-1);
	cout<<n<<endl;
}

int main(){
	int n;
	cin>>n;
	print_inc_dec(n);
	return 0;
}

