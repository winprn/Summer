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

const int N=1e5+10;
map<pii,int> bit;
vector<int> times;
int q[N],t[N],a[N];
int n;

void upd(int t,int x,int v){
    for(;t<=N;t+=t&(-t))bit[{t,x}]+=v;
}

int get(int t,int x){
    int kq=0;
    for(;t>0;t-=t&(-t))kq+=bit[{t,x}];

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
    for(int i=0;i<n;++i){
        cin>>q[i]>>t[i]>>a[i];
        times.pb(t[i]);
    }

    sort(times.begin(),times.end());
    times.erase(unique(times.begin(),times.end()),times.end());
    for(int i=0;i<n;++i)t[i]=lower_bound(times.begin(),times.end(),t[i])-times.begin(),++t[i];

    for(int i=0;i<n;++i){
        if(q[i]==3){
            cout<<get(t[i],a[i])<<endl;
        }else{
            if(q[i]==2)upd(t[i],a[i],-1);
            else upd(t[i],a[i],1);
        }
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
