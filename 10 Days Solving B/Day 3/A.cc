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

const int N = 55;
char a[N][N];
bool mark[N][N];
int n;

bool ok(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < n && a[i][j] == '.' && !mark[i][j]);
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

    cin >> n;
    forn(i, n) forn(j, n) cin >> a[i][j];

    forn(i, n) {
        forn(j, n) {
            if (ok(i, j)) {
                if (ok(i + 1, j) && ok(i, j + 1) && ok(i - 1, j) && ok(i, j - 1)) {
                    mark[i][j] = mark[i + 1][j] = mark[i][j + 1] = mark[i - 1][j] = mark[i][j - 1] = 1;
                }
            }
        }
    }
    bool good = 1;
//    forn(i, n) {
//        forn(j, n) cout << mark[i][j];
//        cout << endl;
//    }
    forn(i, n) {
        forn(j, n) if (a[i][j] == '.' && !mark[i][j]) {good = 0; break;}
    }
    if (good) cout << "YES" << endl;
    else cout << "NO" << endl;

#ifdef RICARDO
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}