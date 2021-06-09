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

const int N = 3e5 + 10;
vi cnt[N];
int a[N];
ll ans;
int n, q;

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

    cin >> n >> q;
    for1(i, n) {
        cin >> a[i];
        cnt[a[i]].pb(i);
    }

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (q--) {
        ans = 1;
        int l, r; cin >> l >> r;
        forn(i, 40) {
            int idx = a[uniform_int_distribution<int>(l, r)(rng)];
            int times = upper_bound(cnt[idx].begin(), cnt[idx].end(), r) - lower_bound(cnt[idx].begin(), cnt[idx].end(), l);

            maxi(ans, 1LL * 2 * times - (r - l + 1));
        }
        cout << ans << endl;
    }

#ifdef RICARDO
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
