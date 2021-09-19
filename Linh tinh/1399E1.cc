#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<pair<int,int>> adj[N];
int a[N],dp[N];
long long S;
int n,t;

void dfs(int u,int p=-1){
    if(adj[u].size()==1)dp[p]=1;
    for(auto v:adj[u]){
        if(v.second==p)continue;
        dfs(v.first,v.second);
        if(p!=-1)dp[p]+=dp[v.second];
    }
}

signed main(){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    freopen("i","r",stdin);
    freopen("o","w",stdout);

    cin>>t;
    while(t--){
        cin>>n>>S;
        for(int i=0;i<=n;++i)dp[i]=0,adj[i].clear();
        for(int i=0;i<n-1;++i){
            int u,v; cin>>u>>v>>a[i];
            --u,--v;
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
        }
        dfs(0);

        set<pair<long long,int>> s;
        long long sum=0;
        for(int i=0;i<n-1;++i)s.insert({1LL*a[i]*dp[i]-1LL*a[i]/2*dp[i],i}),sum+=1LL*a[i]*dp[i];

        int ans=0;
        //cout<<sum<<endl;
        while(sum>S){
            int u=s.rbegin()->second;
            s.erase(prev(s.end()));
            //cout<<u<<' '<<dp[u]<<endl;
            sum-=1LL*a[u]*dp[u]-1LL*a[u]/2*dp[u];
            a[u]/=2;
            s.insert({1LL*a[u]*dp[u]-1LL*a[u]/2*dp[u],u});

            ++ans;
        }
        //cout<<sum<<endl;
        cout<<ans<<endl;
    }
}
