#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

double median(vector<int>&a, vector<int>&b){
	int n1 = a.size();
	int n2 = b.size();
	if(n2<n1){
		return median(b,a);
	}
	int lo = 0;
	int hi = n1;
	int sym = (n1+n2+1)/2;
	while(lo<=hi){
		int mid1 = (lo+hi)/2;
		int mid2 = sym-mid1;
		int l1 = mid1-1<0 ? INT_MIN : a[mid1-1];
		int l2 = mid2-1<0 ? INT_MIN : b[mid2-1];
		int r1 = mid1>=n1 ? INT_MAX : a[mid1];
		int r2 = mid2>=n2 ? INT_MAX : b[mid2];

		if(l1<=r2 && l2<=r1){
			if((n1+n2)%2==0){
				return (double)(max(l1,l2)+min(r1,r2))/2.0; 
			}
			else{
				return double(max(l1,l2));
			}
		}
		else if(l1>r2){
			hi = mid1-1;
		}
		else{
			lo = mid1+1;
		}
	}
	return 0;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n,0);
	vector<int>b(m,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	double ans = median(a,b);
	cout<<ans<<endl;
	return 0;
}

