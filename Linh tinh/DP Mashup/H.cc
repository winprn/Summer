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

const ll inf=1e18;
const int N=3e3+10;
pii a[N];
ll dp[N][5];
int n;

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
    for(int i=0;i<n;++i)cin>>a[i].fi;
    for(int i=0;i<n;++i)cin>>a[i].se;

    for(int i=0;i<n;++i)dp[i][1]=a[i].se,dp[i][2]=dp[i][3]=inf;
    for(int i=0;i<n;++i){
        for(int j=i-1;j>=0;--j){
            if(a[i].fi>a[j].fi){
                dp[i][2]=min(dp[i][2],dp[j][1]+a[i].se);
                dp[i][3]=min(dp[i][3],dp[j][2]+a[i].se);
            }
        }
    }

    ll ans=inf;
    for(int i=0;i<n;++i)ans=min(ans,dp[i][3]);
    cout<<(ans==inf?-1:ans);

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
