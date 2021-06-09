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

const int N = 1e5 + 10;
int a[N], b[N];
int n, cnt, mx;

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
    for1(i, n) cin >> a[i];
    for (int i = 2; i <= n; ++i) b[i] = (a[i - 1] < a[i]);

    for (int j = 2, i = 2; i <= n; j = i = j + 1) {
        int cur = b[i];
        while (j + 1 <= n && cur == b[j + 1]) ++j;
        int l = j - i + 2;
        if (maxi(mx, l)) cnt = 1;
        else if (l == mx) ++cnt;
    }

    if (cnt != 2 || mx % 2 == 0) cout << '0';
    else {
        bool ok = 0;
        for (int i = 3; i <= n; ++i) {
            if (b[i - 1] && !b[i]) {
                int l = i - 1, r = i;
                while (l > 2 && b[l - 1]) --l;
                while (r + 1 <= n && !b[r + 1]) ++r;

                if ((i - 1) - (l - 1) + 1 == mx && r - (i - 1) + 1 == mx) {
                    ok = 1;
                    break;
                }
            }
        }

        cout << ok;
    }

#ifdef RICARDO
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
