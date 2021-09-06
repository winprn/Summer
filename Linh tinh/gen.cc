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

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

const int test = 100;
const int inf=1e9;

long long Rand(int mn,int mx) {
    assert(mn <= mx);
    return rd() % (mx - mn + 1) + mn;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    srand(time(NULL));
    //freopen(((NAME + ".inp").c_str()), "w", stdout);
    forn(idx, test) {
        //gen
        ofstream inp("i");
            int n=Rand(1,10),t=Rand(3,10);
            inp<<n<<' '<<t<<endl;
            for(int i=0;i<n;++i){
                int j=Rand(1,100),k=Rand(0,t-1);
                inp<<j<<' '<<k<<endl;
            }
        inp.close();
        //end gen
        system(("bank.exe"));
        system(("bank_wa.exe"));
        if (system(("fc o ans")) != 0) {
            cout << "Test " << idx << " wrong" << endl;
            return 0;
        }

        cout << "Test " << idx << " good" << endl;
    }

    return 0;

#ifdef RICARDO
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
