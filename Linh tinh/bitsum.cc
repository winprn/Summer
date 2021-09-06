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

ll dp2[65][65];
int digs[65];
ll l,r;
int t;

ll _dp2(int pos,int cnt){
    if(pos==60)return cnt;
    ll &ans=dp2[pos][cnt];
    if(ans!=-1)return ans;

    return ans=_dp2(pos+1,cnt)+_dp2(pos+1,cnt+1);
}

ll _dp(int pos,int cnt){
    if(pos==60)return cnt;
    ll ans=_dp(pos+1,cnt+digs[pos]);

    if(digs[pos])ans+=_dp2(pos+1,cnt);
    return ans;
}

ll solve(ll x){
    for(int i=0;i<60;++i)digs[60-i-1]=(x>>i)&1;
//    for(int i:digs)cout<<i<<' ';
//    cout<<endl;

    return _dp(0,0);
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

    memset(dp2,-1,sizeof(dp2));
    cin>>t;
    while(t--){
        cin>>l>>r;
        cout<<solve(r)-solve(l-1)<<endl;
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
