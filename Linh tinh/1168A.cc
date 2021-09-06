#include "bits/stdc++.h"

using namespace std;

const int N=3e5+10;
int a[N];
int n,m;

bool ok(int x){
	int cur=0;
	for(int i=0;i<n;++i){
		int tmp=a[i],tmp2=a[i]+x;
		if((tmp<=cur&&cur<=tmp2)||(tmp<=cur+m&&cur+m<=tmp2))continue;
		if(tmp<cur)return 1;
		cur=tmp;
	}
	
	return 0;
}

signed main(){
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>a[i];
	
	int l=0,r=m,ans=-1;
	for(int i=0;i<=32;++i){
		int mid=(l+r)/2;
		if(ok(mid))l=mid;
		else ans=r=mid;
	}
	cout<<ans;
}