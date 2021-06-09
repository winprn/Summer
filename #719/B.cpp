/* ldmm is n00b */
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

int n, t;
bool ok = 1;

ll calc(int x, int y) { // x * (10^0 + .. + 10^y)
    ll kq = 1, prv = 1;
    for (int i = 1; i <= y; ++i) {
        kq += 10 * prv;
        prv *= 10;
    }

    return kq * x;
}

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

    cin >> t;
    while (t--) {
        ok = 1;
        cin >> n;
        int i, j;
        //bug(calc(1, 0));
        //bug(calc(3, 6));
        for (i = 0; i <= 9; ++i) {
            for (j = 1; j <= 9; ++j) {
                if (calc(j, i) > n) {
                    //bug(calc(j, i));
                    ok = 0;
                    break;
                } else if (calc(j, i) == n) {
                    ++j;
                    ok = 0;
                    break;
                }
            }

            if (!ok) break;
        }
        bug(i); bug(j);

        if (n < 10) cout << n << endl;
        else cout << 9 * i + (j - 1) << endl;
    }

#ifdef RICARDO
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
