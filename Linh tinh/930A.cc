#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

const int N=1e5+10;
vector<int> adj[N];
int cnt[N];
int n,ans=0,mx;

void dfs(int u, int d){
    cnt[d]++;
    mx=max(mx,d);
    for(int v:adj[u])dfs(v,d+1);
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=1;i<n;++i){
        int x; cin>>x;
        adj[x].pb(i+1);
    }
    dfs(1,0);

    for(int i=0;i<=mx;++i)ans+=cnt[i]%2;
    cout<<ans;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}