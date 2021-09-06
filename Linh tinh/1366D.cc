#include <bits/stdc++.h>

using namespace std;

#define Cerr cerr << "\nTest: "
#define endl "\n"
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fastio { ios_base::sync_with_stdio(false), cin.tie(NULL); }
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)

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
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef double ld;

//=================================================CODE=================================================//

const int MX=1e7+10;
const int N=5e5+10;
bitset<MX> pri;
vector<int> pr;
pii ans[N];
int d[MX];
int n;

void sieve(){
    pri.set(); pri[0] = pri[1] = 0;
    for(int i=2;i<MX;++i){
        if(pri[i]){
            pr.pb(i);
            d[i]=i;
        }
        for(int j:pr){
            if(i*j>=MX)break;
            d[i*j]=j;
            pri[i*j]=0;
            if(i%j==0)break;
        }
    }
}

pii get(int x){
    int tmp=d[x];
    int a=x,b=1;
    while(a%tmp==0){
        a/=tmp;
        b*=tmp;
    }

    if(a!=1)return {a,b};
    return {-1,-1};
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef RICARDO
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
#endif

    sieve();
    cin>>n;
    for(int i=0;i<n;++i){
        int x; cin>>x;
        ans[i]=get(x);
    }
    for(int i=0;i<n;++i)cout<<ans[i].fi<<' ';
    cout<<endl;
    for(int i=0;i<n;++i)cout<<ans[i].se<<' ';
    cout<<endl;

#ifdef RICARDO
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
