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
int dp[N],dp1[N][N];
int t,cases=0;

int _dp1(int l,int r){
    if(l>=r)return 1;
    int &ans=dp1[l][r];
    if(ans!=-1)return ans;

    if(s[l]==s[r])return ans=_dp1(l+1,r-1);
    return ans=0;
}

int _dp(int i){
    if(i<0)return 0;
    int &ans=dp[i];
    if(ans!=-1)return ans;

    ans=1e9;
    for(int j=0;j<=i;++j){
        if(_dp1(j,i))ans=min(ans,1+_dp(j-1));
    }
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

    cin>>t;
    while(t--){
        cin>>s;
        int n=(int)s.size();

        memset(dp1,-1,sizeof(dp1));
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<++cases<<": "<<_dp(n-1)<<endl;
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
