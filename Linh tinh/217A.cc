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

const int N=1e2+10;
int x[N],y[N],par[N];
int n;

int find(int u){
    return(par[u]<0?u:par[u]=find(par[u]));
}

bool join(int u,int v){
    if((u=find(u))==(v=find(v)))return 0;
    return par[u]=v,1;
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
    for(int i=0;i<n;++i)cin>>x[i]>>y[i],par[i]=-1;

    int ans=n;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(find(i)==find(j))continue;
            if(x[i]==x[j]||y[i]==y[j])join(i,j),--ans;
        }
    }
    cout<<ans-1;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
