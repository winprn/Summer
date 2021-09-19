/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=2e4+10;
vector<int> adj[N],tp[N];
stack<int> q;
int out[N],in[N],TP[N],low[N],num[N];
bool onStack[N];
int n,m,t,dem,scc;

void dfs(int u,int p=-1){
  low[u]=num[u]=dem++;
  onStack[u]=1;
  q.push(u);

  for(int v:adj[u]){
    if(num[v]==-1)dfs(v,u);
    if(onStack[v])low[u]=min(low[u],low[v]);
  }

  if(low[u]==num[u]){
    while(!q.empty()){
        int v=q.top();
        q.pop();
        low[v]=low[u];
        onStack[v]=0;
        TP[v]=scc;
        tp[scc].push_back(v);
        if(v==u)break;
    }
    ++scc;
  }
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
    memset(num,-1,sizeof(num));
    memset(onStack,0,sizeof(onStack));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for(int i=0;i<=n;++i)adj[i].clear(),tp[i].clear();
    for(int i=0;i<m;++i){
      int u,v; cin>>u>>v;
      adj[u].push_back(v);
    }

    while(!q.empty())q.pop();
    scc=0,dem=0;
    for(int i=1;i<=n;++i){
      if(num[i]==-1)dfs(i);
    }
    if(scc==1){cout<<0<<endl;continue;}

    for(int i=0;i<scc;++i){
      for(int j:tp[i]){
        for(int k:adj[j]){
          if(TP[j]!=TP[k])in[TP[k]]++,out[TP[j]]++;
        }
      }
    }

    int cnt=0,cnt2=0;
    for(int i=0;i<scc;++i)cnt+=(in[i]==0),cnt2+=(out[i]==0);
    cout<<max(cnt,cnt2)<<endl;
  }
}
