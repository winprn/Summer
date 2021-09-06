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
map<int, bool> mark;
int a[N];
int n,l,x,y;

bool get(int x){
    for(int i=0;i<n;++i)if(mark[a[i]-x])return 1;
    return 0;
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

    cin>>n>>l>>x>>y;
    for(int i=0;i<n;++i)cin>>a[i],mark[a[i]]=1;

    if(mark[x]&&mark[y])cout<<0;
    else if(mark[x+y])cout<<1<<endl<<x<<endl;
    else{
        bool ok=get(x),ok2=get(y);
        int ans=-1;
        for(int i=0;i<n;++i){
            if(a[i]+x<=l&&(mark[a[i]+x+y]||mark[a[i]+x-y]))ans=a[i]+x;
            if(a[i]-x>=0&&(mark[a[i]-x+y]||mark[a[i]-x-y]))ans=a[i]-x;
        }
        //cout<<ans<<endl;

        if(ok&&ok2)cout<<0<<endl;
        else if(ok)cout<<1<<endl<<y<<endl;
        else if(ok2)cout<<1<<endl<<x<<endl;
        else if(ans!=-1)cout<<1<<endl<<ans;
        else cout<<2<<endl<<x<<' '<<y<<endl;
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
