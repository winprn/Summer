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

const int N=1e5+10;
int a[N];
ll A,B;
int n,k;

ll solve(ll l,ll r){
    int i=lower_bound(a,a+k,l)-a;
    int j=upper_bound(a,a+k,r)-a;
    --j;
    int num=j-i+1;

    ll ans;
    if(num==0)ans=A;
    else ans=B*num*(r-l+1);

    if(l==r||num==0)return ans;
    int m=(l+r)/2;
    return ans=min(ans,solve(l,m)+solve(m+1,r));
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

    cin>>n>>k>>A>>B;
    for(int i=0;i<k;++i)cin>>a[i];
    sort(a,a+k);

    cout<<solve(1,(1LL<<n));

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
