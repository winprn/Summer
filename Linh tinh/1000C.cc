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
vector<ll> a;
ll l[N],r[N],ans[N],cnt[2*N];
int n;

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
    for(int i=0;i<n;++i){
        cin>>l[i]>>r[i];
        a.pb(l[i]),a.pb(r[i]+1);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());

    for(int i=0;i<n;++i){
        int tmp=lower_bound(a.begin(),a.end(),l[i])-a.begin();
        int tmp2=lower_bound(a.begin(),a.end(),r[i]+1)-a.begin();
        cnt[tmp]++;
        cnt[tmp2]--;
    }
    for(int i=1;i<2*n;++i)cnt[i]+=cnt[i-1];

    for(int i=1;i<2*n;++i)ans[cnt[i-1]]+=a[i]-a[i-1];
    for(int i=1;i<=n;++i)cout<<ans[i]<<' ';

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
