/* ldmm is n00b */
#include <bits/stdc++.h>

using namespace std;

#define Cerr cerr << "\nTest: "
#define endl "\n"
#define fi first
#define se second
#define pb push_back

#ifdef RICARDO
    #define bug(x) cerr << #x << " = " << (x) << endl;
    #define block if(1)
#else
    #define bug(x) "IDINGO"
    #define block if(0)
#endif


template<class T> bool mini(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool maxi(T &a, T b) { return a < b ? (a = b, true) : false; }

typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;

const int MOD=1e9+7;
const int N=1e5+10;
vector<int> adj[N];
stack<int> q;
int a[N],low[N],num[N],mn[N],tp[N],t[N];
bool onStack[N];
int n,m,tot,cnt;

void dfs(int u){
    low[u]=num[u]=++cnt;
    onStack[u]=1;
    q.push(u);

    for(int v:adj[u]){
        if(!num[v])dfs(v);
        if(onStack[v])low[u]=min(low[u],low[v]);
    }

    if(low[u]==num[u]){
        while(1){
            int v=q.top();
            q.pop();
            onStack[v]=0;
            low[v]=low[u];
            tp[v]=tot;
            mini(mn[tp[v]],a[v]);
            if(v==u)break;
        }

        ++tot;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
#endif

    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    cin>>m;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
    }

    memset(mn,0x3f3f3f,sizeof(mn));
    for(int i=1;i<=n;++i){
        if(!num[i])dfs(i);
    }

    for(int i=1;i<=n;++i){
        if(a[i]==mn[tp[i]])++t[tp[i]];
    }

    pair<ll,ll> ans;
    ans.fi=mn[0],ans.se=t[0];
    for(int i=1;i<tot;++i)ans.fi+=mn[i],ans.se=(ans.se*t[i])%MOD;
    cout<<ans.fi<<' '<<ans.se;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
