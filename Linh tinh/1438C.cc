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

const int N=1e2+10;
int a[N][N];
int n,m,t;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef RICARDO
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
#endif

    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j)cin>>a[i][j];
        }

        for(int i=0;i<n;++i){
            if(i%2==0){
                for(int j=0;j<m;j+=2){
                    if(a[i][j]&1)++a[i][j];
                }
                for(int j=1;j<m;j+=2){
                    if(!(a[i][j]&1))++a[i][j];
                }
            }else{
                for(int j=1;j<m;j+=2){
                    if(a[i][j]&1)++a[i][j];
                }
                for(int j=0;j<m;j+=2){
                    if(!(a[i][j]&1))++a[i][j];
                }
            }
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j)cout<<a[i][j]<<' ';
            cout<<endl;
        }
    }

#ifdef RICARDO
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
