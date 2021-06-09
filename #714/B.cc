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

const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int n, t, mn = 1e9 + 7;
bool ok;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    cin >> t;
    while (t--) {
        mn = 1e9 + 7;
        cin >> n;
        forn(i, n) {
            cin >> a[i];
            mini(mn, a[i]);
        }

        ok = 1;
        forn(i, n) {
            if ((mn & a[i]) != mn) {ok = 0; break;}
        }

        if (count(a, a + n, mn) < 2 || !ok) cout << 0 << endl;
        else {
            int cnt = count(a, a + n, mn);
            ll ans = 1LL * cnt * (cnt - 1);
            ans %= MOD;

            for (int i = 1; i <= n - 2; ++i) {
                ans = ans * 1LL * i % MOD;
            }
            cout << ans << endl;
        }
    }
}