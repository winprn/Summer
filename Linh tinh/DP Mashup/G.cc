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
int dp[N][100*N];
int n,m,t,d;

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

    cin>>n>>m>>t>>d;

    memset(dp,-1,sizeof(dp));
    dp[0][n]=n;
    for(int i=1;i<t;++i){
        for(int j=0;j<=2000;++j){
            for(int k=0;k<=d;++k){
                if(j-k>=0){
                    if(dp[i-1][j]!=-1)dp[i][j-k]=max(dp[i][j-k],dp[i-1][j]+j-k);
                }
                if(dp[i-1][j]!=-1)dp[i][j+k]=max(dp[i][j+k],dp[i-1][j]+j+k);
            }
        }
    }
    cout<<dp[t-1][m];

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
