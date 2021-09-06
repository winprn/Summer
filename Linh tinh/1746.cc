#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e5+10;
ll a[N],dp[N][105];
int n,m;

signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(a[1]==0)for(int i=1;i<=m;++i)dp[1][i]=1;
	else dp[1][a[1]]=1;	
	
	//memset(dp,-1,sizeof dp);
	for(int i=2;i<=n;++i){
		if(a[i]==0){
			for(int j=1;j<=m;++j){
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
				dp[i][j]%=MOD;
			}
		}else{
			int j=a[i];
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
			dp[i][j]%=MOD;
		}
	}
	
	ll ans=0;
	for(int i=1;i<=m;++i)ans+=dp[n][i],ans%=MOD;
	cout<<ans;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}