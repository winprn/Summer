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

int n,m,a,b;

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

    cin>>n>>m>>a>>b;
    --a,--b;
    int i=a/m,ii=a%m;
    int j=b/m,jj=b%m;
    int k=(n-1)/m,kk=(n-1)%m;

    int ans=-1;
    if(i==j)ans=1;
    if(ii==jj+1)ans=2;
    if(j==k&&jj==kk)jj=m-1;
    if(j==i+1){
        if(ii==0&&jj==m-1)ans=1;
        else ans=2;
    }

    if(ans==-1){
        ans=1;
        ans+=(ii!=0);
        ans+=(jj!=m-1);
    }
    cout<<ans;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
