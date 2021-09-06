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

const int N=1e3+10;
int a[N],suf[N],ans[N];
int n,m,d;

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

    cin>>n>>m>>d;
    for(int i=1;i<=m;++i)cin>>a[i];

    int pos=n;
    for(int i=m;i>0;--i){
        for(int j=0;j<a[i];++j)ans[pos-j]=i;
        pos-=a[i];
    }

    pos=0;
    while(pos+d<=n){
        while(pos+1<=n&&ans[pos+1])++pos;
        if(pos+d>n)break;
        if(ans[pos+d]==0){
            int l=-1;
            for(int i=pos+d;i<=n+1;++i){
                if(ans[i]!=0){
                    l=i;
                    break;
                }
            }
            if(l==-1){cout<<"NO";return 0;}

            int r=-1;
            for(int i=l;i<=n+1;++i){
                if(ans[i]==ans[l])r=i;
            }
            while(ans[pos+d]==0){
                swap(ans[l-1],ans[r]);
                --l,--r;
            }
        }
        pos+=d;
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n;++i)cout<<ans[i]<<' ';

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
