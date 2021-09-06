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

const ll inf=1e18;
const int N=1e5+10;
int l[N],r[N];
int n,p;

int get(int x){
    return x/p;
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

    cin>>n>>p;
    for(int i=0;i<n;++i){
        cin>>l[i]>>r[i];
    }

    ld ans=0;
    for(int i=0;i<n;++i){
        ld big1=r[i]-l[i]+1,big2=r[(i+1)%n]-l[(i+1)%n]+1;
        ld tmp=get(r[i])-get(l[i]-1),tmp2=get(r[(i+1)%n])-get(l[(i+1)%n]-1);
        ld bad1=r[i]-l[i]-tmp+1,bad2=r[(i+1)%n]-l[(i+1)%n]-tmp2+1;
        //cout<<tmp<<' '<<tmp2<<' '<<bad1<<' '<<bad2<<endl;
        ans+=2000.*(1.-(1.*bad1/big1)*(1.*bad2/big2));
    }
    cout<<ans;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
