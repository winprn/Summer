#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e5+10;
ll w[105],v[105],dp[105][N];
int n,W;

ll _dp(int i,int cw){
	if(cw<0)return -1e9;
	if(i==0)return 0;
	ll &ans=dp[i][cw];
	if(ans!=-1)return ans;
	
	if(cw>=w[i])ans=v[i]+_dp(i-1,cw-w[i]);
	return ans=max(ans,_dp(i-1,cw));
}

signed main(){
	cin>>n>>W;
	for(int i=1;i<=n;++i)cin>>w[i]>>v[i];
	
	memset(dp,-1,sizeof dp);
	cout<<_dp(n,W);	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}