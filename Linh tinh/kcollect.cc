#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=105;
vector<int> adj[N*N+N],adj2[N*N+N];
stack<int> q;
int dp[N*N+N],low[N*N+N],num[N*N+N],tp[N*N+N],x[N*N+N],id[N][N],val[N*N+N];
char a[N][N];
bool vis[N*N+N],onStack[N*N+N];
int n,m,cnt=0,tot=1,mx=0;

void dfs(int u){
	low[u]=num[u]=++cnt;
	q.push(u);
	onStack[u]=1;
	
	for(int v:adj[u]){
		if(!num[v])dfs(v);
		if(onStack[v])low[u]=min(low[u],low[v]);
	}
	
	if(low[u]==num[u]){
		while(!q.empty()){
			int v=q.top();
			q.pop();
			onStack[v]=0;
			tp[v]=tot;
			val[tot]+=x[v];
			low[v]=num[u];
			if(v==u)break;
		}
		++tot;
	}
}

void dfs2(int u){
	vis[u]=1;
	for(int v:adj2[u]){
		if(!vis[v])dfs2(v);
		dp[u]=max(dp[u],val[u]+dp[v]);
	}
}

signed main(){
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j)cin>>a[i][j],id[i][j]=mx,++mx;
	}	
	
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(a[i][j]=='#')continue;
			if(a[i][j]>='0'&&a[i][j]<='9')x[id[i][j]]=a[i][j]-'0';
			if(j+1<m)adj[id[i][j]].pb(id[i][j+1]);
			if(i+1<n)adj[id[i][j]].pb(id[i+1][j]);
			
			if(a[i][j]=='W'&&j>0)adj[id[i][j]].pb(id[i][j-1]);
			if(a[i][j]=='N'&&i>0)adj[id[i][j]].pb(id[i-1][j]);
		}
	}
	// for(int i=0;i<mx;++i){
		// for(int j:adj[i])cout<<j<<' ';
		// cout<<endl;
	// }
	
	for(int i=0;i<mx;++i){
		if(!num[i])dfs(i);
	}
	
	for(int i=0;i<mx;++i){
		for(int j:adj[i]){
			if(tp[i]!=tp[j])adj2[tp[i]].pb(tp[j]);
		}
	}
	
	// for(int i=0;i<n;++i){
		// for(int j=0;j<m;++j)cout<<id[i][j]<<' ';
		// cout<<endl;
	// }
	//for(int i=0;i<mx;++i)cout<<tp[i]<<endl;
	
	//for(int i=1;i<=tot;++i)cout<<val[i]<<endl;
	
	for(int i=1;i<tot;++i)dp[i]=val[i];
	for(int i=1;i<tot;++i){
		if(!vis[i])dfs2(i);
	}
	cout<<dp[tp[id[0][0]]];
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}