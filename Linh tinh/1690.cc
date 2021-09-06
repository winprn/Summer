#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

vector<int> adj[21];
int dp[(1<<20)][21];
int n,m;

signed main(){
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v; cin>>u>>v;
		--u,--v;
		adj[v].pb(u);
	}
	
	dp[1][0]=1;
	for(int mask=2;mask<1<<n;++mask){
		if ((mask & (1 << 0)) == 0)continue;
		if ((mask & (1 << (n - 1))) && mask != ((1 << n) - 1))continue;
		
		for(int nxt=0;nxt<n;++nxt){
			if ((mask & (1 << nxt)) == 0)continue;
			
			int prv=mask-(1<<nxt);
			for(int v:adj[nxt]){
				if((mask&(1<<v))){
					dp[mask][nxt]+=dp[prv][v];
					dp[mask][nxt]%=MOD;
				}
			}
		}
	}
	cout<<dp[(1<<n)-1][n-1];
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}