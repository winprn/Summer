/// ldmm is n00b ///
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> adj[2][N],topo;
int pos[N];
bool vis[N];
int n,t,ans=0;

void dfs(int u){
    vis[u]=1;
    for(int v:adj[0][u]){
        if(!vis[v]){
            dfs(v);
        }
        if(v<u){
            bool ok=(adj[1][u].size()==0);
            for(int j:adj[1][u])if(!vis[j])ok=1;
            ans+=ok;
        }
    }
    topo.push_back(u);
}

signed main(){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    freopen("i","r",stdin);
    freopen("o","w",stdout);

    cin>>t;
    while(t--){
        cin>>n;
        topo.clear();
        for(int i=1;i<=n;++i)adj[0][i].clear(),adj[1][i].clear(),vis[i]=0;
        for(int i=1;i<=n;++i){
            int m; cin>>m;
            for(int j=0;j<m;++j){
                int u; cin>>u;
                adj[0][u].push_back(i);
                adj[1][i].push_back(u);
            }
        }

        ans=1;
        for(int i=1;i<=n;++i){
            if(!vis[i])dfs(i);
        }
        reverse(topo.begin(),topo.end());
        for(int i=1;i<=n;++i)pos[topo[i-1]]=i;
        for(int i=1;i<=n;++i)cout<<pos[i]<<' ';
        cout<<endl;

        bool ok=1;
        for(int i=1;i<=n;++i){
            for(int j:adj[0][i]){
                if(pos[i]>pos[j])ok=0;
            }
        }
        cout<<(ok?ans:-1)<<endl;
    }
}
