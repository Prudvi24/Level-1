#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/*

    1     
  2 3 2   
3 4 5 4 3 
  2 3 2   
    1   

*/

void solve(int n){
	int sp = n/2;
	int num = 1;
	int count = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sp;j++){
			cout<<"  ";
		}
		int a = count;
		for(int j=1;j<=num;j++){
			cout<<a<<" ";
			if(j<=num/2){
				a++;
			}
			else{
				a--;
			}
		}
		for(int j=1;j<=sp;j++){
			cout<<"  ";
		}
		if(i>=n/2+1){
			sp++;
			num -= 2;
			count--;
		}
		else{
			sp--;
			num += 2;
			count++;
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	solve(n);
	return 0;
}

