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

const int N=3e4+10;
int a[3][N],dp[N][2];
int n;

int _dp(int i,bool lst){
    if(i>n)return 0;
    if(i==n-1){
        if(lst)return a[1][i];
        else return a[0][i];
    }
    int &ans=dp[i][lst];
    if(ans!=-1)return ans;

    if(lst)ans=max({ans,a[1][i]+_dp(i+1,1),a[2][i]+_dp(i+1,0)});
    else ans=max({ans,a[0][i]+_dp(i+1,1),a[1][i]+_dp(i+1,0)});
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

    cin>>n;
    for(int i=0;i<3;++i){
        for(int j=0;j<n;++j)cin>>a[i][j];
    }

    memset(dp,-1,sizeof(dp));
    if(n==1)cout<<a[0][0];
    else cout<<max(a[1][0]+_dp(1,0),a[0][0]+_dp(1,1));

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
