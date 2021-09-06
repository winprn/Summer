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
typedef vector<pll> vpll;
typedef double ld;
 
//=================================================CODE=================================================//
 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    freopen("doanthang.inp", "r", stdin);
    freopen("doanthang.out", "w", stdout);

    int n, k=1; cin >> n;
    vpll a(n);
    forn(i, n) cin >> a[i].se >> a[i].fi;
    sort(all(a));
 
    multiset<int> s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int ok = 0;
        if (!s.empty()) {
            auto it = s.upper_bound(a[i].se);
            if (it != s.begin()) {
                --it;
                if (*it <= a[i].se) {
                    s.erase(it);
                    s.insert(a[i].fi);
                    ok = 1, ++ans;
                }
            }
        }
        if ((int) s.size() < k && !ok) {
            s.insert(a[i].fi);
            ++ans;
        }
    }
    cout << ans << endl;
 
#ifdef RICARDO
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}