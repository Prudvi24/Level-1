#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

double median(vector<int>&a, vector<int>&b){
	int n = a.size();
	int m = b.size();
	int len = n+m;
	int eid1 = len/2-1;
	int eid2 = len/2;
	int ele1 = 0, ele2=0;
	int i=0, j=0, count=0;
	bool flag = 0;
	while(i<n && j<m){
		if(a[i]<b[j]){
			if(count==eid2){
				ele2 = a[i];
				flag = 1;
				break;
			}
			if(count==eid1){
				ele1 = a[i];
			}
			count++;
			i++;
		}
		else{
			if(count==eid2){
				ele2 = b[j];
				flag=1;
				break;
			}
			if(count==eid1){
				ele1 = b[j];
			}
			count++;
			j++;			
		}
	}
	while(i<n && flag==0){
		if(count==eid2){
			ele2 = a[i];
			flag = 1;
			break;
		}
		if(count==eid1){
			ele1 = a[i];
		}
		count++;
		i++;		
	}
	while(j<m && flag==0){
		if(count==eid2){
			ele2 = b[j];
			flag = 1;
			break;
		}
		if(count==eid1){
			ele1 = b[j];
		}
		count++;
		j++;			
	}
	if(len%2==0){
		return ((double)(ele1+ele2)/(double)2);
	}
	return ((double)ele2/(double)1);
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n,0);
	vector<int>b(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	double ans = median(a,b);
	cout<<ans<<endl;
	return 0;
}

