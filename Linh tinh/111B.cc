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
vector<int> d[N];
int lst[N];
int n;

void sieve(){
    for(int i=1;i<=N-10;++i){
        for(int j=i;j<N;j+=i)d[j].pb(i);
    }
    //d.erase(unique(d.begin(),d.end()),d.end());
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
    sieve();
    memset(lst,-1,sizeof(lst));
    for(int i=1;i<=n;++i){
        int a,b,ans=0; cin>>a>>b;
        ans=0;
        for(int j:d[a]){
            if(lst[j]<i-b)++ans;

            lst[j]=i;
        }
        cout<<ans<<endl;
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
