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

const int N=1e6+10;
const int M=2e5+10;
vector<pair<ll,ll>> start[N],finish[N];
ll bit[3][M],a[M];
int n,m,k;

void upd(int t,int i,int v){
    for(;i<M;i+=i&(-i))bit[t][i]+=v;
}

ll get(int t,int i){
    ll kq=0;
    for(;i>0;i-=i&(-i))kq+=bit[t][i];

    return kq;
}

int bs(int x){
    int ans=0;
    for(int i=19;i>=0;--i){
        int ii=ans+(1<<i);
        if(ii<M){
            if(bit[1][ii]<x){
                x-=bit[1][ii];
                ans=ii;
            }
        }
    }

    return ans;
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

    cin>>n>>k>>m;
    for(int i=0;i<m;++i){
        int l,r,c,p;
        cin>>l>>r>>c>>p;
        start[l].pb({c,p});
        finish[r+1].pb({c,p});
        a[i]=p;
    }
    sort(a,a+m);

    ll ans=0;
    for(int i=1;i<=n;++i){
        for(auto &j:start[i]){
            j.se=lower_bound(a,a+m,j.se)-a;
            //cout<<j.fi<<' '<<j.se<<endl;
            upd(1,j.se+1,j.fi);
            upd(2,j.se+1,1LL*j.fi*a[j.se]);
        }
        for(auto &j:finish[i]){
            j.se=lower_bound(a,a+m,j.se)-a;
            //cout<<j.fi<<' '<<j.se<<endl;
            upd(1,j.se+1,-j.fi);
            upd(2,j.se+1,-1LL*j.fi*a[j.se]);
        }

        int tmp=bs(k);
        //cout<<tmp<<endl;
        ans+=get(2,tmp);
        if(tmp<m){
            ans+=(k-get(1,tmp))*a[tmp];
        }
    }
    cout<<ans;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
