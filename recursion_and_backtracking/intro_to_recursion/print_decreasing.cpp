#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void print_decreasing(int n){
	if(n==1){
		cout<<1<<endl;
		return ;
	}
	cout<<n<<endl;
	print_decreasing(n-1);
}

int main(){
	int n;
	cin>>n;
	print_decreasing(n);
	return 0;
}

