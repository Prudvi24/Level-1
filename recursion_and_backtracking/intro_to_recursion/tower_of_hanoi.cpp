#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void tower_of_hanoi(int n, int t1, int t2, int t3){
	if(n==0){
		return ;
	}
	tower_of_hanoi(n-1,t1,t3,t2);
	cout<<n<<"["<<t1<<" --> "<<t2<<"]"<<endl;
	tower_of_hanoi(n-1,t3,t2,t1);
}

int main(){
	int n,t1,t2,t3;
	cin>>n>>t1>>t2>>t3;
	tower_of_hanoi(n,t1,t2,t3);
	return 0;
}

