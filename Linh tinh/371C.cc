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

string s;
ll a[3],b[3],c[3],cnt[50];
ll n;

bool ok(ll x){
    b[0]=x*cnt['B'-'A'],b[1]=x*cnt['S'-'A'],b[2]=x*cnt['C'-'A'];
    b[0]-=a[0],b[1]-=a[1],b[2]-=a[2];

    ll cost=0;
    if(b[0]>0)cost+=1LL*b[0]*c[0];
    if(b[1]>0)cost+=1LL*b[1]*c[1];
    if(b[2]>0)cost+=1LL*b[2]*c[2];

    return n>=cost;
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

    cin>>s;
    for(char i:s)cnt[i-'A']++;
    cin>>a[0]>>a[1]>>a[2]>>c[0]>>c[1]>>c[2];
    cin>>n;

    ll l=0,r=1e15,ans=0;
    for(int i=0;i<64;++i){
        ll m=l+(r-l)/2;
        if(ok(m))ans=m,l=m+1;
        else r=m-1;
    }
    cout<<ans;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
