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

const ll inf=2e9;
const int N=1e3+10;
int dp[2*N][N];
int a[N],b[2*N];
int n,m,k;

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

    cin>>n>>m>>k;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<m;++i)cin>>b[i];
    sort(b,b+m);

    for(int i=0;i<=m;++i)for(int j=0;j<=n;++j)dp[i][j]=inf;

    dp[0][0]=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<=n;++j){
            mini(dp[i+1][j],dp[i][j]);
            if(j<n)mini(dp[i+1][j+1],max(dp[i][j],abs(a[j]-b[i])+abs(k-b[i])));
        }
    }
    cout<<dp[m][n];

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
