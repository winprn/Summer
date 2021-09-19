/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
vector<int> adj[N];
int a[N],b[N],c[N];
long long n,ans;

pair<int,int> dfs(int u,int p,int cur){
  pair<int,int> kq={0,0};
  if(b[u]!=c[u]){
    if(b[u])kq.first++;
    else kq.second++;
  }
  for(int v:adj[u]){
    if(v!=p){
      auto tmp=dfs(v,u,min(a[u],cur));
      kq.first+=tmp.first;
      kq.second+=tmp.second;
    }
  }

  if(a[u]<cur){
    int tmp=min(kq.first,kq.second);
    ans+=2LL*tmp*a[u];
    kq.first-=tmp,kq.second-=tmp;
  }

  return kq;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>n;
  for(int i=1;i<=n;++i){
    cin>>a[i]>>b[i]>>c[i];
  }

  for(int i=0;i<n-1;++i){
    int u,v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  auto res=dfs(1,-1,1e9+7);

  if(res.first||res.second)cout<<-1;
  else cout<<ans;
}
