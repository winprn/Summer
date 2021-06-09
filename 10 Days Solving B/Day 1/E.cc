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

const int N = 105;
char a[N][N];
int t, n, m, cnt, cnt2, cnt3, cnt4;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        forn(i, n) {
            forn(j, m) cin >> a[i][j];
        }

        cnt = cnt2 = cnt3 = cnt4 = 0;
        for (int i = 0; i < m; ++i) {
            if (a[n - 1][i] == 'D') ++cnt;
            else ++cnt3;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i][m - 1] == 'R') ++cnt2;
            else ++cnt4;
        }

        //cout << cnt << ' ' << cnt2 << endl;
        cout << cnt + cnt2 << endl;
    }
}