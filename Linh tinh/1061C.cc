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
int a[N],dp[N*10];
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
    for(int i=0;i<n;++i)cin>>a[i];
    dp[0]=1;

    vector<int> cur;
    for(int i=0;i<n;++i){
        cur.clear();
        for(int j=1;j*j<=a[i];++j){
            if(a[i]%j==0){
                cur.pb(j);
                if(j*j!=a[i])cur.pb(a[i]/j);
            }
        }
        sort(cur.rbegin(),cur.rend());

        for(int j:cur)dp[j]+=dp[j-1],dp[j]%=MOD;
    }

    int ans=0;
    for(int i=1;i<=n;++i)ans+=dp[i],ans%=MOD;
    cout<<ans;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
