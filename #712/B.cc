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
string a, b;
int p1[N], p0[N];
int n, t, cur;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    cin >> t;
    while (t--) {
        memset(p1, 0, sizeof p1);
        memset(p0, 0, sizeof p0);
        cin >> n >> a >> b;
        p1[0] = (a[0] == '1');
        p0[0] = (a[0] == '0');
        for1(i, a.size()) {
            p1[i] = p1[i - 1] + (a[i] == '1' ? 1 : 0);
            p0[i] = p0[i - 1] + (a[i] == '0' ? 1 : 0);
        }

        bool ok = 1;
        cur = 0;
        for (int i = (int) a.size() - 1; i >= 0; --i) {
            if (a[i] != b[i] && cur % 2 == 0) {
                if (p1[i] == p0[i]) {
                    ++cur;
                } else {ok = 0; break;}
            } else if (a[i] == b[i] && cur % 2 == 1) {
                if (p1[i] == p0[i]) {
                    ++cur;
                } else {ok = 0; break;}
            }
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}