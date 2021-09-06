#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=5e2+10;
vector<int> adj[N],match;
vector<bool> vis;
pair<int,int> s[N],t[N];
int start[N];
int n,ts;

bool ok(int i,int j){
	int cur=start[i];
	cur+=abs(t[i].fi-s[i].fi)+abs(t[i].se-s[i].se);
	cur+=abs(s[j].fi-t[i].fi)+abs(s[j].se-t[i].se);
	
	return cur<start[j];
}

bool dfs(int u){
	if(vis[u])return 0;
	vis[u]=1;
	
	for(int v:adj[u]){
		if(match[v]==-1||dfs(match[v])){
			match[v]=u;
			return 1;
		}
	}
	
	return 0;
}

signed main(){
	freopen("taxi.inp","r",stdin);
	freopen("taxi.out","w",stdout);
	
	cin>>ts;
	while(ts--){
		cin>>n;
		for(int i=0;i<n;++i){
			adj[i].clear();
			char tmp;
			int h,m; cin>>h>>tmp>>m;
			cin>>s[i].fi>>s[i].se>>t[i].fi>>t[i].se;
			start[i]=h*60+m;
		}
		// for(int i=0;i<n;++i){
			// cout<<h[i]<<m[i]<<s[i].fi<<s[i].se<<t[i].fi<<t[i].se<<endl;
		// }
		
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(i==j)continue;
				if(ok(i,j))adj[i].pb(j+n);
			}
		}
		
		// for(int i=0;i<n;++i){
			// for(int j:adj[i])cout<<j<<' ';
			// cout<<endl;
		// }
		
		match.assign(2*n+10,-1);
		int ans=0;
		for(int i=0;i<n;++i){
			vis.assign(n,0);
			ans+=dfs(i);
		}
		cout<<n-ans<<endl;
	}	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}