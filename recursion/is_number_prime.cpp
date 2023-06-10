#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
	int tc,d;
	cin>>tc;
	while(tc--){
		cin>>d;
		bool flag = 0;
		for(int div=2;div*div<=d;div++){
			if(d%div==0){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"not prime"<<endl;
		}
		else{
			cout<<"prime"<<endl;
		}
	}
	return 0;
}