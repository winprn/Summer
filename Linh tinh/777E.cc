/* ldmm is n00b */
#include <bits/stdc++.h>

using namespace std;

#define Cerr cerr << "\nTest: "
#define endl "\n"
#define fi first
#define se second
#define pb push_back

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
typedef long long ll;
typedef double ld;

const int N=2e5+10;
vector<int> r;
pair<pii,int> a[N];
ll bit[N];
int n;

bool cmp(pair<pii,int> a,pair<pii,int> b){
    if(a.fi.se==b.fi.se)return a.fi.fi<b.fi.fi;
    return a.fi.se<b.fi.se;
}

void upd(int i,ll val){
    for(;i<=N;i+=i&(-i))bit[i]=max(bit[i],val);
}

ll get(int i){
    ll kq=0;
    for(;i>0;i-=i&(-i))kq=max(kq,bit[i]);

    return kq;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
#endif

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].fi.fi>>a[i].fi.se>>a[i].se;
        r.pb(a[i].fi.fi),r.pb(a[i].fi.se);
    }
    sort(a+1,a+n+1,cmp);
    sort(r.begin(),r.end());
    r.erase(unique(r.begin(),r.end()),r.end());

    for(int i=n;i>0;--i){
        int l=lower_bound(r.begin(),r.end(),a[i].fi.fi)-r.begin();
        int rr=lower_bound(r.begin(),r.end(),a[i].fi.se)-r.begin();
        //cout<<rr<<endl;
        upd(l+1,get(rr)+1LL*a[i].se);
    }
    cout<<get(N);

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
