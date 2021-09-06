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
int a[N];
int n,k,sum=0;

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

    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i],sum+=a[i];

    vector<pii> ans;
    int med=(sum+n-1)/n,cur=-1,idx=-1;
    while(1){
        if(cur<=med){
            for(int j=0;j<n;++j)if(a[j]>med){cur=a[j];idx=j;break;}
        }
        if(cur<=med)break;

        int mn=1e9,id=-1;
        bool ok=0;
        //cout<<cur<<' '<<idx<<endl;
        for(int j=0;j<n;++j){
            if(cur<=med)break;
            if(a[j]<med&&a[j]<mn){
                id=j;
                mn=a[j];
            }
        }
        //cout<<mn<<endl;
        if(mn==1e9)break;
        a[id]++;
        ans.pb({idx,id});
        --cur,--k;
         a[idx]=cur;
        if(k==0)break;
    }

    cout<<*max_element(a,a+n)-*min_element(a,a+n)<<' '<<ans.size()<<endl;
    for(auto i:ans)cout<<i.fi+1<<' '<<i.se+1<<endl;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
