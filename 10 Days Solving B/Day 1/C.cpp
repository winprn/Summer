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
int a[N], b[N];
ll cnt;
int n, t, ma, mb;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    cin >> t;
    while (t--) {
        ma = mb = 1e9 + 7;
        cin >> n;
        forn(i, n) {
            cin >> a[i];
            mini(ma, a[i]);
        }
        forn(i, n) {
            cin >> b[i];
            mini(mb, b[i]);
        }
    
        //cout << ma << ' ' << mb << endl;
        cnt = 0;
        forn(i, n) {
            if (a[i] > ma && b[i] > mb) {
                int tmp = a[i] - ma;
                tmp = min(tmp, b[i] - mb);
                cnt += tmp;

                a[i] -= tmp, b[i] -= tmp;
                //cout << i << ' ' << a[i] << ' ' << b[i] << endl;
            }
            if (a[i] > ma) {
                cnt += a[i] - ma;
                a[i] -= (a[i] - ma);
            }
            if (b[i] > mb) {
                cnt += b[i] - mb;
                b[i] -= (b[i] - mb);
            }
        }

        cout << cnt << endl;
    }
}