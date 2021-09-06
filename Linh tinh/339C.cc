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
string s;
int ans[N];
bool vis[N][15][15];
int n;

bool dfs(int u,int lst,int sum){
    if(u&&sum<=0||sum>10)return 0;
    if(u==n){
        cout<<"YES"<<endl;
        for(int i=0;i<n;++i)cout<<ans[i]+1<<' ';
        return 1;
    }
    if(vis[u][lst][sum])return 0;
    vis[u][lst][sum]=1;
    for(int i=0;i<10;++i){
        if(s[i]=='1'&&i!=lst){
            ans[u]=i;
            if(dfs(u+1,i,i+1-sum))return 1;
        }
    }
    return 0;
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

    cin>>s>>n;

    if(!dfs(0,-1,0))cout<<"NO";

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
