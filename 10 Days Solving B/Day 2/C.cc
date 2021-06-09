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

const int N = 2e3 + 10;
int s[N];
bool mark[50];
int n, a, b, t, lst;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    cin >> t;
    while (t--) {
        memset(s, -1, sizeof s);
        lst = -1;
        cin >> n >> a >> b;
        for (int i = 0; i < n; ++i) {
            memset(mark, 0, sizeof mark);
            int cur = 0;
            if (i + a > n) break;
            for (int j = i; j < i + a; ++j) {
                if (s[j] == -1) {
                    if (cur == b) s[j] = lst;
                    else {
                        if (lst == 25) lst = -1;
                        s[j] = ++lst;
                        ++cur;
                    }
                } else {
                    if (!mark[s[j]]) ++cur;
                    mark[s[j]] = 1;
                }
            }
        }

        forn(i, n) cout << (char) ('a' + s[i]);
        cout << endl;
    }
}