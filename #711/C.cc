/* ldmm is n00b */
#include <bits/stdc++.h>

using namespace std;

#define Cerr cerr << "\nTest: "
#define endl "\n"
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ms(a, x) memset(a, (x), sizeof a);
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
const int N = 2e3 + 10;
int dp[N][N][2];
int n, k, t;

int solve(int cur, int num, int dir) {
    if (num == 1) return 1;
    if (dp[cur][num][dir] != -1) return dp[cur][num][dir];

    int kq = 2;
    if (dir == 0) {
        if (cur < n) kq += solve(cur + 1, num, dir) - 1;
        kq %= MOD;

        if (cur > 1) kq += solve(cur - 1, num - 1, !dir) - 1;
        kq %= MOD;
    } else {
        if (cur > 1) kq += solve(cur - 1, num, dir) - 1;
        kq %= MOD;

        if (cur < n) kq += solve(cur + 1, num - 1, !dir) - 1;
        kq %= MOD;
    }

    return dp[cur][num][dir] = kq;
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
        ms(dp, -1);
        cin >> n >> k;
        cout << solve(1, k, 0) << endl;
    }

#ifdef RICARDO
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
