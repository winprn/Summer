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
ll a[N],b[N][105],C[N][105];
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

    cin>>n>>m;
    for(int i=0;i<N;++i)C[i][0]=1;
    for(int i=1;i<N;++i){
        for(int j=1;j<=min(i,100);++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }

    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=0;i<m;++i){
        int l,r,k; cin>>l>>r>>k;
        b[l][k]=(b[l][k]+1)%MOD;
        for(int j=0;j<=k;++j)b[r+1][j]=(b[r+1][j]-C[k-j+r-l][k-j]+MOD)%MOD;
//        b[k][l]=(b[k][l]+1)%MOD;
//        for(int j=0;j<=k;++j)b[j][r+1]=(b[j][r+1]-C[k-j+r-l][k-j]+MOD)%MOD;
    }

    for(int j=100;j>=0;--j){
        for(int i=1;i<=n;++i)b[i][j]=(b[i][j]+b[i-1][j]+b[i][j+1])%MOD;
    }

    for(int i=1;i<=n;++i)cout<<(a[i]+b[i][0])%MOD<<' ';

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
