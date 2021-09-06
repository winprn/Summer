#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=255;
ll a[N][N],d[N];
int par[N];
bool vis[N];
ll n,m,mn,mx=-1;

ll dijkstra(int s){
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	memset(par,-1,sizeof(par));
	d[s]=0;
	
	while(1){
		int v=-1;
		for(int i=1;i<=n;++i){
			if(!vis[i]&&(v==-1||d[v]>d[i]))v=i;
		}
		if(v==-1)break;
		
		vis[v]=1;
		for(int i=1;i<=n;++i){
			ll dist=d[v]+a[v][i];
			if(dist<d[i]){
				d[i]=dist;
				par[i]=v;
			}
		}
	}
	
	return d[n];
}

signed main(){
	freopen("cost.inp","r",stdin);
	freopen("cost.out","w",stdout);
	
	cin>>n>>m;
	memset(a,0x3f,sizeof(a));
	for(int i=0;i<m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
	}
	mx=mn=dijkstra(1);
	
	vector<int> path;
	int tmp=n;
	while(tmp!=-1){
		path.pb(tmp);
		tmp=par[tmp];
	}
	
	for(int i=0;i<(int)path.size()-1;++i){
		int u=path[i],v=path[i+1];
		a[u][v]=a[v][u]=a[u][v]*2;
		mx=max(mx,dijkstra(1));
		a[u][v]=a[v][u]=a[u][v]/2;
	}
	cout<<mx-mn<<endl;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}