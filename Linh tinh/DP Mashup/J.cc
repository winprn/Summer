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
ll dp[N][15][5];
ll n,m,k,x;

void dfs(int u,int p){
    for(int v:adj[u]){
        if(v!=p)dfs(v,u);
    }

    ll dp1[(int)adj[u].size()+3][15];
    memset(dp1,0,sizeof(dp1));
    dp1[0][0]=1;
    int cnt=0;
    for(int v:adj[u]){
        if(v!=p){
            for(int i=0;i<=x;++i){
                for(int j=0;j<=x-i;++j){
                    int tot=i+j;
                    ll cur=dp[v][j][0]+dp[v][j][1]+dp[v][j][2];

                    dp1[cnt+1][tot]=(dp1[cnt+1][tot]+cur*dp1[cnt][i])%MOD;
                }
            }
            ++cnt;
        }
    }
    for(int i=0;i<=x;++i){
        dp[u][i][0]=(dp1[cnt][i]*(k-1))%MOD;
    }

    memset(dp1,0,sizeof(dp1));
    dp1[0][0]=1;
    cnt=0;
    for(int v:adj[u]){
        if(v!=p){
            for(int i=0;i<=x;++i){
                for(int j=0;j<=x-i;++j){
                    int tot=i+j;
                    ll cur=dp[v][j][0];

                    dp1[cnt+1][tot]=(dp1[cnt+1][tot]+cur*dp1[cnt][i])%MOD;
                }
            }
            ++cnt;
        }
    }
    for(int i=0;i<x;++i){
        dp[u][i+1][1]=(dp1[cnt][i])%MOD;
    }

    memset(dp1,0,sizeof(dp1));
    dp1[0][0]=1;
    cnt=0;
    for(int v:adj[u]){
        if(v!=p){
            for(int i=0;i<=x;++i){
                for(int j=0;j<=x-i;++j){
                    int tot=i+j;
                    ll cur=dp[v][j][0]+dp[v][j][2];

                    dp1[cnt+1][tot]=(dp1[cnt+1][tot]+cur*dp1[cnt][i])%MOD;
                }
            }
            ++cnt;
        }
    }
    for(int i=0;i<=x;++i){
        dp[u][i][2]=(dp1[cnt][i]*(m-k))%MOD;
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

    cin>>n>>m;
    for(int i=0;i<n-1;++i){
        int u,v; cin>>u>>v;
        adj[u].pb(v),adj[v].pb(u);
    }
    cin>>k>>x;
    dfs(1,-1);

    ll ans=0;
    for(int i=0;i<=x;++i){
        for(int j=0;j<3;++j)ans=(ans+dp[1][i][j])%MOD;
    }
    cout<<ans;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
/*
wait, AC?
⢀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⣠⣤⣶⣶
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⢰⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣀⣀⣾⣿⣿⣿⣿
⣿⣿⣿⣿⣿⡏⠉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿
⣿⣿⣿⣿⣿⣿⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠁⠀⣿
⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠙⠿⠿⠿⠻⠿⠿⠟⠿⠛⠉⠀⠀⠀⠀⠀⣸⣿
⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣴⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⢰⣹⡆⠀⠀⠀⠀⠀⠀⣭⣷⠀⠀⠀⠸⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠈⠉⠀⠀⠤⠄⠀⠀⠀⠉⠁⠀⠀⠀⠀⢿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⢾⣿⣷⠀⠀⠀⠀⡠⠤⢄⠀⠀⠀⠠⣿⣿⣷⠀⢸⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⡀⠉⠀⠀⠀⠀⠀⢄⠀⢀⠀⠀⠀⠀⠉⠉⠁⠀⠀⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿
*/
