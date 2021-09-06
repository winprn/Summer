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

const int N=1e2+10;
vector<pii> adj[N];
int dp[N][N][30];
int n,m;

int dfs(int u,int v,int cur){
    int &ans=dp[u][v][cur];
    if(ans!=-1)return ans;
    ans=0;
    for(pii x:adj[u]){
        if(cur<=x.se){
            if(!dfs(v,x.fi,x.se))ans=1;
        }
    }

    return ans;
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

    cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v;
        char c;
        cin>>u>>v>>c;
        adj[u].pb({v,c-'a'});
    }

    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(dfs(i,j,0))cout<<'A';
            else cout<<'B';
        }
        cout<<endl;
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
