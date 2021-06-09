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

const int td[4] = {1, -1, 0, 0};
const int tc[4] = {0, 0, 1, -1};
const ll inf = 1e18;
const int N = 2e3 + 10;
pair<ll, pii> portal[N * N];
ll a[N][N], d[N][N], d1[N][N];
ll ans = 0, ans2 = 0, w, best = 1e18;
int n, m, t;

bool ok(int i, int j) {
    return (i >= 1 && i <= n && j >= 1 && j <= m && a[i][j] >= 0);
}

void bfs(int si, int sj, ll (&d)[N][N]) {
    queue<pii> q;
    q.push({si, sj});
    for1(i, n) {
        for1(j, m) d[i][j] = inf;
    }
    d[si][sj] = 0;

    while (!q.empty()) {
        int ui = q.front().fi;
        int uj = q.front().se;
        q.pop();

        forn(k, 4) {
            int vi = ui + td[k];
            int vj = uj + tc[k];

            if (ok(vi, vj)) {
                if (d[vi][vj] > d[ui][uj] + w) {
                    d[vi][vj] = d[ui][uj] + w;
                    q.push({vi, vj});
                }
            }
        }
    }
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

    cin >> n >> m >> w;
    for1(i, n) {
        for1(j, m) {
            cin >> a[i][j];
        }
    }

    bfs(1, 1, d);
    bfs(n, m, d1);

    ans = d[n][m], ans2 = 0;
    for1(i, n) {
        for1(j, m) {
            if (a[i][j] > 0) {
                mini(best, d1[i][j] + a[i][j]);
            }
        }
    }
    for1(i, n) {
        for1(j, m) {
            if (a[i][j] > 0) {
                mini(ans, d[i][j] + a[i][j] + best);
            }
        }
    }

    if (ans == 1e18) cout << "-1" << endl;
    else cout << ans << endl;

#ifdef RICARDO
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
