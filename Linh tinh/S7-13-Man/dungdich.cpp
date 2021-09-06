#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=22;
int a[N][N],dp[(1<<N)];
int n,k;

int _dp(int mask){
	int &ans=dp[mask];
	if(ans!=-1)return ans;
	int cnt=0;
	for(int i=0;i<n;++i)if((mask>>i)&1)++cnt;
	if(cnt==k)return 0;
	ans=1e9;
	
	for(int i=0;i<n;++i){
		if(!(mask&(1<<i)))continue;
		for(int j=0;j<n;++j){
			if(!(mask&(1<<j))||i==j)continue;
			ans=min(ans,a[i][j]+_dp(mask^(1<<i)));
		}
	}
	return ans;
}

signed main(){
	freopen("dungdich.inp","r",stdin);
	freopen("dungdich.out","w",stdout);
	
	cin>>n>>k;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>a[i][j];
		}
	}
	
	memset(dp,-1,sizeof dp);
	cout<<_dp((1<<n)-1);
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}