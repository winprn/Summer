/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
vector<pair<int,int>> adj[N];
vector<int> a;
long long dp[(1<<10)][10];
int d[N],cnt[N],dist[N][N],mu[N],dd[N][N];
long long tot;
int n,m,q,t;

void dijkstra(int s){
    for(int i=0;i<n;++i)d[i]=INT_MAX/2;
    d[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        for(auto v:adj[u]){
            if(d[v.first]>d[u]+v.second){
                d[v.first]=d[u]+v.second;
                pq.push({d[v.first],v.first});
            }
        }
    }
}

bool TSP(int num){
    for(int i=0;i<mu[num];++i)for(int j=0;j<num;++j)dp[i][j]=INT_MAX/2;

    dp[1][0]=0;
    for(int i=1;i<mu[num];++i){
        for(int j=0;j<num;++j){
            if(dp[i][j]==INT_MAX)continue;
            for(int k=0;k<num;++k){
                if((i>>k)&1||dist[j][k]==INT_MAX/2)continue;
                if(dp[i+mu[k]][k]>dp[i][j]+dist[j][k]){
                    dp[i+mu[k]][k]=dp[i][j]+dist[j][k];
                }
            }
        }
    }

    long long best=dp[mu[num]-1][0];
    for(int i=1;i<num;++i){
        if(dp[mu[num]-1][i]==INT_MAX||dist[i][0]==INT_MAX)continue;
        best=min(best,dp[mu[num]-1][i]+dist[i][0]);
    }
    return best<=tot;
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
        for(int i=0;i<n;++i)adj[i].clear(),cnt[i]=0;
        a.clear();
        for(int i=0;i<m;++i){
            int u,v,w; cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        cin>>q;
        a.push_back(0);
        int cnt=0;
        for(int i=1;i<=q;++i){
            int x; cin>>x;
            if(x==0)++cnt;
            a.push_back(x);
        }

        cin>>tot;
        if(!q){cout<<0<<endl;continue;}
        for(int i=0;i<q+1;++i){
            dijkstra(a[i]);
            for(int j=0;j<q+1;++j)dd[i][j]=d[a[j]];
        }

        int ans=cnt;
        mu[0]=1;
        for(int i=1;i<=q+3;++i)mu[i]=2*mu[i-1];
        for(int i=1;i<mu[q+1];++i){
            if(!(i&1))continue;
            int num=0;
            int lst[q+5];
            for(int j=0;j<q+1;++j){
                if(i&(1<<j)){
                    lst[num]=j;
                    num++;
                }
            }
            //cout<<num<<endl;
            for(int j=0;j<num;++j){
                for(int k=0;k<num;++k){
                    //cout<<lst[j]<<' '<<lst[k]<<endl;
                    dist[j][k]=dd[lst[j]][lst[k]];
                    //cout<<dist[j][k]<<' ';
                }
                //cout<<endl;
            }

            if(TSP(num))ans=max(ans,num-1);
        }
        cout<<ans<<endl;
    }
}
