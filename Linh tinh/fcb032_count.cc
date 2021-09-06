#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

const int N=2e5+10;
set<int> cnt[N];
vector<int> adj[N];
bool vis[N];
int ans[N],num[N];
int n;

void dfs(int u){
    vis[u]=1;
    for(int v:adj[u]){
        if(!vis[v]){
            dfs(v);
            int a=num[u],b=num[v];
            if(cnt[a].size()>=cnt[b].size())cnt[a].insert(cnt[b].begin(),cnt[b].end());
            else{
                num[u]=num[v];
                cnt[b].insert(cnt[a].begin(),cnt[a].end());
            }
        }
    }
    ans[u]=(int)cnt[num[u]].size();
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n-1;++i){
        int u,v; cin>>u>>v;
        //write(u,' ',v,'\n');
        adj[u].pb(v);adj[v].pb(u);
    }
    for(int i=1;i<=n;++i){
        int x; cin>>x;
        cnt[i].insert(x);
        num[i]=i;
    }
    dfs(1);
    
    for(int i=1;i<=n;++i)cout<<ans[i]<<' ';

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}