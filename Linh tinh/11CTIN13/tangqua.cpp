#include <bits/stdc++.h>

using namespace std;

#define ms(a,x) memset(a,(x),sizeof a)
#define MOD 1000000007

typedef long long ll;

int c[3005][3005],f[3005][3005],trace[3005];
int n,m,t,flow;

bool bfs(){
    ms(trace,-1);
    queue<int>q;
    q.push(0);
    trace[0]=n+1;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int v=1;v<=n;++v){
            if(trace[v]==-1&&c[u][v]>f[u][v]){
                trace[v]=u;
                if(v==n)return 1;
                q.push(v);
            }
        }
    }
    
    return 0;
}

void inc(){
    int delta=1e9,u,v=n;
    do{
        u=trace[v];
        delta=min(delta,c[u][v]-f[u][v]);
        v=u;
    }while(v!=0);
    v=n,flow+=delta;

    do{
        u=trace[v];
        f[u][v]+=delta;
        f[v][u]-=delta;
        v=u;
    }while(v!=0);
}

int main() {
    freopen("tangqua.inp", "r", stdin);
    freopen("tangqua.out", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n>>m;
        ms(c,0),ms(f,0);
        flow=0;
        for(int i=0;i<m;++i){
            int u,v;cin>>u>>v;
            c[u][v+n]=c[v][u+n]=1;
            // adj[u].pb(v);
            // adj[v].pb(u);
        }
        for(int i=1;i<=n;++i)c[0][i]=1e9;
        for(int i=n+1;i<=2*n;++i)c[i][n+n+1]=1e9;
        n=2*n+1;

        while(bfs())inc();
        if(flow>=n-1)cout<<'Y'<<endl;
        else cout<<'N'<<endl;
    }
}