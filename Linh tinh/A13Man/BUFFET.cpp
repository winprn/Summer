/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<int> adj[N];
int a[N],b[N],dp[N],d[N];
int n,m;

bool cmp(int i,int j){
  return a[i]<a[j];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("buffet.inp", "r", stdin);
    freopen("buffet.out", "w", stdout);

  cin>>n>>m;
  for(int i=0;i<n;++i){
    int tmp;
    cin>>a[i]>>tmp;
    for(int j=0;j<tmp;++j){
      int v; cin>>v,--v;
      adj[i].push_back(v);
    }
  }

  iota(b,b+n,0);
  sort(b,b+n,cmp);

  int ans=0;
  for(int i=n-1;i>=0;--i){
    for(int j=0;j<n;++j)d[j]=1e9;
    queue<int> q;
    int s=b[i];
    q.push(s),d[s]=0;

    while(!q.empty()){
      int u=q.front();
      q.pop();
      for(int v:adj[u]){
        if(d[v]>d[u]+1){
          d[v]=d[u]+1;
          q.push(v);
        }
      }
    }

    int tmp=a[s];
    for(int j=0;j<n;++j){
      if(d[j]!=1e9){
        tmp=max(tmp,dp[j]+a[s]-m*d[j]);
      }
    }
    dp[s]=tmp;
    ans=max(ans,dp[s]);
  }
  cout<<ans<<endl;
}
