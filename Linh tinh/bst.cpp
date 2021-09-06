#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

int a[300],pr[300],dp[300][300];
int n;

int _dp(int l,int r){
	if(r<=l)return 0;

	int &ans=dp[l][r];
	if(ans!=-1)return ans;
	ans=1e9;
	for(int k=l;k<=r;++k){
		ans=min(ans,_dp(l,k-1)+_dp(k+1,r)+max(0,pr[k-1]-pr[l-1])+max(0,pr[r]-pr[k]));
	}
	
	return ans;
}

signed main(){
	while(cin>>n){
		memset(pr,0,sizeof pr);
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)pr[i]=pr[i-1]+a[i];
		
		memset(dp,-1,sizeof dp);
		cout<<_dp(1,n)<<endl;
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}