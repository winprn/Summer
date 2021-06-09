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
#define sqr(x) (x) * (x)

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

const int N = 1e2 + 5;
int a[N][N];
int n, t, li, lj, cnt;

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
        li = lj = -1;
        cnt = 0;
        cin >> n;
        bug(sqr(n));
        if (n == 1) cout << '1' << endl;
        else if (n == 2) cout << "-1" << endl;
        else {
            forn(i, n) {
                //bug(li); bug(lj);
                if (li != -1) break ;
                forn(j, n) {
                    if (2 * cnt + 1 <= sqr(n)) {
                        a[j][i] = 2 * cnt + 1;
                        ++cnt;
                    } else {
                        li = i;
                        lj = j;
                        break ;
                    }
                }
            }

            bug(li); bug(lj);
            cnt = 1;
            int i = li, j = lj;
            while (i < n) {
                a[j][i] = 2 * cnt;
                ++cnt;
                ++j;
                if (j == n) {
                    j = 0;
                    ++i;
                }
            }

            forn(i, n) {
                forn(j, n) {
                    cout << a[i][j] << ' ';
                }
                cout << endl;
            }
        }
    }

#ifdef RICARDO
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
