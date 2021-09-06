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
int a[N],b[N];
int n,m,c,d,k;

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

    cin>>n>>m>>c>>d>>k;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];

    ll ans=-1;
    for(int i=0;i<n;++i){
        int l=k-i;
        int tmp=lower_bound(b,b+m,a[i]+c)-b;
        if(l>=m-tmp){ans=1e10;break;}
        ans=max(ans,1LL*b[tmp]+d);
    }
    cout<<ans;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
