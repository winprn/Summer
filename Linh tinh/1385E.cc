/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
vector<pair<int,int>> edges;
vector<int> adj[N],topo;
int pos[N];
bool vis[N];
int n,m,t;

void dfs(int u){
  vis[u]=1;
  for(int v:adj[u]){
    if(!vis[v])dfs(v);
  }
  topo.push_back(u);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>t;
  while(t--){
    cin>>n>>m;
    topo.clear();
    edges.clear();
    for(int i=1;i<=n;++i)adj[i].clear(),vis[i]=pos[i]=0;
    for(int i=0;i<m;++i){
      int t,u,v; cin>>t>>u>>v;
      if(t==1)adj[u].push_back(v);
      else edges.push_back({u,v});
    }

    for(int i=1;i<=n;++i){
      if(!vis[i])dfs(i);
    }
    reverse(topo.begin(),topo.end());
    for(int i=1;i<=n;++i)pos[topo[i-1]]=i;

    bool ok=1;
    for(int i=1;i<=n;++i){
      for(int j:adj[i]){
        if(pos[j]<pos[i])ok=0;
      }
    }

    if(!ok)cout<<"NO"<<endl;
    else{
      cout<<"YES"<<endl;
      for(int i=1;i<=n;++i){
        for(int j:adj[i])cout<<i<<' '<<j<<endl;
      }
      for(auto i:edges){
        int u=i.first,v=i.second;
        if(pos[u]<pos[v])cout<<u<<' '<<v<<endl;
        else cout<<v<<' '<<u<<endl;
      }
    }
  }
}
