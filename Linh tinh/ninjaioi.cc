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

const int N=1e3+10;
vector<int> adj[N],adj2[N];
stack<int> q;
int low[N],num[N],tp[N];
bool onStack[N],vis[N];
int n,m,tot,cnt,t;

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
            low[v]=num[u];
            tp[v]=tot;
            if(v==u)break;
        }
        ++tot;
    }
}

void dfs2(int u){
    vis[u]=1;
    for(int v:adj2[u]){
        if(!vis[v])dfs2(v);
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

    cin>>t;
    for(int c=1;c<=t;++c){
        cout<<"Case "<<c<<": ";
        cin>>n>>m;
        for(int i=1;i<=n;++i)adj[i].clear();
        for(int i=0;i<m;++i){
            int u,v; cin>>u>>v;
            adj[u].pb(v);
        }

        memset(num,0,sizeof(num));
        memset(low,0,sizeof(low));
        memset(tp,0,sizeof(tp));
        tot=cnt=0;
        for(int i=1;i<=n;++i){
            if(!num[i])dfs(i);
        }

        for(int i=1;i<=n;++i)adj2[i].clear();
        for(int i=1;i<=n;++i){
            for(int j:adj[i]){
                if(tp[i]!=tp[j])adj2[tp[i]].pb(tp[j]);
            }
        }

        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=1;i<=tot;++i){
            if(!vis[i])cout<<i<<endl,dfs2(i),++ans;
        }
        cout<<ans<<endl;
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
