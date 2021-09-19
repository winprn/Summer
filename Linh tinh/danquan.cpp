/// ldmm is n00b ///
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> adj[N][3];
int d[3][N];
bool mark[2][N];
int n,m,k;

void bfs(queue<int> cur, int t){
    int tt=t>0;
    while(!cur.empty()){
        int u=cur.front();
        cur.pop();

        for(int v:adj[u][tt]){
            if(d[t][v]>d[t][u]+1){
                d[t][v]=d[t][u]+1;
                cur.push(v);
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    freopen("danquan.inp","r",stdin);
    freopen("danquan.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)d[0][i]=d[1][i]=d[2][i]=1e7;
    queue<int> g,r,q;
    for(int i=0;i<m;++i){
        int u; cin>>u;
        mark[0][u]=1;
        d[1][u]=0;
        g.push(u);
    }
    for(int i=0;i<k;++i){
        int u; cin>>u;
        mark[1][u]=1;
        d[2][u]=0;
        r.push(u);
    }
    for(int i=1;i<=n;++i){
        int tmp; cin>>tmp;
        for(int j=0;j<tmp;++j){
            int u; cin>>u;
            adj[i][0].push_back(u);
            adj[u][1].push_back(i);
        }
    }
    q.push(1);
    d[0][1]=0;
    bfs(g,1),bfs(r,2),bfs(q,0);
    int ans=1e7;
    for(int i=1;i<=n;++i){
        if(!mark[0][i]&&!mark[1][i])continue;
        ans=min(ans,d[0][i]+d[1][i]+d[2][i]);
    }
    cout<<(ans==1e7?-1:ans)<<endl;
}
