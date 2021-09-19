/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
const int LOG=20;
vector<int> adj[N],event[N];
bool mark[N];
int h[N],par[N][LOG];
int n,k;

void dfs(int u,int p=-1){
  for(int v:adj[u]){
    if(v!=p){
      h[v]=h[u]+1;
      par[v][0]=u;
      for(int j=1;j<LOG;++j)par[v][j]=par[par[v][j-1]][j-1];
      dfs(v,u);
    }
  }
}

int lca(int u,int v){
  if(h[u]<h[v])swap(u,v);
  int k=h[u]-h[v];
  for(int i=0;i<LOG;++i){
    if(k&(1<<i))u=par[u][i];
  }
  if(u==v)return u;

  for(int i=LOG-1;i>=0;--i){
    if(par[u][i]!=par[v][i]){
      u=par[u][i],v=par[v][i];
    }
  }
  return par[u][0];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>n>>k;
  for(int i=1;i<=n;++i){
    int t,v; cin>>t>>v;
    adj[i].push_back(v);
    adj[v].push_back(i);
    event[t].push_back(i);
    if(v==0)mark[i]=1;
  }
  dfs(0);

  for(int i=1;i<=k;++i){
    int root=event[i][0],p,ans=-1;
    for(int j:event[i])if(h[j]>h[root])root=j;
    //cout<<root<<endl;
    for(int j:event[i]){
      p=lca(root,j);
      ans=max(ans,h[j]+h[root]-2*h[p]);
    }
    cout<<ans<<endl;
  }
}
