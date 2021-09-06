#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=2e5+10;
vector<int> adj[N],a;
int d[N],cnt[N];
int n,m,k,mn,mx;

void bfs(int s){
	queue<int> q;
	q.push(s);
	memset(d,0x3f,sizeof d);
	d[s]=0;
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
		
		for(int v:adj[u]){
			if(d[v]>d[u]+1){
				d[v]=d[u]+1;
				cnt[v]=1;
				q.push(v);
			}else if(d[v]==d[u]+1) ++cnt[v];
		}
	}
}

signed main(){
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v; cin>>u>>v;
		adj[v].pb(u);
	}
	cin>>k;
	while(k--){
		int x; cin>>x;
		a.pb(x);
	}
	
	bfs(a.back());
	// for(auto i:a)cout<<d[i]<<' ';
	// cout<<endl;
	a.pop_back();
	for(int i=0;i<(int)a.size()-1;++i){
		if(1+d[a[i+1]]==d[a[i]]){
			if(cnt[a[i]]>1)++mx;
		}else ++mx,++mn;
	}
	cout<<mn<<' '<<mx;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}