#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e5+10;
vector<pair<ll,pair<int,int>>> edges;
int par[N];
int n,m;

int findP(int u){
	return(par[u]==-1?u:par[u]=findP(par[u]));
}

bool join(int u,int v){
	if((u=findP(u))==(v=findP(v)))return 0;
	
	return par[u]=v,1;
}

signed main(){
	//freopen("power.inp","r",stdin);
	//freopen("power.out","w",stdout);
	
	cin>>n>>m;
	memset(par,-1,sizeof par);
	for(int i=0;i<m;++i){
		int u;
		ll w;
		cin>>u>>w;
		edges.pb({w,{u,n+1}});
	}
	for(int i=1;i<=n;++i){
		ll w; cin>>w;
		edges.pb({w,{i,(i+1>n?1:i+1)}});
	}
	sort(edges.begin(),edges.end());
	
	ll ans=0;
	for(auto i:edges){
		int u=i.se.fi,v=i.se.se;
		ll w=i.fi;
		if(findP(u)!=findP(v)){
			// cout<<u<<' '<<v<<' '<<w<<endl;
			// cout<<findP(u)<<' '<<findP(v)<<endl;
			// cout<<endl;
			join(u,v);
			ans+=w;
		}
	}
	cout<<ans;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}