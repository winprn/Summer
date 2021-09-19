/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
vector<int> adj[N],res[2];
long long a[N],b[N];
bool vis[N];
long long ans=0;
int n;

void dfs(int u){
  vis[u]=1;
  for(int v:adj[u]){
    if(!vis[v])dfs(v);
  }

  ans+=a[u];
  if(b[u]!=-1&&a[u]>=0){
    a[b[u]]+=a[u];
  }
  if(a[u]>=0)res[0].push_back(u);
  else res[1].push_back(u);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>n;
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=1;i<=n;++i){
    cin>>b[i];
    if(b[i]!=-1)adj[b[i]].push_back(i);
  }

  for(int i=1;i<=n;++i){
    if(!vis[i])dfs(i);
  }

  cout<<ans<<endl;
  reverse(res[1].begin(),res[1].end());
  for(int i:res[0])cout<<i<<' ';
  for(int i:res[1])cout<<i<<' ';
}
