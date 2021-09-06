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

const int N=1e6+10;
string s;
pair<int,pii> st[8*N];
int n,m;

pair<int,pii> mer(pair<int, pii>a, pair<int,pii> b){
    int tmp=min(a.se.fi,b.se.se);
    return {a.fi+b.fi+tmp,{a.se.fi+b.se.fi-tmp,a.se.se+b.se.se-tmp}};
}

void build(int id,int l,int r){
    if(l==r){
        if(s[l-1]=='(')st[id].se.fi=1;
        else st[id].se.se=1;
        return ;
    }

    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);

    auto tmp=min(st[id*2].se.fi,st[id*2+1].se.se);
    st[id].fi=st[id*2].fi+st[id*2+1].fi+tmp;
    st[id].se.fi=st[id*2].se.fi+st[id*2+1].se.fi-tmp;
    st[id].se.se=st[id*2].se.se+st[id*2+1].se.se-tmp;
}

pair<int,pii> get(int id,int l,int r,int tl,int tr){
    if(l>tr||r<tl)return {0,{0,0}};
    if(tl<=l&&r<=tr)return st[id];

    int m=(l+r)/2;
    auto a=get(id*2,l,m,tl,tr),b=get(id*2+1,m+1,r,tl,tr);
    auto tmp=min(a.se.fi,b.se.se);

    return {a.fi+b.fi+tmp,{a.se.fi+b.se.fi-tmp,a.se.se+b.se.se-tmp}};
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

    cin>>s;
    n=(int)s.size();
    memset(st,0,sizeof(st));
    build(1,1,n);

    cin>>m;
    while(m--){
        int l,r; cin>>l>>r;
        cout<<get(1,1,n,l,r).fi*2<<endl;
    }

#ifdef RICARDO
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
