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

const ll inf=1e17;
const int N=4e3+10;
vector<int> res;
ll dp[2][N][N];
int a[N];
int n,k;

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

    cin>>n>>k;
    int tmp=k;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<=n;++i)for(int j=0;j<=k;++j)for(int l=0;l<2;++l)dp[l][i][j]=inf;

    dp[1][0][1]=a[0];
    dp[0][0][0]=0;
    for(int i=1;i<n;++i){
        for(int j=0;j<=k;++j){
            dp[0][i][j]=dp[0][i-1][j];
            dp[1][i][j]=dp[1][i-1][j];
            if(i>=2&&j>0)dp[0][i][j]=min(dp[0][i][j],dp[0][i-2][j-1]+a[i]);
            if(i>=2&&i!=n-1&&j>1)dp[1][i][j]=min(dp[1][i][j],dp[1][i-2][j-1]+a[i]);
        }
    }

    auto trace=dp[0];
    if(dp[0][n-1][k]>dp[1][n-1][k])trace=dp[1];
    cout<<trace[n-1][k]<<endl;

    int i=n-1,j=k;
    while(1){
        if(trace[i][j]==trace[i-1][j])--i;
        else{
            cout<<i<<' ';
            i-=2,--j;
        }
        if(j==0)break;
        if(i==0){cout<<0;break;}
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
