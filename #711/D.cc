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

const int inf = 1e9;
const int N = 205;
const int M = 1e5 + 10;
ll x[N];
int t[N], y[N], dp[N][M];
int n, m;

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

    cin >> n >> m;
    forn(i, n) cin >> t[i] >> x[i] >> y[i];
    forn(i, n + 1) forn(j, m + 1) dp[i][j] = inf;

    dp[0][0] = 0;
    forn(i, n) {
        for (int j = 0; j <= m; ++j) {
            if (dp[i][j] == inf) continue ;
            dp[i + 1][j] = dp[i][j];
            int sum = j;
            for (int k = 0; k < y[i]; ++k) {
                if (t[i] == 1) {
                    sum = sum + (x[i] + 99999) / 100000;
                } else {
                    sum = ceil((float) sum * (float) x[i] / 100000.);
                }

                if (sum > m) break;
                if (dp[i][sum] < inf) break;
                dp[i + 1][sum] = min(dp[i + 1][sum], i + 1);
            }
        }
    }

    for1(i, m) {
        cout << (dp[n][i] == inf ? -1 : dp[n][i]) << ' ';
    }

#ifdef RICARDO
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
