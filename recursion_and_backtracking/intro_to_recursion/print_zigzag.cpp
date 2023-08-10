#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void print_zigzag(int n){
	if(n==0){
		return ;
	}
	cout<<n<<" ";
	print_zigzag(n-1);
	cout<<n<<" ";
	print_zigzag(n-1);
	cout<<n<<" ";
}

int main(){
	int n;
	cin>>n;
	print_zigzag(n);
	cout<<endl;
	return 0;
}