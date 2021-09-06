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

const int N=55;
int a[N],v[N],mc[N][105],dp[N][105];
int n,m;

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
        int x; cin>>x;
        cin>>v[x];
    }

    for(int i=1;i<=50;++i){
        mc[i][0]=-1e6;
        for(int j=1;j<=i;++j){
            for(int k=0;k<i;++k){
                mc[i][j]=max(mc[i][j],mc[k][j-1]+v[i-k]);
            }
        }
    }

    for(int i=1;i<=n;++i){
        for(int k=1;k<=a[i];++k){
            for(int j=k-1;j<=100;++j)dp[i][j]=max(dp[i][j],dp[i-1][j-k+1]+mc[a[i]][k]);
        }
    }

    int ans=-1;
    for(int i=0;i<=100;++i)ans=max(ans,dp[n][i]-(i*(i+1))/2);
    cout<<ans;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
