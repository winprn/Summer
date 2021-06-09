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
string s;
bool mark[N];
int t;

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
        memset(mark, 0, sizeof mark);
        cin >> s;
        int n = (int) s.size();
        bug(n);
        if (count(s.begin(), s.end(), 'a') == (int) s.size()) {
            cout << "NO" << endl;
            continue ;
        }

        for (int i = n - 1; i >= n / 2; --i) {
            if (s[i] == 'a') {
                bug(i); bug(n - i - 1);
                mark[n - i - 1] = 1;
            }
        }

        bool done = 0;
        cout << "YES" << endl;
        forn(i, n) {
            if (!mark[i] && !done) {cout << 'a'; done = 1;}
            cout << s[i];
        }
        cout << endl;
    }
}
