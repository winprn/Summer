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

const int N=300005;
const int MX=1e6+10;
pair<pii,int> b[N];
int a[N],bit[N],ans[N],p[MX];
int n,q;

bool cmp(pair<pii,int> a,pair<pii,int> b){
    if(a.fi.fi==b.fi.fi)return a.fi.se<b.fi.se;
    return a.fi.fi<b.fi.fi;
}

void upd(int i,int v){
    for(;i<=N;i+=i&(-i))bit[i]+=v;
}

int get(int i){
    int kq=0;
    for(;i>0;i-=i&(-i))kq+=bit[i];

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
        cin>>a[i];
        p[a[i]]=-1;
    }
    cin>>q;
    for(int i=0;i<q;++i){
        cin>>b[i].fi.se>>b[i].fi.fi;
        b[i].se=i;
    }
    sort(b,b+q,cmp);

    memset(bit,0,sizeof(bit));
    int id=0;
    for(int i=1;i<=n;++i){
        if(p[a[i]]!=-1)upd(p[a[i]],-1);
        p[a[i]]=i;
        upd(i,1);
        while(id<q&&i==b[id].fi.fi){
            ans[b[id].se]=get(b[id].fi.fi)-get(b[id].fi.se-1);
            ++id;
        }
    }
    for(int i=0;i<q;++i)cout<<ans[i]<<endl;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
