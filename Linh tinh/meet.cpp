#include <bits/stdc++.h>
#define maxN 1010
#define inf INT_MAX
 
using namespace std;
 
typedef vector<int> vi;
 
vi adj[maxN];
int n,m,u,v,change,k;
int a[maxN],b[maxN],mx[maxN],d[maxN];
bool visit[maxN];
 
void dfs(int u,int idx)
{
    visit[u]=true;
    b[u]=idx;
    for (int i=0;i<adj[u].size();++i)
    {
        int v=adj[u][i];
        if (!visit[v]) dfs(v,idx);
    }
}
 
void dfs2(int u,int idx)
{
    visit[u]=true;
    if (a[u]!=idx) change++;
    for (int i=0;i<adj[u].size();++i)
    {
        v=adj[u][i];
        if (!visit[v]) dfs2(v,idx);
    }
}
 
int main()
{
    freopen("MEET.INP","r",stdin);
    freopen("MEET.OUT","w",stdout);
 
    cin>>n>>m;
 
    for (int i=1;i<=n;++i) cin>>a[i];
 
    for (int i=0;i<m;++i)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    k=0;
 
    for (int i=1;i<=n;++i)
    {
        if (!visit[i])
        {
            k++;
            dfs(i,k);
        }
    }
 
    for (int i=1;i<=k;++i) mx[i]=inf;
 
    for (int i=1;i<=n;++i)
    {
        memset(visit,0,sizeof visit);
        change=0;
        dfs2(i,a[i]);
        mx[b[i]]=min(mx[b[i]],change);
    }
 
    int res=0;
    for (int i=1;i<=k;++i) res+=mx[i];
 
    cout<<res;
}