#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> pii;

const int N = 1e4+10;
vector<pii>adj[N];
ll d[N],dp[N];
int n,m,ans=0;

int main() {
    freopen("thongke.inp", "r", stdin);
    freopen("thongke.out", "w", stdout);

    cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v,w;cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[u].pb({u,w});
    }

    memset(d,0x3f,sizeof d);
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,1});
    d[1]=0,dp[1]=1;
    while(!pq.empty()){
        int u=pq.top().se;
        ll du=pq.top().fi;
        pq.pop();

        if(du>d[u])continue;
        for(auto v:adj[u]){
            if(d[v.fi]>d[u]+v.se){
                dp[v.fi]=min(2LL,dp[u]);
                d[v.fi]=d[u]+v.se;
                pq.push({d[v.fi],v.fi});
            }else if(d[v.fi]==d[u]+v.se){
                dp[v.fi]+=dp[u];
                dp[v.fi]=min(2LL,dp[v.fi]);
            }
        }
    }

    for(int i=2;i<=n;++i)ans+=(dp[i]>1);
    cout<<ans<<endl;
}