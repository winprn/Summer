#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

const int N=4e4+10;
vector<int> adj[N];
int d[5][N];
int n,m,x,y,z;

void bfs(int s){
    queue<int>q;
    if(s==3)q.push(n);
    else q.push(s);
    d[s][(s==3?n:s)]=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(d[s][v]>d[s][u]+1){
                d[s][v]=d[s][u]+1;
                q.push(v);
            }
        }
    }
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("group.inp", "r", stdin);
    freopen("group.out", "w", stdout);

    cin>>x>>y>>z>>n>>m;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    memset(d,0x3f,sizeof d);
    bfs(1),bfs(2),bfs(3);
    int ans=1e9;
    for(int i=1;i<=n;++i){
        ans=min(ans,d[1][i]*x+d[2][i]*y+d[3][i]*z);
    }
    cout<<ans<<endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}