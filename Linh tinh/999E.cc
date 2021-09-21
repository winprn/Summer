/// ldmm is n00b ///
#include <bits/stdc++.h>
using namespace std;

const int N=5e3+10;
vector<int> adj[N],adj2[N];
stack<int> st;
vector<pair<int,int>> a;
int low[N],num[N],tp[N];
bool onStack[N],vis[N],mark[N],VIS[N];
int n,m,cnt=1,tot=0,s,tmp;

void dfs(int u){
    vis[u]=1;
    for(int v:adj[u]){
        if(!vis[v])dfs(v);
    }
}

void dfs2(int u){
    VIS[u]=1;
    for(int v:adj[u]){
        if(!VIS[v]&&!vis[u]){
            ++tmp;
            dfs2(v);
        }
    }
}

signed main(){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    freopen("i","r",stdin);
    freopen("o","w",stdout);

    cin>>n>>m>>s;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
    dfs(s);

    for(int i=1;i<=n;++i){
        if(!vis[i]){
            tmp=1;
            memset(VIS,0,sizeof(VIS));
            dfs2(i);
            a.push_back({tmp,i});
        }
    }
    sort(a.rbegin(),a.rend());

    int ans=0;
    for(int i=0;i<a.size();++i){
        if(!vis[a[i].second]){
            //cout<<a[i].second<<endl;
            dfs(a[i].second);
            ++ans;
        }
    }
    cout<<ans;
}
