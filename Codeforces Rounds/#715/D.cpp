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

vector<char> ans;
string s1, s2, s3;
int n, t;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s1 >> s2 >> s3;

        int i1, i2, i3;
        i1 = i2 = i3 = 0;

        ans.clear();
        while (i1 < n * 2 && i2 < n * 2 && i3 < n * 2) {
            if (s1[i1] == s2[i2]) {
                ans.pb(s1[i1]);
                ++i1, ++i2;
            } else if (s1[i1] == s3[i3]) {
                ans.pb(s1[i1]);
                ++i1, ++i3;
            } else {
                ans.pb(s2[i2]);
                ++i2, ++i3;
            }
        }

        int sze = (int) ans.size();
        //cout << i1 << ' ' << i2 << ' ' << i3 << endl;
        int mn = min({i1, i2, i3});
        if (mn == i1) mn = min(i2, i3);
        else if (mn == i2) mn = min(i1, i3);
        else mn = min(i1, i2);
        for (int i = mn; i < 2 * n; ++i) {
            if (mn == i1) ans.pb(s1[i]);
            else if (mn == i2) ans.pb(s2[i]);
            else ans.pb(s3[i]);
        }

        for (auto i : ans) cout << i;
        cout << endl;
    }
}