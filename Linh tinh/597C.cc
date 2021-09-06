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

const int N=2e5+10;
ll a[N],bit[N][15],dp[N][15];
int n,k;

void upd(int i,int j,ll val){
    for(;i<=N;i+=i&(-i))bit[i][j]+=val;
}

ll get(int i,int j){
    ll kq=0;
    for(;i>0;i-=i&(-i))kq+=bit[i][j];

    return kq;
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

    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i],dp[i][0]=1;

    for(int j=1;j<=k;++j){
        for(int i=1;i<=n;++i){
            dp[i][j]=get(a[i]-1,j);
            upd(a[i],j,dp[i][j-1]);
        }
    }

    ll ans=0;
    for(int i=1;i<=n;++i)ans+=dp[i][k];
    cout<<ans;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
